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
	SNode<R>* front;	//永远指向队列头节点
	SNode<R>* rear;		//永远指向队列尾节点
public:
	//ADT方法
		/*构造和析构函数*/
	queue() : rear(NULL), front(NULL) {}
	~queue() { free(front); }

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
	front = new struct SNode<R>;
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