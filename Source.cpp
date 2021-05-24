//13. Створити шаблонний клас – впорядкований одновимірний масив.
//Тип елементів масиву визначається параметром шаблона(цілі числа, дійсні числа, символи або символьні рядки).
//Передбачити функції для виконання таких операцій : введення елементів у масив, бінарний пошук заданого елемента у масиві 
//і виведення його номера, виведення масиву на екран.
#include <iostream>
using namespace std;

template<typename T>
class OneDim_Array {
private:
	T* arr;
	int size;

	int BinarySearch(int l, int r, T x)
	{
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (arr[m] == x)
				return m;
			if (arr[m] < x)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

public:
	OneDim_Array(int vsize) {
		size = vsize;
		arr = new T[size];
	}
	~OneDim_Array() {
		delete[] arr;
	}

	void InputArr() {
		int i, j;
		cout << "\nEnter elements of array:" << endl;
		for (i = 0; i < size; i++) {
			cin >> arr[i];
		}

		T temp;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (arr[i] > arr[j]) {
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}

	void SearchElem() {
		T elem;
		cout << "\nEnter element you search: ";
		cin >> elem;
		int id = BinarySearch (0, size - 1, elem);
		if (id == -1) {
			cout << "  Element doesn't exist in this array." << endl;
		}
		else {
			cout << "Element exists in this array. It's number is " << id + 1 << endl;
		}
	}

	void OutputArr() {
		cout << "\nSorted array:   ";
		int i;
		for (i = 0; i < size; i++) {
			cout << arr[i]<<"   ";
		}
		cout << endl;
	}
};


int main() {
	
	int size = 0;
	cout << "\nEnter size of double array: ";
	cin >> size;

	OneDim_Array<double> D_array(size);
	D_array.InputArr();
	D_array.SearchElem();
	D_array.OutputArr();

	cout << "\n\nEnter size of string array: ";
	cin >> size;

	OneDim_Array<string> S_array(size);
	S_array.InputArr();
	S_array.SearchElem();
	S_array.OutputArr();

	return 0;
}