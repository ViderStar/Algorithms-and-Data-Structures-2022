#include <iostream>
#include <fstream>
#include <string>
#include <set>

class v {
public:
	int value = 0;
	v* right = nullptr;
	v* left = nullptr;

	v(int value) {
		this->value = value;
	}
};

class BinaryTree {
public:
	v* rootV = nullptr;

	void addVInEmptyTree(int value) {
		this->rootV = new v(value);
	}

	void addV(int value, v* vertex) {
		if (rootV == nullptr) {
			addVInEmptyTree(value);
			return;
		}

		if (vertex->value < value && vertex->right == nullptr) {
			vertex->right = new v(value);
			return;
		}

		if (vertex->value < value && vertex->right != nullptr) {
			addV(value, vertex->right);
			return;
		}

		if (vertex->value > value && vertex->left == nullptr) {
			vertex->left = new v(value);
			return;
		}

		if (vertex->value > value && vertex->left != nullptr) {
			addV(value, vertex->left);
			return;
		}
	}

	void leftOrdering(v* vertex, int& sum) {
		if (vertex != nullptr) {
			sum += vertex->value;
			leftOrdering(vertex->left, sum);
			leftOrdering(vertex->right, sum);
		}
	}
};

int main() {
	BinaryTree bt;
	std::string value;

	std::ifstream in("input.txt");

	std::set<int> st;

	while (getline(in, value)) {
		st.insert(std::stoi(value));
	}

	std::ofstream out("output.txt");

	long long sum = 0;

	std::set<int>::iterator it = st.begin();

	while (it != st.end()) {
		sum += *it;
		++it;
	}

	out << sum;

	out.close();

	return 0;
}