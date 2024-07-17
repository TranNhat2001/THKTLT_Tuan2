#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// Định nghĩa cấu trúc hỗn số
struct MixedNumber {
	int wholePart; 
	int numerator; 
	int denominator; 
};

// Hàm tạo hỗn số ngẫu nhiên
MixedNumber createRandomMixedNumber() {
	MixedNumber mn;
	mn.wholePart = rand() % 10; 
	mn.numerator = rand() % 10; 
	do {
		mn.denominator = rand() % 9 + 1; 
	} while (mn.denominator == 0);
	return mn;
}

// Hàm tạo mảng hỗn số ngẫu nhiên
void createRandomMixedArray(MixedNumber arr[], int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = createRandomMixedNumber();
	}
}

// Hàm xuất danh sách hỗn số
void printMixedArray(const MixedNumber arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i].wholePart << " " << arr[i].numerator << "/" << arr[i].denominator << endl;
	}
}

// Hàm so sánh hai hỗn số
bool compareMixedNumbers(const MixedNumber &a, const MixedNumber &b) {
	int numeratorA = a.wholePart * a.denominator + a.numerator;
	int numeratorB = b.wholePart * b.denominator + b.numerator;
	int commonDenominator = a.denominator * b.denominator;

	return (numeratorA * b.denominator < numeratorB * a.denominator);
}
// Hàm chuyển hỗn số thành phân số
void convertToFraction(const MixedNumber &mn, int &numerator, int &denominator) {
	numerator = mn.wholePart * mn.denominator + mn.numerator;
	denominator = mn.denominator;
}

// Hàm chuyển phân số thành hỗn số
MixedNumber convertToMixedNumber(int numerator, int denominator) {
	MixedNumber mn;
	mn.wholePart = numerator / denominator;
	mn.numerator = numerator % denominator;
	mn.denominator = denominator;
	return mn;
}

// Hàm tính tổng hai hỗn số
MixedNumber addMixedNumbers(const MixedNumber &a, const MixedNumber &b) {
	int numeratorA, denominatorA;
	int numeratorB, denominatorB;

	convertToFraction(a, numeratorA, denominatorA);
	convertToFraction(b, numeratorB, denominatorB);

	int commonDenominator = denominatorA * denominatorB;
	int resultNumerator = numeratorA * denominatorB + numeratorB * denominatorA;

	return convertToMixedNumber(resultNumerator, commonDenominator);
}

// Hàm tính hiệu hai hỗn số
MixedNumber subtractMixedNumbers(const MixedNumber &a, const MixedNumber &b) {
	int numeratorA, denominatorA;
	int numeratorB, denominatorB;

	convertToFraction(a, numeratorA, denominatorA);
	convertToFraction(b, numeratorB, denominatorB);

	int commonDenominator = denominatorA * denominatorB;
	int resultNumerator = numeratorA * denominatorB - numeratorB * denominatorA;

	return convertToMixedNumber(resultNumerator, commonDenominator);
}

// Hàm tính tích hai hỗn số
MixedNumber multiplyMixedNumbers(const MixedNumber &a, const MixedNumber &b) {
	int numeratorA, denominatorA;
	int numeratorB, denominatorB;

	convertToFraction(a, numeratorA, denominatorA);
	convertToFraction(b, numeratorB, denominatorB);

	int resultNumerator = numeratorA * numeratorB;
	int resultDenominator = denominatorA * denominatorB;

	return convertToMixedNumber(resultNumerator, resultDenominator);
}

// Hàm tính thương hai hỗn số
MixedNumber divideMixedNumbers(const MixedNumber &a, const MixedNumber &b) {
	int numeratorA, denominatorA;
	int numeratorB, denominatorB;

	convertToFraction(a, numeratorA, denominatorA);
	convertToFraction(b, numeratorB, denominatorB);

	int resultNumerator = numeratorA * denominatorB;
	int resultDenominator = denominatorA * numeratorB;

	return convertToMixedNumber(resultNumerator, resultDenominator);
}


void main() {
	srand(time(0));

	const int size = 5;
	MixedNumber arr[size];

	createRandomMixedArray(arr, size);

	printf("Danh sach hon so: ");
	printMixedArray(arr, size);

	// So sánh hai hỗn số
	printf("\nSo sanh hon so dau va hon so thu hai: ");
	if (compareMixedNumbers(arr[0], arr[1])) {
		printf("\nHon so dau nho hon hon so thu hai");
	}
	else {
		printf("\nHon so dau lon hon hoac bang hon so thu hai");
	}
	// Chuyển hỗn số thành phân số và ngược lại
    int numerator, denominator;
    convertToFraction(arr[0], numerator, denominator);
	printf("\nHon so dau tien chuyen thanh phan so: %d/%d", numerator, denominator);

    MixedNumber mn = convertToMixedNumber(numerator, denominator);
	printf("\nPhan so %d/%d chuyen thanh hon so %d %d/%d", numerator, denominator, mn.wholePart, mn.numerator, mn.denominator);

    // Tính toán các phép toán trên hai hỗn số đầu tiên
    MixedNumber sum = addMixedNumbers(arr[0], arr[1]);
    MixedNumber difference = subtractMixedNumbers(arr[0], arr[1]);
    MixedNumber product = multiplyMixedNumbers(arr[0], arr[1]);
    MixedNumber quotient = divideMixedNumbers(arr[0], arr[1]);

	printf("\nTong cua hai hon so dau: %d %d/%d", sum.wholePart, sum.numerator, sum.denominator);
	printf("\nHieu cua hai hon so dau: %d %d/%d",difference.wholePart, difference.numerator, difference.denominator);
	printf("\nTich cua hai hon so dau: %d %d/%d",product.wholePart,product.numerator,product.denominator);
	printf("\nThuong cua hai hon so dau: %d %d/%d",quotient.wholePart, quotient.numerator, quotient.denominator);
	_getch();
}