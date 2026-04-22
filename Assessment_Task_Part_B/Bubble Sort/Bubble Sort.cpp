#include <iostream>
#include <cassert>

using namespace std;

void Swap(int& a, int& b);

// Uses 'In-Place' Bubble Sort To Sort An Array Of Integers.
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

int main()
{
	// Initialize Array Of Numbers To Be Sorted.
	int array_to_be_sorted[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };

	// Calculate The Length Of The Array Of Numbers To Be Sorted.
	int array_to_be_sorted_length = sizeof(array_to_be_sorted) / sizeof(array_to_be_sorted[0]);

	// Bubble Sort The Array.
	Bubble_Sort(array_to_be_sorted, array_to_be_sorted_length);

	// Loop Through The Sorted Array In Pairs.
	for (int index_of_number_to_check = 0; index_of_number_to_check < array_to_be_sorted_length - 1; ++index_of_number_to_check)
	{
		// Assert That The First Number In The Pair Is Less Then The Second Number In The Pair.
		// This Is To Confirm That The "Bubble Sort" Function Sorted The Array In Ascending Order Correctly.
		assert(array_to_be_sorted[index_of_number_to_check] < array_to_be_sorted[index_of_number_to_check + 1]);
	}
}