#include <iostream>
using namespace std;
struct Node
{
	int context;
	Node *next;
};
class Queue
{
public:
	Queue(){head = NULL;}
	void enque(int x);
	void deque();
	void display();
private:
 	Node *head;
};
void Queue::enque(int x)
{
	Node *p = new Node;
 	if (head == NULL){
  		p -> context = x;
		p -> next = NULL;
 		head  = p;
	}
	else{
 		p -> context = x;
  		p -> next = head;
 		head = p;
 	}
}
void Queue::deque()
{
	Node *p = new Node;
	Node *temp = new Node;
	if (head == NULL){
 	cout << "There is nothing to delete.";
 	}
	else{
		if (head -> next = NULL)
			head = NULL;
		else{
 			for (temp = head; temp -> next != NULL; temp = temp -> next)
				p = temp;
			p -> next = NULL;
		}
 	}
}
void Queue::display()
{
	Node *temp = head;
	for (temp = head; temp != NULL; temp = temp -> next)
 	cout << temp -> context << ' ';
	cout << endl;
}

int main()
{
	Queue queue;
	queue.enque(1);
	queue.display();
	queue.enque();
	queue.display();
	queue.enque(3);
	queue.display();
	queue.deque();
	queue.display();
	queue.deque();
	queue.display();
	queue.deque();
	queue.display();
	queue.deque();
	return 0;
}