#include <iostream>

using namespace std;

int n;
char tree[30][3];

int searchNode(char node) {
	for (int i = 0; i < n; i++) {
		if (tree[i][0] == node)
			return i;
	}
}

void preorder(int nodeIdx) {
	cout << tree[nodeIdx][0];
	if (tree[nodeIdx][1] != '.')	preorder(searchNode(tree[nodeIdx][1]));
	if (tree[nodeIdx][2] != '.')	preorder(searchNode(tree[nodeIdx][2]));
}

void inorder(int nodeIdx) {
	if (tree[nodeIdx][1] != '.')	inorder(searchNode(tree[nodeIdx][1]));
	cout << tree[nodeIdx][0];
	if (tree[nodeIdx][2] != '.')	inorder(searchNode(tree[nodeIdx][2]));
}

void postorder(int nodeIdx) {
	if (tree[nodeIdx][1] != '.')	postorder(searchNode(tree[nodeIdx][1]));
	if (tree[nodeIdx][2] != '.')	postorder(searchNode(tree[nodeIdx][2]));
	cout << tree[nodeIdx][0];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tree[i][j];
		}
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}