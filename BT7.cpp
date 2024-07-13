#include <iostream>
#include <cmath>
using namespace std;

// a. Tìm phần tử lớn nhất và địa chỉ của nó
void findMaxElement(int* arr, int n) {
    int* maxElem = arr;
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > *maxElem) {
            maxElem = arr + i;
        }
    }
    cout << "Phan tu lon nhat: " << *maxElem << " tai dia chi: " << maxElem << endl;
}

// b. Tìm địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
void findEvenOdd(int* arr, int n) {
    int* maxEven = nullptr;
    int* minOdd = nullptr;
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) % 2 == 0) {
            if (!maxEven || *(arr + i) > *maxEven) {
                maxEven = arr + i;
            }
        }
        else {
            if (!minOdd || *(arr + i) < *minOdd) {
                minOdd = arr + i;
            }
        }
    }
    if (maxEven) {
        cout << "Phan tu chan lon nhat tai dia chi: " << maxEven << endl;
    }
    else {
        cout << "Khong co phan tu chan trong mang" << endl;
    }
    if (minOdd) {
        cout << "Phan tu le nho nhat tai dia chi: " << minOdd << endl;
    }
    else {
        cout << "Khong co phan tu le trong mang" << endl;
    }
}

// c. Xóa phần tử có giá trị 0
void removeZeroes(int* arr, int& n) {
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) != 0) {
            arr[newSize++] = arr[i];
        }
    }
    n = newSize;
}

// d. Thêm phần tử x vào sau phần tử đầu tiên
void addElementAfterFirst(int* arr, int& n, int x) {
    for (int i = n; i > 1; --i) {
        arr[i] = arr[i - 1];
    }
    arr[1] = x;
    ++n;
}

// e. Tính tổng các phần tử là số chính phương
bool isPerfectSquare(int num) {
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

int sumOfPerfectSquares(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (isPerfectSquare(*(arr + i))) {
            sum += *(arr + i);
        }
    }
    return sum;
}

// f. Xuất các số cực đại trong mảng
void findLocalMaxima(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if ((i == 0 || *(arr + i) > *(arr + i - 1)) && (i == n - 1 || *(arr + i) > *(arr + i + 1))) {
            cout << "So cuc dai: " << *(arr + i) << " tai dia chi: " << (arr + i) << endl;
        }
    }
}

int main() {
    int arr[11] = { 3, 1, 4, 1, 5, 9, 2, 6, 0, 5 }; // Tăng kích thước để có thể thêm phần tử
    int n = 10; // Kích thước thực tế của mảng

    findMaxElement(arr, n);
    findEvenOdd(arr, n);

    removeZeroes(arr, n);
    cout << "Mang sau khi xoa phan tu 0: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    addElementAfterFirst(arr, n, 7);
    cout << "Mang sau khi them phan tu 7: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int sum = sumOfPerfectSquares(arr, n);
    cout << "Tong cac phan tu la so chinh phuong: " << sum << endl;

    findLocalMaxima(arr, n);

    return 0;
}