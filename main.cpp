#include"huffman.h"
#include"stack.h"

bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.first < b.first;
}

void main() {
	vector<pair<int, char>> in_paper;
	pair<int, char> temp;
	TNode head;

	/*�������*/
	cin >> temp.second;
	cin >> temp.first;
	while (temp.first != 0) {
		in_paper.push_back(temp);
		cin >> temp.second;
		cin >> temp.first;
	}
	sort(in_paper.begin(), in_paper.end(), cmp);//��С��������

	HTree Huffman_Tree;
	head = Huffman_Tree.createTree(in_paper);
	Huffman_Tree.preordertraversal(head);
}