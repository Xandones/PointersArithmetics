#include <iostream>
#include <iomanip>

using namespace std;

void LineTracer(void);
void VectorPrinter(int Array[], int* p);


int main()
{
	int Vector[] = { 1, 23, -78, 900, 234 }; // An int in C++ has a size of 4 bytes

	int* ptr;
	ptr = Vector; // This is where the pointer is set to point to the address of the first element of the vector.
	// Using the name of the vector is the same as using &VectorName[0].
	cout << "******* POINTERS ARITHMETIC *******\n\n";
	cout << "Original vector:\n";
	VectorPrinter(Vector, ptr);
	LineTracer();

	cout << "\nOriginal value stored in ptr : " << ptr << " (address of the first array's element)" << "\n";

	LineTracer();
	cout << "\nUsing a pointer without modifing it:\n\n";
	cout << "(ptr + 0) RESULTING ADDRESS: " << ptr << " Value: " << *ptr << "\n"; // The original address of the pointer will be displayed.
	cout << "(ptr + 1) RESULTING ADDRESS: " << (ptr + 1) << " Value: " << *(ptr + 1) << "\n"; // 4 bytes ahead (4 X 1) 
	cout << "(ptr + 2) RESULTING ADDRESS: " << (ptr + 2) << " Value: " << *(ptr + 2) << "\n"; // 8 bytes ahead (4 X 2)
	cout << "(ptr + 3) RESULTING ADDRESS: " << (ptr + 3) << " Value: " << *(ptr + 3) << "\n"; // 12 bytes ahead (4 x 3)
	cout << "(ptr + 4) RESULTING ADDRESS: " << (ptr + 4) << " Value: " << *(ptr + 4) << "\n"; // 16 bytes ahead (4 X 4)

	LineTracer();
	cout << "\nValue stored in ptr: " << ptr << "\n";

	LineTracer();
	ptr++; // Adds 1 unity (4 bytes in this case) to the pointer.
	cout << "\nValue stored in ptr after increasing its value in one unit: " << ptr << "\n";

	LineTracer();
	ptr = &Vector[3]; // This is the way to directly choose a position of the array to point to.
	cout << "\nValue stored in ptr after changing it directly to the 4th element of the array: " << ptr << "\n";

	LineTracer();
	ptr--; //  Subtracts 1 unity (4 bytes in this case) to the pointer.
	cout << "\nValue stored in ptr after subtracting 1 unit of it: " << ptr << "\n";

	LineTracer();
	ptr = Vector; // Resets vetor to the first position (0).
	cout << "\nContents of each array element:\n";
	VectorPrinter(Vector, ptr);

	int** ptr2 = &ptr; // Pointer that points to another pointer.
	LineTracer();
	cout << "\nMemory address for ptr2 (a pointer for ptr's address): " << &ptr2 << "\n\n";
	cout << "Value stored in ptr2 (the address of ptr - the first element of the array):" << *ptr2 << "\n\n";
	cout << "Accessing all array's members without modifying them:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "(*ptr2 + " << i << ") RESULTING ADDRESS : " << (*ptr2 + i) << " Value : " << *(*ptr2 + i) << "\n";
	}
}

void LineTracer(void) // Creates a horizontal line for maximum terminal screen width size
{
	int width = 237; // The width depends of the screen resolution and also of the size of the font. In this case: Resolution 1920 X 1080; Font Size: 16.  
	char c = '_'; // The underline character will be used to make the line. The minus signal can also be an option.

	for (int i = 0; i < width; ++i)
	{
		cout << c;
	}

	cout << "\n";
}

void VectorPrinter(int Array[], int* p) // Displays arrays using a pointer. It works the same way: depends of the size declared for the pointer.
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Vector[" << i << "] Content: " << *(p + i) << "\n"; // Vector[i] is the same as *(p + i) and *(Vector + i).
		// The name of a vector works the same way as a pointer for the first element of the vector.
	}
}