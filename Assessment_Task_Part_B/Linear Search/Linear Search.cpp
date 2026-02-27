#include <iostream>

using namespace std;

// Loops Through An Array Of Numbers To Find The Target Value.
// If The Target Value Is Found Return It's Index.
// If The Target Value Is Not Found Return -1.
int Linear_Search(int target_value, int array_of_numbers[], int array_of_numbers_length)
{
	// Loop Through The Array Of Numbers.
	for (int current_index = 0; current_index < array_of_numbers_length; current_index++)
	{
		// Check To See If The Current Number In The Array Is Equal To The Target Value.
		if (array_of_numbers[current_index] == target_value)
		{
			// Return The Index Of The Current Number In The Array.
			return current_index;
		}
	}

	// Target Value Not Found, Return -1.
	return -1;
}