#include <iostream>

using namespace std;

template <class T>
class Heap {
	public:
		Heap() {
			this->MAX_SIZE = 1000;
			this->size = 0;
			this->data = new T[MAX_SIZE+1];
		}
		Heap(int size) {
			this->MAX_SIZE = size;
			this->size = 0;
			this->data = new T[MAX_SIZE+1];
		}
		virtual ~Heap() {
			delete [] this->data;
		}
		virtual void push(int data) = 0;
		virtual T pop() = 0;
	protected:
		T *data;
		int MAX_SIZE;
		int size;
		int getParent(int idx) {
			int res = idx/2;
			return (res <= 0) ? -1 : res;
		}
		int getLeftChild(int idx) {
			int res = idx*2;
			return (res > MAX_SIZE) ? -1 : res;
		}
		int getRightChild(int idx) {
			int res = idx*2 + 1;
			return (res > MAX_SIZE) ? -1 : res;
		}
};

template <class T>
class MaxHeap : public Heap<T> {
	public:
		MaxHeap() : Heap<T>() {};
		MaxHeap(int size) : Heap<T>(size) {};

		void push(int data) {
			if (this->size == this->MAX_SIZE) return;
			int idx = ++(this->size);
			while (idx > 1 && data > this->data[this->getParent(idx)]) {
				this->data[idx] = this->data[this->getParent(idx)];
				idx = this->getParent(idx);
			}
			this->data[idx] = data;
		}
		T pop() {
			if (this->size == 0) return NULL;
			int item = this->data[1];
			int temp = this->data[this->size--];
			int idx = 1;
			int child = 2;	
			while (child <= this->size) {
				if (child+1 <= this->size && this->data[child] < this->data[child+1]) child += 1;
				if (temp > this->data[child]) break;
				this->data[idx] = this->data[child];
				idx = child;
				child = this->getLeftChild(idx);
				if (child == -1) break;
			}	
			this->data[idx] = temp;
			return item;
		}
};

template <class T>
class MinHeap : public Heap<T> {
	public:
		MinHeap() : Heap<T>() {};
		MinHeap(int size) : Heap<T>(size) {};

		void push(int data) {
			if (this->size == this->MAX_SIZE) return;
			int idx = ++(this->size);
			while (idx > 1 && data < this->data[this->getParent(idx)]) {
				this->data[idx] = this->data[this->getParent(idx)];
				idx = this->getParent(idx);
			}
			this->data[idx] = data;
		}
		T pop() {
			if (this->size == 0) return NULL;
			int item = this->data[1];
			int temp = this->data[this->size--];
			int idx = 1;
			int child = 2;	
			while (child <= this->size) {
				if (child+1 <= this->size && this->data[child] > this->data[child+1]) child += 1;
				if (temp < this->data[child]) break;
				this->data[idx] = this->data[child];
				idx = child;
				child = this->getLeftChild(idx);
				if (child == -1) break;
			}	
			this->data[idx] = temp;
			return item;
		}
};
int main() {
	Heap<int> *mHeap = new MinHeap<int>(10);
	mHeap->push(1);
	mHeap->push(4);
	mHeap->push(8);
	mHeap->push(9);
	mHeap->push(7);
	mHeap->push(2);
	mHeap->push(3);
	mHeap->push(6);
	mHeap->push(5);
	mHeap->push(10);


	for (int i = 0; i < 10; i++) {
		cout << mHeap->pop() << endl;
	}
	delete mHeap;
	return 0;
}
