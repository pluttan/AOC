#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#define maxLength 1000

// Structure representing a character in a string
struct String
{
    char this;
    struct String *next;
    struct String *prev;
};

// Pointer type for the string structure
typedef struct String *str;

// Function to initialize an empty string
str sInit();

// Function to add a character to the end of the string
str sadd(str tail, char elem);

// Function to add a character to the beginning of the string
str saddH(str head, char elem);

// Function to retrieve a pointer to the end of the string
str stoTail(str head);

// Function to retrieve a pointer to the beginning of the string
str stoHead(str tail);

// Function to deallocate memory for the entire string
void sdi(str head);

// Function to print the characters in the string to the standard output
void sprint(str head);

// Function to add a null-terminated string to the string
void sada(char *in, str tail);

// Function to create a string from a null-terminated string
str sida(char *in);

// Function to convert an integer to a string
str sint(long long number);

// Function to convert a floating-point number to a string
// with a specified number of digits after the decimal point
str sfloatR(long double fnumber, int afterPoint);

// Function to convert a floating-point number to a string
// with a default precision of 14 digits after the decimal point
str sfloat(long double fnumber);

// Function to print integer
void iprint(long long i);

// Function to print float
void fprint(long double i);

// Function to print string and delete
void sprintd(str head);

// Function to print float with number of digits
void fprintR(long double i, int r);

#endif /* STRING_UTILS_H */
