/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

*/

#include <iostream>
using namespace std;

class ListNode
{
public:
	explicit ListNode(int val)
		:data(val), nextPtr(nullptr)
	{

	}

	int getData() const
	{
		return data;
	}

	int data;
	ListNode * nextPtr;

};

int kthToLast(ListNode * head, int k)
{
	ListNode * current = head;
	int count = k;
	if (current != nullptr)
	{
		ListNode * runner = current;
		while (count > 0)
		{
			if (runner->nextPtr != nullptr)
			{
				runner = runner->nextPtr;
				--count;
			}
			else
				return -1;
			
		}

		while (runner != nullptr)
		{
			runner = runner->nextPtr;
			current = current->nextPtr;
		}
	}

	return current->getData();
}

int kthToLastRec(ListNode * head, int k)
{
	if (head == nullptr)
		return 0;

	int index = kthToLastRec(head->nextPtr, k) + 1;
	if (index == k)
		cout << "output2 = " << head->data;

	return index;
		
}



ListNode * kthToLastRecHelper(ListNode * head, int k, int & i)
{
	if (head == nullptr)
		return nullptr;

	ListNode * node = kthToLastRecHelper(head->nextPtr, k , i) ;
	i = i + 1;
	if (i == k)
		return head;
	return node;
}

ListNode * kthToLastRec2(ListNode * head, int k)
{
	int i = 0;
	return kthToLastRecHelper(head, k, i );

}

int main()
{
	ListNode * head = new ListNode(1);
	head->nextPtr = new ListNode(2);
	head->nextPtr->nextPtr = new ListNode(2);
	head->nextPtr->nextPtr->nextPtr = new ListNode(3);
	head->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(4);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(5);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(5);

	ListNode * input = head;

	while (input != nullptr)
	{
		cout << input->data << " -> ";
		input = input->nextPtr;
	}
	cout << " nullptr " << endl;

	cout << "output1 = " << kthToLast(head, 3) << endl;

	kthToLastRec(head, 3);
		cout << endl;

	cout << "output 3 = " << kthToLastRec2(head, 3)->data << endl;

	return 0;
}
