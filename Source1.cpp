

/** 
	Algorithm:
	
	printCustomerData(id, first, last, savingAcc, checkingAcc){
	cout << id << first << last << savingAcc << checkingAcc
	}

	printNames(id, string, last){
	cout << id << string << last
	}

	printTotal(id, savingAcc, chckingAcc, Total){
	cout << id << savingAcc << checkingAcc << Total
	}

	main(){
	id, first, last, savingAcc, checkingAcc      ... arrays 
	}

	Store the input in declared arrays, from input file and return for specifed case.
	line = 0; to read every line starting from 0th index.
	while fin!.good() read file

	Menu: 
	1. Print data : return printCustomerData
	2. Print names : printNames
	3. Print Total : printTotal
	4. Exit : Exit program
	}
	**/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printCustomerData(int id[], string first[], string last[], double savings_Account[], double checking_Account[], int size) {
	int a;
	for (a = 0;a < size;a++) {
		
		cout << id[a] << "\t" << first[a] << "\t" << last[a] << "\t\t" << savings_Account[a] << "\t\t" << checking_Account[a] << "\t" << endl;
	}
}

void printNames(int id[], string first[], string last[], int size) {
	int a;
	for (a = 0;a < size;a++) {
		
		cout << id[a] << "\t" << first[a] << "\t" << last[a] << "\t" << endl;
	}

}

void printTotal(int id[], double savings_Account[], double checking_Account[], int size) {
	int a;
	for (a = 0;a < size;a++) {
		
		cout << id[a] << setw(15) << savings_Account[a] << setw(15) << checking_Account[a] << "\t\t" << savings_Account[a] + checking_Account[a] << "\t" << endl;
	}
}

int main() {

	const int s = 10;
	int id[s];
	double saving[s], checking[s];
	string first[s], last[s];

	ifstream fin("input.txt");

	if (!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}

	int line = 0;
	
	while(fin.good()) {
		fin >> id[line] >> first[line] >> last[line] >> saving[line] >> checking[line];
		
		//cout << id[line] << first[line] << last[line] << saving[line] << checking[line] << endl;
		
		line++;
		
	}

	int opt;
	bool flag = true;
	do {
		cout << "1. Print all customer data" << endl;
		cout << "2. Print name and ID's" << endl;
		cout << "3. Print account total" << endl;
		cout << "4. Enter q/Q to quit" << endl;

		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "ID" << "\t" << "First" << "\t" << "Last" << "\t" << "Saving Account" << "\t" << "Checking Account" << "\t" << endl;
			printCustomerData(id, first, last, saving, checking, s);
			break;
		case 2:
			cout << "ID" << "\t" << "First" << "\t" << "Last" << "\t" << endl;
			printNames(id, first, last, s);
			break;
		case 3:
			cout << "ID" << "\t" << "Saving Account" << "\t" << "Checking Account" << "\t" << "Total" << "\t" << endl;
			printTotal(id, saving, checking, s);
			break;
		default: {
			flag = false;
			exit(1);
		}
		}

	} while (flag);
	fin.close();
	
	getchar();

}