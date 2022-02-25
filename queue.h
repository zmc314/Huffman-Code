#ifndef queue_H_
#define queue_H_

#define MaxSize 40

template<typename R>
struct QNode {
	R data;
	struct QNode* next;
};

template<typename R>
class queue {
private:
	QNode<R>* front;	//��Զָ�����ͷ�ڵ�
	QNode<R>* rear;		//��Զָ�����β�ڵ�
public:
	//ADT����
		/*�������������*/
	queue() : rear(NULL), front(NULL) {}
	~queue() { }

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
	front = new struct QNode<R>;
	rear = new struct QNode<R>;
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
		front = new struct QNode<R>;
		front->data = item;
		rear = front->next;
	}
	else {
		rear = new struct QNode<R>;
		rear->data = item;
		rear = rear->next;
	}
	return;
}

template<typename R>
R queue<R>::Pop() {
	R item = front->data;
	struct QNode<R>* cur;
	cur = front;
	front = front->next;
	free(cur);
	return item;
}

#endif //!queue_H_