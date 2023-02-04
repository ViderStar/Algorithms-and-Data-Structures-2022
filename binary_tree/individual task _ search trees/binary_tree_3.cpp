#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class v {
public:
	int value = 0;
	v* right = nullptr;
	v* left = nullptr;

	int leftNumber = 0;
	int rightNumber = 0;

	v(int value) {
		this->value = value;
	}
};

class BinaryTree {
public:
	v* rootV = nullptr;
	int size = 0;

	void addVInEmptyTree(int value) {
		size = -~size;
		this->rootV = new v(value);
	}

	void addV(int value, v* vertex) {
		if (rootV == nullptr) {
			addVInEmptyTree(value);
			return;
		}

		if (vertex->value < value && vertex->right == nullptr) {
			vertex->right = new v(value);
			size = -~size;
			return;
		}

		if (vertex->value < value && vertex->right != nullptr) {
			addV(value, vertex->right);
			return;
		}

		if (vertex->value > value && vertex->left == nullptr) {
			vertex->left = new v(value);
			size = -~size;
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

	void leftOrderingForLR(v* vertex) {
		if (vertex != nullptr) {
			leftOrderingForLR(vertex->left);
			leftOrderingForLR(vertex->right);
			if (vertex->left == nullptr && vertex->right == nullptr) {
				vertex->leftNumber = 0;
				vertex->rightNumber = 0;
			} else if(vertex->left != nullptr && vertex->right == nullptr) {
				vertex->leftNumber = vertex->left->leftNumber + vertex->left->rightNumber + 1;
				vertex->rightNumber = 0;
			}
			else if (vertex->left == nullptr && vertex->right != nullptr) {
				vertex->leftNumber = 0;
				vertex->rightNumber = vertex->right->leftNumber + vertex->right->rightNumber + 1;
			}
			else {
				vertex->leftNumber = vertex->left->leftNumber + vertex->left->rightNumber + 1;
				vertex->rightNumber = vertex->right->leftNumber + vertex->right->rightNumber + 1;
			}
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

	void leftOrderingForMiddle(v* vertex, int& count, std::vector<int>& vect) {
		if (vertex != nullptr) {
			if (abs(vertex->rightNumber - vertex->leftNumber) == 1) {
				vect[count] = vertex->value;
				count = -~count;
			}
			leftOrderingForMiddle(vertex->left, count, vect);
			leftOrderingForMiddle(vertex->right, count, vect);
		}
	}

	std::string getMiddleValue() {
		int count = 0;
		std::vector<int> vectMiddle(this->size);
		leftOrderingForMiddle(this->rootV, count, vectMiddle);
		if (count % 2 == 0) {
			return  " ";
		}
		std::sort(vectMiddle.begin(), vectMiddle.begin() + count);
		return std::to_string(vectMiddle[count / 2]);
	}
};

int main() {
	BinaryTree bt;
	std::string value;

	std::ifstream in("in.txt");

	while (getline(in, value)) {
		bt.addV(stoi(value), bt.rootV);
	}

	bt.leftOrderingForLR(bt.rootV);

	std::string middleValue = bt.getMiddleValue();

	if (middleValue[0] != ' ') {
		bt.deleteVertex(stoi(middleValue), bt.rootV);
	}

	std::ofstream out("out.txt");

	bt.leftOrdering(bt.rootV, out);

	out.close();

	return 0;
}