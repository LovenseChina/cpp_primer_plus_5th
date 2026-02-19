#ifndef QTEMP_H_
#define QTEMP_H_

template<class T, int n>
class Queue {
public:
	Queue(): rear(0), front(0), MAXSIZE(n) {}
	bool enqueue(const T &);
	bool dequeue(T &);
	bool isfull() const { return (rear + 1) % MAXSIZE == front; }
	bool isempty() const { return rear == front; }
private:
	const int MAXSIZE;
	int rear, front;
	T data[n];
};

template <class T, int n>
bool Queue<T, n>::enqueue(const T &item) {
	if ((rear + 1) % MAXSIZE == front)
		return false;
	else {
		data[rear] = item;
		rear = (rear + 1) % MAXSIZE;
		return true;
	}
}

template <class T, int n>
bool Queue<T, n>::dequeue(T &item) {
	if (rear == front)
		return false;
	else {
		item = data[front];
		front = (front + 1) % MAXSIZE;
		return true;
	}
}
#endif
