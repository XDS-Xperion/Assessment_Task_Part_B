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

	// Keeps Track Of The Users Input For Breaking Out Of And Continuing The Loop.
	string user_input = "";

	// Keeps Track Of The Users Input For The Value To Find.
	int value_to_find = -1;

	// Used To Store The Index Of The Value To Find.
	int value_to_find_index = -1;

	// Keep Looping Until The User Enters "n".
	while (user_input != "n")
	{
		// Output The Array Of Numbers To The Console.
		cout << "67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29";

		// Output A Prompt For User Input To The Console.
		cout << "\n\nPlease Enter One Of The Values From Above: ";

		// Get The Value To Find Via User Input In The Console.
		cin >> value_to_find;

		// Use Linear_Search To Get The Index Of The Value To Find.
		value_to_find_index = Linear_Search(value_to_find, array_of_numbers, array_of_numbers_length);

		if (value_to_find_index != -1) // Index Is Valid, Value Was Found In The Array.
		{
			// Output The Value Found Message To The Console.
			cout << "\nThe Value " << value_to_find << " Was Found At Index " << value_to_find_index << " Of The Array.";
		}
		else // Index Is Not Valid, Value Was Not Found In The Array.
		{
			// Output The Value Not Found Message To The Console.
			cout << "\nThe Value " << value_to_find << " Was Not Found In The Array.";
		}

		// Output A Prompt For User Input To The Console.
		cout << "\n\nWould You Like To Try Another Value? (y / n): ";

		// Get The Users Option To Try Another Value Or Not Via User Input In The Console.
		cin >> user_input;

		// Output A Newline To The Console.
		cout << "\n";
	}
}