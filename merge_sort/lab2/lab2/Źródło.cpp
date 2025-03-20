#include<iostream>
#include<string>
using namespace std;

bool compareSmaller(string leftNum, string rightNum) {
	int size1 = leftNum.length();
	int size2 = rightNum.length();

	if (size1 > size2) {
		return true;
	}
	else if (size1 == size2) {
		for (int i = 0; i < size1; i++) {
			if (leftNum[i] > rightNum[i]) {
				return true;
			}
			else if (rightNum[i] > leftNum[i]) {
				return false;
			}
		}
	}
	return false;
}

void mergeConnect(string* arr, int left, int middle, int right) {
	int s1 = middle - left + 1;
	int s2 = right - middle;

	string* leftArr = new string[s1];
	string* rightArr = new string[s2];
	string* connectArr = new string[s1 + s2];

	for (int i = 0; i < s1; i++) {
		leftArr[i] = arr[left + i];
	}
	for (int i = 0; i < s2; i++) {
		rightArr[i] = arr[middle + i + 1];
	}

	int i = 0, j = 0, k = 0;

	while (i < s1 && j < s2) {
		if (compareSmaller(leftArr[i],rightArr[j])) {
			connectArr[k] = rightArr[j];
			j++, k++;
		}
		else {
			connectArr[k] = leftArr[i];
			i++, k++;
		}
	}

	while (i < s1) {
		connectArr[k] = leftArr[i];
		k++, i++;
	}
	while (j < s2) {
		connectArr[k] = rightArr[j];
		k++, j++;
	}

	for (int p = 0; p < (s1 + s2); p++) {
		arr[left+p] = connectArr[p];
	}

	delete[] connectArr;
	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(string* arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int middle =(left + right) / 2;
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	mergeConnect(arr, left, middle, right);
}

void print(string* arr, int nOfNumbers) {
	for (int i = 0; i < nOfNumbers; i++) {
		cout << arr[i] << endl;
	}
}

int main() {
	string number;
	int nOfNum;
	int left, right;
	cin >> nOfNum;

	string *arr = new string[nOfNum];

	for (int i = 0; i < nOfNum;i++) {
		cin >> number;
		arr[i] = number;
	}

	left = 0;
	right = nOfNum - 1;
	mergeSort(arr, left, right);

	print(arr,nOfNum);

	delete[] arr;
}