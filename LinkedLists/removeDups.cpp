/*
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/
#include <unordered_set>
#include <iostream>
using namespace std;


class ListNode
{
public:
	explicit ListNode(int val)
		:data(val), nextPtr(nullptr)
	{

	}

	int gatData() const
	{
		return data;
	}

	int data;
	ListNode * nextPtr;

};


ListNode * RemoveDups(ListNode* head)
{
	unordered_set<int> nodeSet;
	ListNode* current = head;

	if (current != nullptr)
		nodeSet.insert(current->gatData());

	while (current != nullptr && current->nextPtr != nullptr)
	{
		int elem = current->nextPtr->gatData();
		if (nodeSet.find(elem) == nodeSet.end())
		{
			nodeSet.insert(elem);
			
		}
		else
		{
			ListNode* tmp = current->nextPtr;
			current->nextPtr = tmp->nextPtr;
			tmp->nextPtr = nullptr;
			delete tmp;
		}
		current = current->nextPtr;
	}

	return head;
}

ListNode * RemoveDups2(ListNode* head)
{
	ListNode* current = head;
	while (current != nullptr)
	{
		ListNode* runner = current;
		while (runner->nextPtr != nullptr)
		{
			if (current->data == runner->nextPtr->data)
			{
				ListNode* tmp = runner->nextPtr;
				runner->nextPtr = tmp->nextPtr;
				tmp->nextPtr = nullptr;
				delete tmp;
			}
			else
			{
				runner = runner->nextPtr;
			}
		}
		current = current->nextPtr;

	}
	return head;
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

	ListNode * output = RemoveDups2(head);

	while (output != nullptr)
	{
		cout << output->data << " -> ";
		output = output->nextPtr;
	}
	cout << " nullptr " << endl;
}
