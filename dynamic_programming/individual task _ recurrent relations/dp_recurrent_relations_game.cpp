#include <iostream>
#include <fstream>

const int SIZE = 10000000;
int* resultArray = new int[SIZE];

using namespace std;

void createEmptyArray() {
    for (int i = 0; i < SIZE; ++i) {
        resultArray[i] = 0;
    }
    resultArray[SIZE-1] = 1;
}

int pow10[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

int getDigit(int n, int digit) {
    return n / pow10[7 - digit] % 10;
}


void createArrayOfPosition() {
    createEmptyArray();
    int counter = SIZE - 1;
    while (counter > 0) {

        int allD[7] = { getDigit(counter, 7), getDigit(counter, 6), getDigit(counter, 5), 
        getDigit(counter, 4), getDigit(counter, 3), getDigit(counter, 2), getDigit(counter, 1) };

        for (int digitalToAdd = 1; digitalToAdd < 4; ++digitalToAdd) {
            for (int i = 0; i < 7; ++i) {
                if (allD[i] + digitalToAdd < 10) {
                    resultArray[counter] += resultArray[counter + pow10[i] * digitalToAdd];
                }
            }
        }

        if (resultArray[counter] != 0) {
            resultArray[counter] = 0;
        }
        else {
            resultArray[counter] = 1;
        }

        --counter;
    }
}

bool diffByOneDigit(int a, int b) {
    int res = 0;
    res += (a % 10 != b % 10);
    while ((a /= 10) && (b /= 10)) {
        res += (a % 10 != b % 10);
    }
    return res <= 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ifstream in("input.txt");
    int num;
    in >> num;
    in.close();

    createArrayOfPosition();

    std::ofstream out("output.txt");
    if (resultArray[num] == 1) {
        out << "The second wins";
        out.close();
    }
    else {
        out << "The first wins\n";
        for (int i = 0; i < 7; ++i) {
            for (int digitalToAdd = 1; digitalToAdd < 4; ++digitalToAdd) {
                if (num + pow10[i] * digitalToAdd < SIZE 
                    && resultArray[num + pow10[i] * digitalToAdd] != 0  
                    && diffByOneDigit(num, num + pow10[i] * digitalToAdd)) {
                    out << num + pow10[i] * digitalToAdd << " ";
                }
            }
        }
    }

    out.close();
    
    return 0;
}