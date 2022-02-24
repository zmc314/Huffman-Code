#include"huffman.h"
#include"stack.h"

#define stack_size 40

void HTree::preordertraversal(TNode cur) {
	if (cur == NULL) {
		return;
	}
	if (cur->letter != NULL) {
		cout << cur->letter;
	}
	preordertraversal(cur->left);
	preordertraversal(cur->right);
	free(cur);
}

TNode HTree::createTree(vector<pair<int, char>> material) {
	pair<int, char> temp_ic;
	stack<TNode> paper;
	stack<TNode> temp_paper;
	TNode temp[stack_size];
	TNode temp_for_one;
	TNode parent[stack_size];
	TNode left;
	TNode right;
	
	/*用循环给结构体指针数组进行初始化*/
	for (int i = 0; i < stack_size; i++) {
		temp[i] = (TNode)malloc(sizeof(struct treeNode));
		parent[i] = (TNode)malloc(sizeof(struct treeNode));
		temp[i]->numbers = 0;
		parent[i]->numbers = 0;
	}

	/*建栈*/
	paper.CreateStack(stack_size);
	temp_paper.CreateStack(stack_size);

	int i = 0;
	while (material.size() != 0) {
		temp_ic = material.back();
		material.pop_back();
		temp[i]->letter = temp_ic.second;
		temp[i]->numbers = temp_ic.first;
		temp[i]->left = NULL;
		temp[i]->right = NULL;
		paper.Push(temp[i]);//按从大到小压入栈中
		i++;
	}
	i = 0;
	while (paper.IsEmpty() == false) {
		int flag = 0;
		left = paper.Pop();
		right = paper.Pop();
		/*将字母和字母数量存入树中*/
		parent[i]->left = left;
		parent[i]->right = right;
		parent[i]->letter = NULL;
		parent[i]->numbers = left->numbers + right->numbers;
		if (paper.IsEmpty() == true) {
			paper.Push(parent[i]);
			break;
		}
		/*将parent重新压回栈中*/
		temp_for_one = paper.Pop();
		while (temp_for_one->numbers < parent[i]->numbers) {
			temp_paper.Push(temp_for_one);
			if (paper.IsEmpty() == true) {
				flag = 1;
				break;
			}
			temp_for_one = paper.Pop();
		}
		if (flag == 0) {
			paper.Push(temp_for_one);
		}
		else {
			flag = 0;
		}
		paper.Push(parent[i]);
		i++;
		/*将存到暂时栈中的指针放回栈中*/
		while (temp_paper.IsEmpty() != true) {
			paper.Push(temp_paper.Pop());
		}	
	}
	/*释放内存*/
	for (int j = 0; j < stack_size; j++) {
		if (temp[j]->numbers == 0)
			free(temp[j]);
		if (parent[j]->numbers == 0)
			free(parent[j]);
	}
	/*将树的根赋值给头节点*/
	return paper.Pop();
}