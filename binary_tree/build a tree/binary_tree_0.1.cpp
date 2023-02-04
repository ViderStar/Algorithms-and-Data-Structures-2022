#include <iostream>
#include <fstream>
#include <string>

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

	void leftOrdering(v* vertex, std::ofstream& out) {
		if (vertex != nullptr) {
			out << vertex->value << '\n';
			leftOrdering(vertex->left, out);
			leftOrdering(vertex->right, out);
		}
	}
};

int main() {
	BinaryTree bt;
	std::string value;

	std::ifstream in("input.txt");

	while (getline(in, value)) {
		bt.addV(stoi(value), bt.rootV);
	}

	std::ofstream out("output.txt");

	bt.leftOrdering(bt.rootV, out);

	return 0;
}