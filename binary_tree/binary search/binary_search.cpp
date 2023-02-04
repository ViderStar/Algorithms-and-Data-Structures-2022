#include <iostream>

void binarySearchFunction(int num, int* arr, int size) {
    int b = -1;
    int l = -1; 
    int r = -1;
    int left = 0;
    int right = size - 1;
    int middle = (size - 1) / 2;

    while (b == -1) {
        if (arr[middle] == num) {
            b = 1;
        }
        else if(arr[middle] < num) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }

        if (left > right) {
            b = 0;
        } 

        middle = (left + right) / 2;
    }

    if (b == 1) {
        int left = 0;
        int right = size - 1;
        while (l == -1) {
            if (arr[middle - 1] == num) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }

            if (arr[middle - 1] != num && arr[middle] == num) {
                l = middle;
            }
            
            middle = (left + right) / 2;
            
        }
    }
    else {
        if (arr[middle] > num) {
            l = middle;
        }
        else if (middle + 1 != size && arr[middle + 1] > num) {
            l = middle + 1;
        }
        else {
            l = size;
        }
    }

    if (arr[middle] > num && arr[middle - 1] <= num) {
        r = middle;
    }
    else {
        left = 0;
        right = size - 1;
        while (r == -1) {
            if (arr[middle] > num) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }

            if (arr[middle] > num && (arr[middle - 1] <= num || middle - 1 < 0)) {
                r = middle; 
            }
            else if (middle == size || middle + 1 == size) {
                r = size;
            }
            
            middle = (left + right) / 2;
        }
    }

    std::cout << b << " " << l << " " << r << '\n';
}

int main()
{
    int size;
    int requestCount;
    int* arr;

    std::cin >> size;
    int temp = 0;
    arr = new int[size];

    while (temp != size) {
        std::cin >> arr[temp];
        ++temp;
    }

    std::cin >> requestCount;

    while (requestCount != 0) {
        int requestNumber;

        std::cin >> requestNumber;

        binarySearchFunction(requestNumber, arr, size);

        --requestCount;
    }
}