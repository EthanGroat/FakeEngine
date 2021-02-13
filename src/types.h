#pragma once

// #include "ExternalLibraries.h"


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
/* using some things I coded in c */

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
    if (lst->items != NULL)
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
            // free(lst->items);
            lst->items = new_item_set;
            if (lst->items == NULL)
                exit(EXIT_FAILURE);
            memset(  /* zerofill new space */
                (char*)lst->items + lst->max * lst->itemsize / 2,
                0,
                lst->itemsize * lst->max / 2
            );
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


// C++-only style stuff
namespace FakeEngine
{
    template<typename StorageType>
    class FakeList  // C++ wrapper class for my C list structure
    {
        public:
        private:
            fakelist* the_list;
        public:
            // a resizable list structure of any type
            // (type must be specified in angle brackets when created)
            FakeList()
            {
                the_list = fakelist_new(sizeof(StorageType));
            }
            ~FakeList()
            {
                if (the_list->items != NULL)
                    free(the_list->items);
                free(the_list);
            }

            // initialize the FakeList with an array
            void initialize(StorageType* initializer_array, int length)
            {
                for (int i = 0; i < length; ++i)
                    fakelist_append(the_list, initializer_array+i);
            }
            void insert_at(int index, StorageType item)
            {
                fakelist_insert_at(the_list, index, &item);
            }
            StorageType get(int index)
            {
                return *(StorageType*)fakelist_get(the_list, index);
            }
            StorageType* get_ptr(int index)
            {
                return (StorageType*)fakelist_get(the_list, index);
            }
            void rm(int index)
            {
                fakelist_rm(the_list, index);
            }
            ///@brief does not resize the buffer, only clears the entries
            void clear()
            {
                memset((char*)the_list->items, 0, the_list->itemsize * the_list->count); /* zerofill */
                the_list->count = 0;
            }
            StorageType extract(int index)
            {
                StorageType temp = get(index);
                rm(index);
                return temp;
            }
            void append(StorageType item)
            {
                fakelist_append(the_list, &item);
            }
            void enq(StorageType item)  // enqueue
            {
                append(item);
            }
            StorageType deq()  // dequeue
            {
                return extract(0);
            }
            void push(StorageType item)
            {
                append(item);
            }
            StorageType pop()
            {
                return extract(-1);
            }

            int length()
            {
                return the_list->count;
            }
            int internal_buffer_length()
            {
                return the_list->max;
            }
            size_t internal_buffer_size()
            {
                return the_list->max * sizeof(StorageType);
            }

            StorageType* get_internal_array()
            {
                return (StorageType*)(the_list->items);
            }

            // Operators
            FakeList operator[](int index)
            {
                return get(index);
            }
    };
}






