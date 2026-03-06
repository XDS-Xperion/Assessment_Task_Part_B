#include <iostream>

// A Function That Takes The Pointers Of 2 Numbers And Swaps The Values They Point To.
void Swap_Numbers(int* a, int* b)
{
	// Store The Value That a Points To In A Temp Variable.
	int temp = *a;

	// Set The Value That a Points To The Value b Points To.
	*a = *b;

	// Set The Value That b Points To The Value of temp.
	*b = temp;
}