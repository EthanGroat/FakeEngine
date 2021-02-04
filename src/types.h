#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


/**** Vectors ****/

typedef struct
{
    float x;
    float y;
} vector_2d;

typedef struct
{
    float x;
    float y;
    float z;
} vector_3d;

typedef struct
{
    float x;
    float y;
    float z;
    float q;
} vector_4d;


/**** Lists ****/

typedef struct fakelist fakelist;
struct fakelist
{
    int count;
    int max;
    size_t itemsize;
    void* items;
};


fakelist* fakelist_new(size_t size);
void fakelist_free(fakelist* lst);
void fakelist_resize(fakelist* lst);
void* fakelist_append(fakelist* lst, void* item);
void fakelist_rm(fakelist* lst, int index);
void* fakelist_insert_at(fakelist* lst, int index, void* item);
void* fakelist_get(fakelist* lst, int index);

fakelist* fakelist_new(size_t size)
{
    fakelist* lst = (fakelist*)calloc(1, sizeof(fakelist));
    lst->itemsize = size;
    lst->count = 0;
    lst->max = 0;
    lst->items = NULL;
    return lst;
}

void fakelist_free(fakelist* lst)
{
    if (lst->count > 0)
        free(lst->items);
    free(lst);
}
void fakelist_resize(fakelist* lst)
{
    if (lst->items == NULL || lst->max == 0)
    {
        lst->max = 2;
        lst->items = calloc(lst->max, lst->itemsize);
    }
    else if (lst->count < lst->max/2)
    {
        lst->max /= 2;
        size_t newsize = lst->itemsize * lst->max;
        void* new_item_set = realloc(lst->items, newsize);
        lst->items = new_item_set;
    }
    else
    {
        while (lst->count >= lst->max)
        {
            lst->max *= 2;
            size_t newsize = lst->itemsize * lst->max;
            void* new_item_set = realloc(lst->items, newsize);
            if (new_item_set == NULL)
                exit(EXIT_FAILURE);
            memset(  /* zerofill new space */
                (char*)new_item_set + lst->max / 2,
                0,
                lst->itemsize * lst->max / 2
            );
            lst->items = new_item_set;
        }
    }
}
void* fakelist_append(fakelist* lst, void* item)
{
    char *pos;

    fakelist_resize(lst);

    pos = (char*)lst->items + (lst->count * lst->itemsize);
    memcpy(pos, item, lst->itemsize);

    lst->count++;
    return pos;
}
void fakelist_rm(fakelist* lst, int index)
{
    if (index < 0)
        index = lst->count + index;
    if (lst->count <= 0 || index > lst->count - 1)
        return;

    char* pos;
    char* end;

    fakelist_resize(lst);

    pos = (char*)lst->items + index * lst->itemsize;
    end = (char*)lst->items + (lst->count - 1) * lst->itemsize;
    while (pos < end)
    {
        /* comparison is an optimization: avoids overwriting duplicates */
        if (memcmp(pos, pos + lst->itemsize, lst->itemsize) != 0)
        {
            memcpy(pos, pos + lst->itemsize, lst->itemsize);
        }
        pos += lst->itemsize;
    }
    lst->count--;
}
void* fakelist_insert_at(fakelist* lst, int index, void* item)
{
    char* pos;
    char* index_pos;

    if (index > lst->count)
        lst->count = index;  /* allow for zerofilling */
    else if (index < 0)
        index = lst->count + index;  /* negative indices like python lists */

    fakelist_resize(lst);
    
    pos = (char*)lst->items + (lst->count - 1) * lst->itemsize;
    index_pos = (char*)lst->items + index * lst->itemsize;
    while (pos >= index_pos)
    {
        if (memcmp(pos + lst->itemsize, pos, lst->itemsize) != 0)
        {
            memcpy(pos + lst->itemsize, pos, lst->itemsize);
        }
        pos -= lst->itemsize;
    }

    pos = (char*)lst->items + index * lst->itemsize;
    memcpy(pos, item, lst->itemsize);
    lst->count++;
    return pos;
}
void* fakelist_get(fakelist* lst, int index)
{
    if (index < 0)
        index = lst->count + index;
    if (lst->count <= 0 || index > lst->count - 1)
        return NULL;
    else return (char*)lst->items + index * lst->itemsize;
}










