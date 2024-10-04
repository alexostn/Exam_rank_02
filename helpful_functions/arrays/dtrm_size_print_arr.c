#include <stdio.h>

int main()
{
	int tab[] = {7, 3, 5, 2};
	int i = 0;

	// Determining the size of the array
	int size = sizeof(tab) / sizeof(tab[0]);

	// Printing the array elements
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return 0;
}
// it will also work with mixed data types
// #include <stdio.h>

// struct MyStruct {
// 	int a;
// 	float b;
// 	char c;
// };

// int main()
// {
// 	// Array of structures with different data types
// 	struct MyStruct arr[] = {
// 		{1, 2.5, 'a'},
// 		{2, 3.5, 'b'},
// 		{3, 4.5, 'c'}
// 	};

// 	// Determining the length of the array
// 	int size = sizeof(arr) / sizeof(arr[0]);

// 	// Printing the elements of the array
// 	for (int i = 0; i < size; i++) {
// 		printf("Element %d: a = %d, b = %.1f, c = %c\n", i, arr[i].a, arr[i].b, arr[i].c);
// 	}

// 	return 0;
// }

