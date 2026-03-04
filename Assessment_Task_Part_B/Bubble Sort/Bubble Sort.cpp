#include <iostream>

void Swap(int& a, int& b);

// Uses Bubble Sort To Sort An Array Of Integers.
void Bubble_Sort(int array_to_be_sorted[], int array_to_be_sorted_length)
{
	// Exit Out Of The Function Early If The Array Length Is Less Than 2.
	// This Means The Array Has A Single Element Or Has An Invalid Length.
	if (array_to_be_sorted_length < 2)
	{
		return;
	}

	// Flag Used To Continue The Loop Until It Is True.
	bool array_sorted = false;

	// Loop Until The array_sorted Flag Is True.
	while (!array_sorted)
	{
		// Set The Flag To True.
		array_sorted = true;

		// For Loop Used To Compare Pairs Of Numbers. For Example Element I And Element I + 1.
		for (int index_of_number_to_sort = 0; index_of_number_to_sort < array_to_be_sorted_length - 1; ++index_of_number_to_sort)
		{
			// Check The Pairs.
			if (array_to_be_sorted[index_of_number_to_sort] > array_to_be_sorted[index_of_number_to_sort + 1])
			{
				// Swap The Pairs As They Are Out Of Order.
				Swap(array_to_be_sorted[index_of_number_to_sort], array_to_be_sorted[index_of_number_to_sort + 1]);

				// Set The Flag To False, As A Pair Was Just Swapped.
				array_sorted = false;
			}
		}
	}
}

// Swaps The Values Of A And B.
void Swap(int& a, int& b)
{
	int temp = a; // Store The Value Of A In A Temp Variable.
	a = b; // Assign The Value Of B To A.
	b = temp; // Assign The Cached Value Of A To B.
}