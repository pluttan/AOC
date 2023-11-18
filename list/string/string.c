#include "../../mem/al.h"

#ifndef NULL
#define NULL (void *)0
#endif

struct String
{
    char this;
    struct String *next;
    struct String *prev;
};

struct String *sInit()
{
    int size = sizeof(struct String);

    struct String *head = (struct String *)malloc(size);
    (*head).next = NULL;
    (*head).prev = NULL;
    (*head).this = '\0';

    return head;
}

void sdInit(struct String *head)
{
    struct String *this = head;
    while (this != NULL)
    {
        struct String *temp = this;
        this = this->next;
        free(temp);
    }
}

int main()
{
    struct String *head = sInit();
    sdInit(head);
    return 0;
}
