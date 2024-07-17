#include <iostream>
#include <cstdlib> 
#include <conio.h>

using namespace std;

// Hàm tạo mảng ngẫu nhiên có số phần tử từ 15 đến maxElements
void createRandomArray(int a[], int &n, int maxElements) {
	n = 15 + rand() % (maxElements - 14);
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 100;
	}
}

// Hàm tạo mảng chỉ chứa các số chẵn từ mảng ban đầu
void createEvenArray(const int a[], int n, int evenArray[], int &evenCount) {
	evenCount = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) {
			evenArray[evenCount++] = a[i];
		}
	}
}

// Hàm tìm kiếm tuyến tính x trong mảng a
bool linearSearch(const int a[], int n, int x, int &position) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == x) {
			position = i;
			return true;
		}
	}
	return false;
}

// Hàm sắp xếp tăng dần bằng giải thuật Interchange Sort
void interchangeSort(int a[], int n, bool ascending) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

// Hàm tìm kiếm nhị phân x trong mảng đã sắp xếp tăng dần
bool binarySearch(const int a[], int n, int x, int &position) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			position = mid;
			return true;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

// Hàm sắp xếp tăng dần bằng giải thuật Selection Sort
void selectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}
}

// Hàm đổi chỗ hai phần tử
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

// Hàm phân đoạn cho giải thuật Quick Sort
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
		if (a[j] < pivot) {
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return (i + 1);
}

// Hàm sắp xếp tăng dần bằng giải thuật Quick Sort
void quickSort(int a[], int low, int high) {
	if (low < high) {
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

// Hàm in ra mảng
void printArray(const int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf(" %d ", a[i]);;
	}
}

void main() {
	const int MAX_ELEMENTS = 30;

	int a[MAX_ELEMENTS];
	int n;

	// Tạo mảng ngẫu nhiên có số phần tử từ 15 đến MAX_ELEMENTS
	createRandomArray(a, n, MAX_ELEMENTS);

	printf("\nMang ngau nhien: ");
	printArray(a, n);

	// Tạo mảng chỉ chứa các số chẵn từ mảng ban đầu
	int evenArray[MAX_ELEMENTS];
	int evenCount;
	createEvenArray(a, n, evenArray, evenCount);

	printf("\nMang chi chua so chan: ");
	printArray(evenArray, evenCount);

	// Tìm kiếm tuyến tính số 50 trong mảng a
	int position;
	int x = 50;
	if (linearSearch(a, n, x, position)) {
		printf("\nTim thay %d tai vi tri %d", x, position);
	}
	else {
		printf("\nKhong tim thay %d trong mang", x);
	}

	// Sắp xếp mảng a tăng dần bằng Interchange Sort và in ra kết quả
	interchangeSort(a, n, true);
	printf("\nMang sau khi sap xep tang dan: ");
	printArray(a, n);

	// Tìm kiếm nhị phân số 50 trong mảng a đã sắp xếp tăng dần
	if (binarySearch(a, n, x, position)) {
		printf("\nTim thay %d tai vi tri %d", x,  position);
	}
	else {
		printf("\nKhong tim thay %d trong mang.", x);
	}

	// Sắp xếp mảng a tăng dần bằng Selection Sort và in ra kết quả
	selectionSort(a, n);
	printf("\nMang sau khi sap xep tang dan (Selection Sort): ");
	printArray(a, n);

	// Sắp xếp mảng a tăng dần bằng Quick Sort và in ra kết quả
	quickSort(a, 0, n - 1);
	printf("\nMang sau khi sap xep tang dan (Quick Sort): ");
	printArray(a, n);
	_getch();
}