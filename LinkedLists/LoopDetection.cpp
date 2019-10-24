/*
Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C - > D -> E -> C [the same C as earlier)
Output: C
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int val)
		:data(val),nextPtr(nullptr)
	{}

	int data;
	ListNode * nextPtr;

};


ListNode * detectLoop(ListNode * cirList)
{
	ListNode * slow = cirList;
	ListNode * fast = cirList;

	while (fast != nullptr && fast->nextPtr != nullptr)
	{
		slow = slow->nextPtr;
		fast = fast->nextPtr->nextPtr;

		if (slow == fast)
			break;
	}


	if (fast == nullptr || fast->nextPtr == nullptr)
		return false;

	slow = cirList;
	while (slow != fast)
	{
		slow = slow->nextPtr;
		fast = fast->nextPtr;
	}

	return slow;
}

int main()
{
	ListNode * head = new ListNode(1);
	head->nextPtr = new ListNode(2);
	head->nextPtr->nextPtr = new ListNode(3);
	head->nextPtr->nextPtr->nextPtr = new ListNode(4);
	head->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(5);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = head->nextPtr->nextPtr;
	
	ListNode * output = detectLoop(head);
	if (output)
		cout << output->data << endl;



}
