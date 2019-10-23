/*
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
Input: 3 -) 5 -) 8 -) 5 -) 10 -) 2 -) 1 [partition = 5]
Output: 3 -) 1 -) 2 -) 10 -) 5 -) 5 -) 8
*/

#include <iostream>
#include <algorithm>
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




bool partition(int x, ListNode * head)
{
	ListNode * current = head;
	if (current == nullptr)
		return false;
	while (current != nullptr && current->data < x)
	{
		current = current->nextPtr;
	}
	if (current != nullptr)
	{
		ListNode * runner = current;
		while (runner != nullptr)
		{
			if (runner->data < x)
			{
				int tmp = runner->data;
				runner->data = current->data;
				current->data = tmp;
				current = current->nextPtr;
			}
			runner = runner->nextPtr;

		}

	}
	return true;

}

ListNode * partition2(int x, ListNode * input)
{
	ListNode * head = nullptr;
	ListNode * tail = nullptr;

	ListNode * current = input;

	while (current != nullptr )
	{
		ListNode * newNode = new ListNode(current->data);
		if (current->data < x)
		{
			if (head == nullptr)
				head = tail = newNode;
			else
			{
				newNode->nextPtr = head;
				head = newNode;
			}

		}
		else
		{
			if (head == nullptr)
				head = tail = newNode;
			else
			{
				tail->nextPtr = newNode;
				tail = newNode;
			}

		}
		current = current->nextPtr;
	}
	
	return head;
}

int main()
{
	ListNode * head = new ListNode(3);
	head->nextPtr = new ListNode(5);
	head->nextPtr->nextPtr = new ListNode(8);
	head->nextPtr->nextPtr->nextPtr = new ListNode(5);
	head->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(10);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(2);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(1);

	ListNode * input = head;

	while (input != nullptr)
	{
		cout << input->data << " -> ";
		input = input->nextPtr;
	}
	cout << " nullptr " << endl;


	cout << "_______________2________________" << endl;
	input = partition2(5, head);
	while (input != nullptr)
	{
		cout << input->data << " -> ";
		input = input->nextPtr;
	}
	cout << " nullptr " << endl;

	cout << "________________3_______________" << endl;
	if (partition(5, head))
	{
		input = head;

		while (input != nullptr)
		{
			cout << input->data << " -> ";
			input = input->nextPtr;
		}
		cout << " nullptr " << endl;

	}

	

	return 0;
}
