#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

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
    if (c == '(')
        return 1;
    else if (c == '[')
        return 2;
    else if (c == '{')
        return 3;
    else if (c == '<')
        return 4;
    else
        return 0;
}

int isOpen(char c)
{
    return (
        c == '(' ||
        c == '[' ||
        c == '{' ||
        c == '<');
}

int closeMatches(stack *s, char c)
{
    return (
        (s->c == '(' && c == ')') ||
        (s->c == '[' && c == ']') ||
        (s->c == '{' && c == '}') ||
        (s->c == '<' && c == '>'));
}

int uintcmp(const void *a, const void *b)
{
    uint64_t ai = *(uint64_t *)a;
    uint64_t bi = *(uint64_t *)b;

    if (ai < bi)
        return -1;
    else
        return 1;
}

int main(void)
{
    int count = 0;
    uint64_t arr[47];
    while (!feof(stdin))
    {
        stack *chunk = (stack *)(malloc(sizeof(stack)));
        chunk->prev = NULL;
        while (1)
        {
            char c;
            scanf("%c", &c);
            
            if (c == '\r' || feof(stdin))
            {
                uint64_t points = 0;
                while (chunk->prev != NULL)
                {
                    points = (points * 5) + assignPoints(pop(&chunk));
                }
                arr[count++] = points;

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
                while ((c = fgetc(stdin)) != '\n' && c != EOF);
                break;
            }
        }
        freeStack(&chunk);
    }
    qsort(arr, count, sizeof(uint64_t), uintcmp);
    printf("%lu\n", arr[count / 2]);
    return 0;
}