#include <iostream>
using namespace std;
class Queue
{
private:
    int front, end;
    int *arr, size;

public:
    Queue(int s){
        size = s;
        front = -1;
        end = -1;
        arr = new int[size];
        cout << "Queue Created\n";
    }
    ~Queue(){
        front = (end = -1);
        size = 0;
        delete arr;
        cout << "Queue Destroyed\n";
    }
    void enqueue(int element);
    int dequeue();
    void display();
    bool isEmpty();
    bool isFull();
};
void Queue::enqueue(int element){
    if (isFull()){
        cout << "Queue Full\n";
    }
    else{
        if (front == -1)
            front++;
        arr[(++end) % size] = element;
        cout << "Enqueued : " << arr[end % size] << endl;
    }
}
int Queue::dequeue()
{
    if (isEmpty()){
        cout << "Queue Empty";
        return -1;
    }
    else{
        int temp = front;
        if (front == end)
            front = (end = -1);
        else
            ++front;
        return arr[temp % size];
    }
}
void Queue::display(){
    if (isEmpty()){
        cout << "Queue Empty\n";
        return;
    }
    cout << "Front at ::" << front % size;
    cout << "\nDATA :: ";
    for (int i = front; i <= end; i++){
        cout << arr[i % size] << "\t";
    }
    cout << "\nRear at::" << end % size << endl;
}
bool Queue::isEmpty(){
    return (front == -1 && end == -1);
}
bool Queue::isFull(){
    return ((end - front) == size);
}
int main(){
    int s, ui;
    cout << "Enter the size of the queue\n";
    cin >> ui;
    Queue q(ui);
    cout << "Enter the elements of the queue\n";
    for (int i = 0; i < ui; i++){
        cout << "Enter element:\n";
        cin >> s;
        q.enqueue(s);
    }
    q.display();
    cout << "Dequeue\t" << q.dequeue() << endl;
    cout << "Dequeue\t" << q.dequeue() << endl;
    q.display();
    q.enqueue(3);
    q.enqueue(2);
    q.display();

    return 0;
}