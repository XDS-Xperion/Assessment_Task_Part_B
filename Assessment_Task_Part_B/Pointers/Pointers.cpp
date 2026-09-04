#include <iostream>
#include <cassert>

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

int main() 
{
	// Initialize a To 290.
	int a = 290;

	// Initialize b To 197.
	int b = 197;

	// Swap The Values Of a And b.
	Swap_Numbers(&a, &b);

	// Assert That The Values Have Been Swapped.
	assert(a == 197);
	assert(b == 290);

	int c = 80;
	int d = 69;

	Swap_Numbers(&c, &d);

	assert(c == 69);
	assert(d == 80);
}