#ifndef __LINTH__
#define __LINTH__

#include "../string/string.h"

// Structure to represent an element in a doubly-linked list
struct Lint
{
    int this;          // Value of the current element
    struct Lint *next; // Pointer to the next element in the list
    struct Lint *prev; // Pointer to the previous element in the list
};

// Definition of a pointer type to the Lint structure
typedef struct Lint *lint;

// Initializes an empty list
lint liInit();

// Adds an element to the end of the list
lint liadd(lint tail, int elem);

// Adds an element to the beginning of the list
lint liaddH(lint head, int elem);

// Gets a pointer to the last element in the list
lint litoTail(lint head);

// Gets a pointer to the first element in the list
lint litoHead(lint tail);

// Frees the memory occupied by the list
void lidi(lint head);

// Prints the list with a specified separator
void liprintp(lint head, str sep);

// Prints the list with a specified separator and frees the memory
void liprintpd(lint head, str sep);

// Prints the list with a default separator
void liprint(lint head);

// Prints the list with a default separator and frees the memory
void liprintd(lint head);

// Adds an array of integers to the end of the list
void liada(int *in, lint tail, const unsigned int length);

// Initializes a list with an array of integers
lint liida(int *in, const unsigned int length);

// Function to find an element by index in the list, starting from the head
// Returns a pointer to the found element or NULL if the element is not found
lint lii(lint head, int index);

// Function to find an element by index in the list, starting from the tail
// Returns a pointer to the found element or NULL if the element is not found
lint liiH(lint tail, int index);

#endif // __LINTH__
