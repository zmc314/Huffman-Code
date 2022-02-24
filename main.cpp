#include"huffman.h"
#include"stack.h"

bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.first < b.first;
}

void main() {
	vector<pair<int, char>> in_paper;
	pair<int, char> temp;
	TNode head;

	/*输出参数*/
	cin >> temp.second;
	cin >> temp.first;
	while (temp.first != 0) {
		in_paper.push_back(temp);
		cin >> temp.second;
		cin >> temp.first;
	}
	sort(in_paper.begin(), in_paper.end(), cmp);//从小到大排序

	HTree Huffman_Tree;
	head = Huffman_Tree.createTree(in_paper);
	Huffman_Tree.preordertraversal(head);
}