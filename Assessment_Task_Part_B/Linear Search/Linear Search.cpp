#include <iostream>
#include <cassert>

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

int main()
{
	// Initialize Array Of Numbers.
	int array_of_numbers[] = { 67,13,3,89,43,2,19,71,5,61,97,7,37,31,17,11,83,53,23,29 };

	// Calculate The Length Of The Array Of Numbers.
	int array_of_numbers_length = sizeof(array_of_numbers) / sizeof(array_of_numbers[0]);

	// Various Asserts To Verify The Linear_Search Function Works Correctly.
	assert(Linear_Search(3, array_of_numbers, array_of_numbers_length) == 2);
	assert(Linear_Search(7, array_of_numbers, array_of_numbers_length) == 11);
	assert(Linear_Search(67, array_of_numbers, array_of_numbers_length) == 0);
	assert(Linear_Search(88, array_of_numbers, array_of_numbers_length) == -1);
}