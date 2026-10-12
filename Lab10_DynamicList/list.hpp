#ifndef LIST_HPP
#define LIST_HPP

// prints the values in array "colPtr" of "size"
void output(double *colPtr, int size);

// returns the index of "number" in the array, or -1 if it is not there
int check(double *colPtr, double number, int size);

// adds "number" to the array unless it is already there; the array grows
void addNumber(double *&colPtr, double number, int &size);

// removes "number" from the array if it is there; the array shrinks
void removeNumber(double *&colPtr, double number, int &size);

#endif
