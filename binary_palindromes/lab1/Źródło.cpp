#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int fromBinary(int bytes) {
	int number=0;
	for (int i = 0; i < bytes; i++) {
		number += pow(2, i);
	}
	return number;
}

bool palinCheck(int bytes,string numToCheck) {
	char temp;
	int check = 0;
	for (int i = 0; i < bytes/2; i++) {
		temp = numToCheck[bytes - 1 - i];
		if (numToCheck[i] == temp) {
			check++;
		}
	}
	if (check == bytes / 2) return true;
	else return false;
}

void numbersCheckBinary(int bytes, int currNumber) {
	string numBin = "";
	char tempBin;
	int temp = currNumber;

	if (currNumber >= 0) {
		for (int i = 0; i < bytes;i++) {
			if (temp % 2 == 0) {
				tempBin = '0';
			}
			else tempBin = '1';
			numBin += tempBin;
			temp /= 2;
		}
		if (palinCheck(bytes, numBin)) cout << numBin;

		numbersCheckBinary(bytes, currNumber-1);
	}
}

int main() {
	unsigned int bytes;

	while (cin >> bytes) {
		int biggestNumber = fromBinary(bytes);
		numbersCheckBinary(bytes, biggestNumber);
		cout << endl;
	}
	return 0;
}