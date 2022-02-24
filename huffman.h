#ifndef huffman_H_
#define huffman_H_

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*因为哈夫曼树只有字母和字母的数量，所以不需要使用模板*/
/*每一个树节点中都存有一个字母和这个字母在字段中的数量*/
typedef struct treeNode {
	char letter;
	int numbers;
	struct treeNode* left;	//左孩子
	struct treeNode* right;	//右孩子
}* TNode;

/*建哈夫曼树类*/
class HTree {
public:
	/*构造和析构函数*/
	HTree() {}
	~HTree() { }
	
	/*建树*/
	//TODO:加入参数，直接从文件中读取。
	TNode createTree(vector<pair<int, char>> material);

	/*前序遍历*/
	void preordertraversal(TNode cur);
	void levelordertraversal();
};


#endif // !huffman_H_

