#include <iostream>

using namespace std;

struct Tree {
	int left;
	int right;
};

const int MAX = 100;
int n;
Tree t[MAX];

void preorder(int x) {
	cout << x << ' ';
	if (t[x].left != -1) preorder(t[x].left);
	if (t[x].right != -1) preorder(t[x].right);
}

void inorder(int x) {
	if (t[x].left != -1) inorder(t[x].left);
	cout << x << ' ';
	if (t[x].right != -1) inorder(t[x].right);
}

void postorder(int x) {
	if (t[x].left != -1) postorder(t[x].left);
	if (t[x].right != -1) postorder(t[x].right);
	cout << x << ' ';
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		t[a].left = b;
		t[a].right = c;
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;

}
