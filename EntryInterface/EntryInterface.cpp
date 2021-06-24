#include <iostream>
#include <limits>
using namespace std;

short NBSTUDENTS;
const char STRINGSIZE = 50;

struct Student
{
	char firstName[STRINGSIZE];
	char lastName[STRINGSIZE];
	double average; // avg grade (%)
};

int main(void)
{
	cout << "Enter the number of students (> 1) : ";
	cin >> NBSTUDENTS;
	while (NBSTUDENTS <= 1) {
		cout << "Error ! The number of students must be strictly superior to 1." << endl << \
			"Enter the number of students : ";
		cin >> NBSTUDENTS;
	}

	Student* studentsArray = new Student[NBSTUDENTS]; // allocate array of Student and store address in studentsArray ptr

	if (studentsArray == nullptr) { // validate allocation
		cout << "Error while allocating the students array !" << endl;
		system("pause");
		exit(1);
	}

	cout << "Enter first name, last name and average for each of the " << NBSTUDENTS << " students :";

	for (short i = 0; i < NBSTUDENTS; i++) {
		cout << "Enter the first name for student # " << (i+1) << " : ":
		cin >> studentsArray[i].firstName;

	}

	return 0;
}
