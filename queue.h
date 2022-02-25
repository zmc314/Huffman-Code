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
	QNode<R>* front;	//永远指向队列头节点
	QNode<R>* rear;		//永远指向队列尾节点
public:
	//ADT方法
		/*构造和析构函数*/
	queue() : rear(NULL), front(NULL) {}
	~queue() { }

	/*建栈*/
	void CreateQueue(int size);

	/*压入队列*/
	void Push(R item);

	/*检查队列是否空*/
	bool IsEmpty();

	/*出队*/
	R Pop();
};


template<typename R>
void queue<R>::CreateQueue(int size)
{
	front = new struct QNode<R>;
	rear = new struct QNode<R>;
	/*头尾在同一节点*/
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