#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct package {
	int payment;
	int weight;
};

int fromBinary(int bytes) {
	int number = 0;
	for (int i = 0; i < bytes; i++) {
		number += pow(2, i);
	}
	return number;
}

void pack(vector<package>& car, int* maxPayment,string numBin,int numItems, int maxMass) {
	int sumPayment = 0;
	int sumWeight = 0;
	for (int i = 0; i < numItems; i++) {
		if (numBin[i] == '1') {
			sumWeight += car[i].weight;
			sumPayment += car[i].payment;
		}
	}

	if (sumWeight <= maxMass && sumPayment > *maxPayment) {
		*maxPayment = sumPayment;
	}
}

void numbersCheckBinary(int numItems, int currNumber, vector<package>&car,int *maxPayment, int maxMass) {
	string numBin;
	char tempBin;
	int temp;

	for(int j = currNumber; j >= 0; j--){
		numBin = "";
		temp = j;
		for (int i = 0; i < numItems; i++) {
			if (temp % 2 == 0) {
				tempBin = '0';
			}
			else tempBin = '1';
			numBin += tempBin;
			temp /= 2;
		}
		pack(car, maxPayment, numBin, numItems, maxMass);
	}
}

int main() {
	int numItems;
	int maxMass;
	int weight;
	int payment;
	int maxPayment = 0;
	int biggestNumByBinary;
	package pack;

	for (int k = 0; k < 500; k++) {
		cin >> numItems;
		vector<package>car;
		for (int i = 0; i < numItems; i++) {
			cin >> payment;
			pack.payment = payment;
			car.push_back(pack);
		}

		for (int i = 0; i < numItems; i++) {
			cin >> weight;
			car[i].weight = weight;
		}

		cin >> maxMass;
		
		biggestNumByBinary = fromBinary(numItems);
		numbersCheckBinary(numItems, biggestNumByBinary, car, &maxPayment, maxMass);
		cout << maxPayment << endl;

		maxPayment = 0;
		car.clear();
	}

	return 0;
}