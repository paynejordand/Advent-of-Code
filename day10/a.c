#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack stack;

struct stack
{
    stack *prev;
    char c;
};

void push(stack **s, char c)
{
    stack *temp = (stack *)(malloc(sizeof(stack)));
    temp->prev = *s;
    temp->c = c;
    *s = temp;
}

char pop(stack **s)
{
    char c = (*s)->c;
    stack *temp = *s;
    *s = (*s)->prev;
    free(temp);

    return c;
}

void freeStack(stack **s)
{
    while ((*s)->prev != NULL)
    {
        stack *temp = *s;
        *s = (*s)->prev;
        free(temp);
    }
    free(*s);
}

void printStack(stack *s)
{
    while (s->prev != NULL)
    {
        printf("%c ", s->c);
        s = s->prev;
    }
    printf("\n");
}

int assignPoints(char c)
{
    if (c == ')')
        return 3;
    else if (c == ']')
        return 57;
    else if (c == '}')
        return 1197;
    else if (c == '>')
        return 25137;
    else
        return 0;
}

int isOpen(char c)
{
    return (c == '(' || c == '[' || c == '{' || c == '<');
}

int closeMatches(stack *s, char c)
{
    return (
        (s->c == '(' && c == ')') ||
        (s->c == '[' && c == ']') ||
        (s->c == '{' && c == '}') ||
        (s->c == '<' && c == '>'));
}

int main(void)
{
    int points = 0;
    while (!feof(stdin))
    {
        char c;
        stack *chunk = (stack *)(malloc(sizeof(stack)));
        chunk->prev = NULL;
        while (1)
        {
            scanf("%c", &c);

            if (c == '\n')
            {
                while ((c = fgetc(stdin)) != '\n' && c != EOF);
                break;
            }

            if (isOpen(c))
            {
                push(&chunk, c);
            }
            else if (closeMatches(chunk, c))
            {
                pop(&chunk);
            }
            else
            {
                points += assignPoints(c);
                while ((c = fgetc(stdin)) != '\n' && c != EOF);
                break;
            }
        }
        freeStack(&chunk);
    }

    printf("\n%d\n", points);
    return 0;
}