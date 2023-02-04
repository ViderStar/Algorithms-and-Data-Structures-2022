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

	v* deleteVertex(int value, v* vertex) {
		if (vertex == nullptr) {
			return nullptr;
		}

		if (vertex->value > value) {
			vertex->left = deleteVertex(value, vertex->left);
			return vertex;

		}
		else if (vertex->value < value) {
			vertex->right = deleteVertex(value, vertex->right);
			return vertex;
		}

		if (vertex == rootV) {
			if (rootV->left != nullptr && rootV->right == nullptr) {
				rootV = rootV->left;
			}
			else if (rootV->left == nullptr && rootV->right != nullptr) {
				rootV = rootV->right;
			}
			else {
				int min = findMinVertex(vertex->right)->value;
				vertex->value = min;
				vertex->right = deleteVertex(min, vertex->right);
			}
			return nullptr;
		}

		if (vertex->left == nullptr) {
			return vertex->right;
		}
		else if (vertex->right == nullptr) {
			return vertex->left;
		}
		else {
			int min = findMinVertex(vertex->right)->value;
			vertex->value = min;
			vertex->right = deleteVertex(min, vertex->right);
			return vertex;
		}
		
	}

	v* findMinVertex(v* vertex) {
		if (vertex->left != nullptr) {
			return findMinVertex(vertex->left);
		}
		return vertex;
	}
};

int main() {
	BinaryTree bt;
	std::string value;
	
	int deleteValue;

	std::ifstream in("input.txt");

	getline(in, value);
	deleteValue = std::stoi(value);
	getline(in, value);

	while (getline(in, value)) {
		bt.addV(stoi(value), bt.rootV);
	}

	bt.deleteVertex(deleteValue, bt.rootV);

	std::ofstream out("output.txt");

	bt.leftOrdering(bt.rootV, out);

	out.close();

	return 0;
}