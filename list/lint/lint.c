#include "../../io/out.h"
#include "../../mem/al.h"
#include "../../math/math.h"
#include "../string/string.h"

struct Lint
{
    int this;
    struct Lint *next;
    struct Lint *prev;
};

typedef struct Lint *lint;

lint liInit()
{
    int size = sizeof(struct Lint);
    lint head = NULL;

    while (head == NULL || head == (void *)-1)
    {
        head = (lint)malloc(size);
    }

    (*head).next = NULL;
    (*head).prev = NULL;
    (*head).this = 0;

    return head;
}

lint liadd(lint tail, int elem)
{
    if ((*tail).this == 0)
    {
        (*tail).this = elem;
    }
    else
    {
        lint this = (lint)malloc(sizeof(struct Lint));
        if ((*tail).next != NULL)
        {
            (*this).next = (*tail).next;
        };
        (*tail).next = this;
        (*this).prev = tail;
        (*this).this = elem;
        tail = this;
    }
    return tail;
}

lint liaddH(lint head, int elem)
{
    if ((*head).this == 0)
    {
        (*head).this = elem;
    }
    else
    {
        lint this = (lint)malloc(sizeof(struct Lint));
        (*this).prev = NULL;
        (*this).this = elem;
        (*this).next = head;
        (*head).prev = this;
        head = this;
    }

    return head;
}

lint litoTail(lint head)
{
    lint this = head;
    lint temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->next;
    }
    return temp;
}

lint litoHead(lint tail)
{
    lint this = tail;
    lint temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->prev;
    }
    return temp;
}

void lidi(lint head)
{
    lint this = litoHead(head);
    while (this != NULL)
    {
        lint temp = this;
        this = this->next;
        free(temp);
    }
}

void liprintp(lint head, str sep)
{
    lint this = head;
    lint temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->next;
        iprint((*temp).this);
        if (this != NULL)
            sprint(sep);
        else
            print("\n");
    }
    sdi(sep);
}

void liprintpd(lint head, str sep)
{
    liprintp(head, sep);
    lidi(head);
}

void liprint(lint head)
{
    liprintp(head, sida(", "));
}

void liprintd(lint head)
{
    liprint(head);
    lidi(head);
}

void liada(int *in, lint tail, const unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        tail = liadd(tail, *(in + i));
    }
}

lint liida(int *in, const unsigned int length)
{
    lint head = liInit();
    liada(in, litoTail(head), length);
    return head;
}

lint lii(lint head, int index)
{
    lint current = head;
    int currentIndex = 0;

    while (current != NULL)
    {
        if (currentIndex == index)
        {
            return current;
        }
        current = current->next;
        currentIndex++;
    }
    return NULL;
}

lint liiH(lint tail, int index)
{
    lint current = tail;
    int currentIndex = 0;

    while (current != NULL)
    {
        if (currentIndex == index)
        {
            return current;
        }
        current = current->prev;
        currentIndex++;
    }
    return NULL;
}
