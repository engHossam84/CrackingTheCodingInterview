/*
Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .Thatis,617 + 295.
Output: 2 - > 1 - > 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
Output: 9 - > 1 - > 2. That is, 912.
*/

#include <iostream>
using namespace std;

class ListNode {
	friend class LinkedList;
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

class LinkedList
{
public:
	LinkedList()
		:head(nullptr), tail(nullptr)
	{

	}

	void insertAtBack(int val)
	{
		ListNode * newNode = new ListNode(val);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->nextPtr = newNode;
			tail = newNode;
		}
	}

	void insertAtFront(int val)
	{
		ListNode * newNode = new ListNode(val);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->nextPtr = head;
			head = newNode;
		}
	}

	ListNode * head;
	ListNode * tail;

};


int length(ListNode * li)
{
	if (li == nullptr)
		return 0;
	return 1 + length(li->nextPtr);
}

void padList(ListNode * li, int len)
{
	for (int i = 0; i < len; i++)
	{
		ListNode * newNode = new ListNode(0);
		newNode->nextPtr = li;
		li = newNode;
	}
}

int sumListHelper(ListNode * l1, ListNode * l2, int &carry, int & sum, LinkedList * output)
{
	if (l1 == nullptr && l2 == nullptr)
		return 0;

	sumListHelper(l1 ? l1->nextPtr : nullptr, l2 ? l2->nextPtr : nullptr, carry, sum, output);
	if (l1 != nullptr)
		sum = l1->data;

	if (l2 != nullptr)
		sum += l2->data;

	if (carry == 1)
		sum += carry;

	output->insertAtFront(sum % 10);
	carry = sum / 10;

	return sum;





}

LinkedList * sumList2(ListNode * l1, ListNode * l2)
{
	int len1 = length(l1);
	int len2 = length(l2);
	int sum = 0; 
	int carry = 0;
	LinkedList * output = new LinkedList();

	if (len1 > len2)
		padList(l2, len1 - len2);
	else if(len2 > len1)
		padList(l2, len1 - len2);

	sumListHelper(l1, l2,carry, sum, output);

	if (carry == 1)
		output->insertAtFront(1);

	return output;

}

LinkedList * sumList(ListNode * l1, ListNode * l2)
{
	int carry = 0;
	int sum = 0;
	LinkedList * output = new LinkedList();
	while (l1 != nullptr || l2 != nullptr)
	{
		if (l1 != nullptr && l2 != nullptr)
		{
			sum = sum + l1->data + l2->data + carry;
			l1 = l1->nextPtr;
			l2 = l2->nextPtr;
		}
		else if (l1 != nullptr)
		{
			sum = sum + l1->data +  carry;
			l1 = l1->nextPtr;
		}
		else
		{
			sum = sum  + l2->data + carry;
			l2 = l2->nextPtr;
		}

		if (sum > 10)
		{
			carry = 1;
			sum = sum - 10;
		}
		else
		{
			carry = 0;
		}
		output->insertAtBack(sum);
		sum = 0;
	}
	if(carry == 1)
		output->insertAtBack(carry);

	return output;
}

/*
Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .Thatis,617 + 295.
Output: 2 - > 1 - > 9. That is, 912.*/
int main()
{
	ListNode * l1 = new ListNode(7);
	l1->nextPtr = new ListNode(1);
	l1->nextPtr->nextPtr = new ListNode(6);

	ListNode * l2 = new ListNode(5);
	l2->nextPtr = new ListNode(9);
	l2->nextPtr->nextPtr = new ListNode(2);

	

	LinkedList * output = sumList(l1, l2);

	ListNode * input = output->head;

	while (input != nullptr)
	{
		cout << input->data << " -> ";
		input = input->nextPtr;
	}
	cout << " nullptr " << endl;

	/*
	Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
Output: 9 - > 1 - > 2. That is, 912.
	*/

	ListNode * ll1 = new ListNode(6);
	ll1->nextPtr = new ListNode(1);
	ll1->nextPtr->nextPtr = new ListNode(7);

	ListNode * ll2 = new ListNode(2);
	ll2->nextPtr = new ListNode(9);
	ll2->nextPtr->nextPtr = new ListNode(5);

	LinkedList * output2 = sumList2(ll1, ll2);

	ListNode * input2 = output2->head;

	while (input2 != nullptr)
	{
		cout << input2->data << " -> ";
		input2 = input2->nextPtr;
	}
	cout << " nullptr " << endl;
}
