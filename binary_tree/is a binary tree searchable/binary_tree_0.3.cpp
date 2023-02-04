#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

struct v {
	int value;
	int min;
	int max;
};

v* arr;
int n;

int main()
{
	std::string value;

	std::ifstream in("bst.in");

	getline(in, value);

	n = std::stoi(value);

	arr = new v[n];
	int i = 1;

	getline(in, value);

	arr[0].value = std::stoi(value);
	arr[0].min = INT_MIN;
	arr[0].max = INT_MAX;

	bool flag = true;

	while (getline(in, value)) {
		int number = std::stoi(value.substr(0, value.find_first_of(' ')));
		int numberStr = std::stoi(value.substr(value.find_first_of(' ') + 1, value.find_last_of(' ') - (value.find_first_of(' ') + 1)));
		int min, max;
		int parentValue = arr[numberStr - 1].value;
		int parentMin = arr[numberStr - 1].min;
		int parentMax = arr[numberStr - 1].max;

		arr[i].value = number;
		
		if (value[value.length() - 1] == 'L') {
			max = std::min(parentMax, parentValue) - 1;
			min = parentMin;

			if (std::min(parentMax, parentValue) == INT_MIN) {
				flag = false;
				break;
			}
		}
		else {
			max = arr[numberStr - 1].max;
			min = std::max(parentMin, parentValue);
		}

		if (number < min || number > max) {
			flag = false;
			break;
		}

		arr[i].min = min;
		arr[i].max = max;
		++i;
	}

	std::ofstream out("bst.out");

	if (flag) {
		out << "YES";
	}
	else {
		out << "NO";
	}

	return 0;
	 
}