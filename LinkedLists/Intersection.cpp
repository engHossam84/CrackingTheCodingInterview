/*
Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting

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

	int data;
	ListNode * nextPtr;

};

int length(ListNode * l1)
{
	if (l1 == nullptr)
		return 0;
	return 1 + length(l1->nextPtr);
}

void padList(ListNode ** li, int len)
{
	for (int i = 0; i < len; ++i)
	{
		ListNode * newNode = new ListNode(0);
		newNode->nextPtr = *li;
		*li = newNode;
	}
}

bool intersection(ListNode * l1, ListNode * l2, ListNode * &output)
{
	if (l1 == nullptr && l2 == nullptr)
		return false;

	intersection(l1 ? l1->nextPtr : nullptr, l2 ? l2->nextPtr : nullptr, output);
	if (l1 == l2)
	{
		output = l1;
	}

	return true;
}

void checkIntersect(ListNode * l1, ListNode * l2, ListNode * &output)
{
	int len1 = length(l1);
	int len2 = length(l2);

	if (len1 > len2)
		padList(&l2, len1 - len2);
	else if(len2 > len1)
		padList(&l1, len2 - len1);

	intersection(l1, l2, output);

}



int main()
{
	ListNode * head = new ListNode(3);
	head->nextPtr = new ListNode(1);
	head->nextPtr->nextPtr = new ListNode(5);
	head->nextPtr->nextPtr->nextPtr = new ListNode(9);
	head->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(7);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(2);
	head->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = new ListNode(1);

	ListNode * head2 = new ListNode(4);
	head2->nextPtr = new ListNode(6);
	head2->nextPtr->nextPtr = head->nextPtr->nextPtr->nextPtr->nextPtr;

	ListNode * output = nullptr;

	checkIntersect(head, head2, output);
	if (output != nullptr)
	{
		cout << output->data << endl;
	}
}
	
