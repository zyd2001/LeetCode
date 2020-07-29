#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> arr;
    int size;
    int head;
    int tail;
    int k;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : arr(k, 0), k(k), size(0), tail(-1), head(0) {}

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        else
        {
            size++;
            tail = (tail + 1) % k;
            arr[tail] = value;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;
        else
        {
            size--;
            head = (head + 1) % k;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[head];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return k == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    MyCircularQueue circularQueue(3); // set the size to be 3
    circularQueue.enQueue(2);  // return true
    circularQueue.Rear();  // return 3
    circularQueue.Front();  // return true
    circularQueue.deQueue();  // return true
    circularQueue.enQueue(5);  // return true
    circularQueue.Rear();  // return 3
    circularQueue.deQueue();  // return true
    circularQueue.Front();  // return true
    circularQueue.enQueue(4);  // return false, the queue is full
    circularQueue.deQueue();  // return true
    circularQueue.deQueue();  // return true
    circularQueue.deQueue();  // return true
}