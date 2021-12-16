#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[6];
    int count;
    char vals[27][6];
} map_key;

typedef struct
{
    int count;
    map_key keys[27];
} map;

typedef struct
{
    int count;
    char values[100][6];
} set;

int map_contains_key(map m, char *key)
{
    for (int i = 0; i < m.count; i++)
    {
        if (!strcmp(m.keys[i].name, key))
            return i;
    }
    return -1;
}

void map_add(map *m, char *key, char *val)
{
    int id;
    if ((id = map_contains_key(*m, key)) >= 0)
    {
        strcpy(m->keys[id].vals[m->keys[id].count++], val);
    }
    else
    {
        id = m->count++;
        m->keys[id].count = 1;
        strcpy(m->keys[id].name, key);
        strcpy(m->keys[id].vals[0], val);
    }
}

int set_contains(set s, char *val)
{
    for (int i = 0; i < s.count; i++)
    {
        if (!strcmp(s.values[i], val))
            return 1;
    }
    return 0;
}

set set_copy(set s)
{
    set new;
    for (int i = 0; i < s.count; i++)
    {
        strcpy(new.values[i], s.values[i]);
    }
    new.count = s.count;
    return new;
}

void set_clear(set *s)
{
    s->count = 0;
}

void set_add(set *s, char *val)
{
    if (!set_contains(*s, val))
        strcpy(s->values[s->count++], val);
}

void traverse_map(map m, set *s, char *node, char *path, int *ended)
{
    char *path_to = (char *)malloc(sizeof(char) * (strlen(path) + strlen(node) + 4));
    strcpy(path_to, path);
    strcat(path_to, node);

    if (!strcmp(node, "end"))
    {
        //printf("%s\n", path_to);
        if (s->count > 0)
            (*ended)++;
    }
    else
    {
        strcat(path_to, ",");
        int id = map_contains_key(m, node);
        for (int i = 0; i < m.keys[id].count; i++)
        {
            set node_set = set_copy(*s);
            char *next_node = m.keys[id].vals[i];
            if (set_contains(node_set, next_node))
                continue;
            if (islower(next_node[0]))
                set_add(&node_set, next_node);
            traverse_map(m, &node_set, next_node, path_to, ended);
        }
    }
    free(path_to);
}

int main(void)
{
    map cave;
    cave.count = 0;
    while (!feof(stdin))
    {
        char str[13];
        char *k, *v;
        scanf("%s\r\n", str);
        // in some cases the end of the second cave would get chopped off
        // weird solution to fix that
        v = strchr(str, '-');
        v++;
        k = strtok(str, "-");
        map_add(&cave, k, v);
        map_add(&cave, v, k);
    }

    int ended = 0;
    set small_caves;
    set_clear(&small_caves);
    set_add(&small_caves, "start");

    traverse_map(cave, &small_caves, "start", "", &ended);
    printf("%d\n", ended);

    return 0;
}