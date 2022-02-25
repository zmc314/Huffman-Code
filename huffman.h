#ifndef huffman_H_
#define huffman_H_

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*��Ϊ��������ֻ����ĸ����ĸ�����������Բ���Ҫʹ��ģ��*/
/*ÿһ�����ڵ��ж�����һ����ĸ�������ĸ���ֶ��е�����*/
typedef struct treeNode {
	char letter;
	int numbers;
	struct treeNode* left;	//����
	struct treeNode* right;	//�Һ���
}* TNode;

/*������������*/
class HTree {
public:
	TNode head;
	/*�������������*/
	HTree() : head(NULL) {}
	~HTree() { }
	
	/*����*/
	//TODO:���������ֱ�Ӵ��ļ��ж�ȡ��
	void createTree(vector<pair<int, char>> material);

	/*ǰ�����*/
	void preordertraversal(TNode cur);
	void levelordertraversal();
};


#endif // !huffman_H_

