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

int Binary_Search(int target_value, int array_of_sorted_numbers[], int array_of_sorted_numbers_length)
{
	// Keeps Track Of The Start Index.
	int left = 0;

	// Keeps Track Of The End Index.
	int right = array_of_sorted_numbers_length - 1;

	while (left <= right)
	{
		// Calculate The Middle Index.
		int middle = (left + right) / 2;

		// Check To See If The Target Value Is At The Middle Index.
		if (array_of_sorted_numbers[middle] == target_value)
		{
			// Target Value Found.
			// Return The Index Of The Target Value.
			return middle;
		}

		// Check To See If The Value Of The Middle Index Is Less Then The Target Value.
		if (array_of_sorted_numbers[middle] < target_value)
		{
			// Ignore Left Half.
			left = middle + 1;
		}

		// Check To See If The Value Of The Middle Index Is Greater Then The Target Value.
		if (array_of_sorted_numbers[middle] > target_value)
		{
			// Ignore Right Half.
			right = middle - 1;
		}
	}

	// Target Value Not Found.
	return -1;
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

	assert(Binary_Search(11, array_to_be_sorted, array_to_be_sorted_length) == 4);
	assert(Binary_Search(23, array_to_be_sorted, array_to_be_sorted_length) == 8);
	assert(Binary_Search(97, array_to_be_sorted, array_to_be_sorted_length) == 19);
	assert(Binary_Search(88, array_to_be_sorted, array_to_be_sorted_length) == -1);

	// Keeps Track Of The Users Input.
	int user_input = 0;

	// Loop Until The Users Input Is -1
	while (user_input != -1)
	{
		// Output The Sorted Array Of Numbers To The Console.
		cout << "2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 53, 61, 67, 71, 83, 89, 97";

		// Prompt The User For Their Input.
		cout << "\n\nPlease Enter A Value To Search For Or Enter -1 To End: ";

		// Gather The Users Input.
		cin >> user_input;

		// Check To See If The User Wants To End The Program.
		if (user_input != -1)
		{
			// Use Binary Search To Search For The Users Input.
			int result = Binary_Search(user_input, array_to_be_sorted, array_to_be_sorted_length);

			if (result == -1) // Value Not Found In The Array.
			{
				// Output The Value Not Found Message To The Console.
				cout << "\nThe Number \"" << user_input << "\" Was Not Found In The Array.";
			}
			else // Value Found In The Array.
			{
				// Output The Value Found Message To The Console.
				cout << "\nThe Number \"" << user_input << "\" Was Found In The Array At Index " << result <<".";
			}

			cout << "\n\n";
		}
	}
}