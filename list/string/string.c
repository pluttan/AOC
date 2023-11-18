#include "../../io/out.h"
#include "../../mem/al.h"
#include "../../math/math.h"
#include "string.h"

str sInit()
{
    int size = sizeof(struct String);
    str head = NULL;

    while (head == NULL || head == (void *)-1)
    {
        head = (str)malloc(size);
    }

    (*head).next = NULL;
    (*head).prev = NULL;
    (*head).this = 0;

    return head;
}

str sadd(str tail, char elem)
{
    if ((*tail).this == 0)
    {
        (*tail).this = elem;
    }
    else
    {
        str this = (str)malloc(sizeof(struct String));
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

str saddH(str head, char elem)
{
    if ((*head).this == 0)
    {
        (*head).this = elem;
    }
    else
    {
        str this = (str)malloc(sizeof(struct String));
        (*this).prev = NULL;
        (*this).this = elem;
        (*this).next = head;
        (*head).prev = this;
        head = this;
    }

    return head;
}

str stoTail(str head)
{
    str this = head;
    str temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->next;
    }
    return temp;
}

str stoHead(str tail)
{
    str this = tail;
    str temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->prev;
    }
    return temp;
}

void sdi(str head)
{
    str this = stoHead(head);
    while (this != NULL)
    {
        str temp = this;
        this = this->next;
        free(temp);
    }
}

void sprint(str head)
{
    str this = head;
    str temp = this;
    while (this != NULL)
    {
        temp = this;
        this = this->next;
        print(&(*temp).this);
    }
}

void sprintd(str head)
{
    sprint(head);
    sdi(head);
}

void sada(char *in, str tail)
{
    unsigned long i = 0;
    while (*in != '\0' && i < maxLength)
    {
        i++;
        tail = sadd(tail, *in);
        in++;
    }
}

str sida(char *in)
{
    str head = sInit();
    sada(in, stoTail(head));
    return head;
}

str sint(long long number)
{
    long long isNegative = 0;
    str st = sInit();

    if (number < 0)
    {
        isNegative++;
        number = -number;
    }

    while (number != 0)
    {
        st = saddH(st, '0' + number % 10);
        number /= 10;
    };

    if (isNegative)
    {
        st = saddH(st, '-');
    }

    return st;
}

str sfloatR(double fnumber, int afterPoint)
{
    if (afterPoint > 14)
        return sida("afterPoint is bigger then 14");
    int isNegative = 0;
    str st = sInit();

    if (fnumber < 0)
    {
        isNegative++;
        fnumber = -fnumber;
    }

    unsigned long long number = fnumber * pow(10, afterPoint);

    int zeroTrack = 0;
    int nowNumber = 0;

    while (nowNumber == 0)
    {
        nowNumber = number % 10;
        number /= 10;
        afterPoint--;
    };

    while (number != 0)
    {
        afterPoint--;
        if (!(afterPoint + 2))
            st = saddH(st, '.');
        st = saddH(st, '0' + nowNumber);
        nowNumber = number % 10;
        number /= 10;
    };
    st = saddH(st, '0' + nowNumber);

    if (isNegative)
    {
        st = saddH(st, '-');
    }

    return st;
}

str sfloat(double fnumber)
{
    return sfloatR(fnumber, 3);
}

void iprint(long long i)
{
    sprintd(sint(i));
}

void fprint(double i)
{
    sprintd(sfloat(i));
}