/*
Cameron Cunningham
CMSY-281-001
Lab 0
01-29-2020
*/

#include <iostream>
#include <cstring>
#include <string>
#include <array>

using namespace std;
//headers for functions
void validate(int&);
string toLower(string stringToUpper);
void entry(string[],int*,int);
void menu(string[], int*, int);
void displayAnimals(string[],int*,int);


int main() {
	int numOfAnimals{};
	string* animals = NULL;
	int* animalCounts = NULL;
	//Collecting how many animals they want to enter.

	cout << "How many animals will you be entering? (Maximum is 5)";
	cin >> numOfAnimals;
	validate(numOfAnimals);

	//Creating dynamic arrays based on how many animals they are entering.
	animals = new string[numOfAnimals];
	animalCounts = new int[numOfAnimals];

	//Displaying the menu for adding animals,displaying, and quiting
	menu(animals, animalCounts, numOfAnimals);
	
	system("pause");
	return 0;
}


//Function for entering the animals
void entry(string animals[], int* animalCounts, int numberOfAnimals) {
	//Collecting animal data loop
	for (int i{}; i < numberOfAnimals; i++) {
		cout << "Please enter the species of animal: ";
		cin >>animals[i];
		if (toLower(animals[i]) != "none") {
		cout << endl << "Please enter the count of that animal: ";
		cin >> *(animalCounts + i);
	}
}
}

// validate number of animals
void validate(int& numToValidate) {
	while (numToValidate < 0) {
		cout << "\n\n\t Invalid number entered.\n\t\t Please reenter the number: ";
		cin >> numToValidate;
	}

	while (numToValidate > 5) {
		cout << "\n\n\t Invalid number entered.\n\t\t Please reenter the number: ";
		cin >> numToValidate;
	}

}

// function for the menu
void menu(string animals[], int* animalCounts, int numberOfAnimals) {
	int choice{};

	while (choice != 3) {
		cout << "\n1. Add Animals\n" << "2. Display Animals\n" << "3: Quit" << endl << endl << "Menu Choice: ";
		cin >> choice;

		switch (choice) {
		case (1):
			cin.ignore();
			entry(animals, animalCounts, numberOfAnimals);
			cin.ignore();
			break;
		case (2):
			
			displayAnimals(animals, animalCounts, numberOfAnimals);
			break;
		case(3):
			cout << "Exiting program" <<endl;
			break;
		}
	}
}

// function for displaying data inside the arrays
void displayAnimals(string animals[], int* animalCounts, int numberOfAnimals) {

	for (int i{}; i < numberOfAnimals; i++) {
		cout << "Animal: " << animals[i] << endl;
		cout << "Count: " << *(animalCounts + i) << endl;
	}

}


// function that turns string to all lowercase
string toLower(string stringToLower) {

	string tempString;
	for (int i{}; i < stringToLower.length(); i++){
		tempString += tolower(stringToLower[i]);
	}
	return tempString;
}

