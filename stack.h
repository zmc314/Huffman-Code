#ifndef stack_H_
#define stack_H_

#define MaxSize 40

template<typename T>
struct SNode {
	T data;
	struct SNode* next;
};

template<typename T>
class stack {
private:
	SNode<T>* head; //��Զָ��ͷ�ڵ㣬�����ƶ�
	int top; //��ʾջ��λ��
public:
	//ADT����
		/*�������������*/
	stack() : head(NULL), top(-1) {}
	~stack() {}

	/*��ջ*/
	void CreateStack(int size);

	/*���ջ��*/
	bool IsFull();

	/*ѹջ*/
	void Push(T item);

	/*���ջ��*/
	bool IsEmpty();

	/*��ջ*/
	T Pop();
};

template<typename T>
void stack<T>::CreateStack(int size)
{
	head = new struct SNode<T>;
	SNode<T>* cur = NULL;
	SNode<T>* temp = NULL;
	temp = head;
	for (int i = 0; i < size; i++)
	{
		cur = new struct SNode<T>;
		temp->next = cur;
		temp = cur;
	}
	temp->next = NULL;
}

template<typename T>
bool stack<T>::IsEmpty() {
	return top == -1 ? true : false;
}

template<typename T>
void stack<T>::Push(T item) {
	if (IsFull() == true)
		return;
	SNode<T>* cur = head;
	for (int i = 0; i < top + 1; i++, cur = cur->next);
	top++;
	cur->data = item;
	return;
}

template<typename T>
bool stack<T>::IsFull() {
	return top == MaxSize - 1 ? true : false;
}

template<typename T>
T stack<T>::Pop() {
	T item = {};
	if (IsEmpty() == true)
		return item;
	SNode<T>* cur = head;
	for (int i = 0; i < top; i++, cur = cur->next);
	item = cur->data;
	top--;
	return item;
}

#endif // !stack_H_

