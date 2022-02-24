#ifndef queue_H_
#define queue_H_

#define MaxSize 40

template<typename R>
struct SNode {
	R data;
	struct SNode* next;
};

template<typename R>
class queue {
private:
	SNode<R>* front;	//��Զָ�����ͷ�ڵ�
	SNode<R>* rear;		//��Զָ�����β�ڵ�
public:
	//ADT����
		/*�������������*/
	queue() : rear(NULL), front(NULL) {}
	~queue() { free(front); }

	/*��ջ*/
	void CreateQueue(int size);

	/*ѹ�����*/
	void Push(R item);

	/*�������Ƿ��*/
	bool IsEmpty();

	/*����*/
	R Pop();
};


template<typename R>
void queue<R>::CreateQueue(int size)
{
	front = new struct SNode<R>;
	/*ͷβ��ͬһ�ڵ�*/
	rear = front;
}

template<typename R>
bool queue<R>::IsEmpty() {
	return front == rear ? true : false;
}

template<typename R>
void queue<R>::Push(R item) {
	if (IsEmpty() == true) {
		front->data = item;
		rear = front->next;
	}
	else {
		rear = new struct SNode<R>;
		rear->data = item;
		rear = rear->next;
	}
	return;
}

template<typename R>
R queue<R>::Pop() {
	T item = {};
	if (IsEmpty() == true)
		return item;
	SNode<T>* cur = front;
	for (int i = 0; i < top; i++, cur = cur->next);
	item = cur->data;
	top--;
	return item;
}

#endif //!queue_H_