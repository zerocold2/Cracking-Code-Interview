#include "Main.h"


struct Node {

	int Data;
	Node* Next;
};

class LinkedLists
{
public:
	Node* Head = NULL;
	LinkedLists(int d) {
		Head = new Node;
		Head->Data = d;
		Head->Next = NULL;
	}
	void Add(int d) {
		Node* end = new Node;
		end->Data = d;
		end->Next = NULL;
		Node* n = Head;
		while (n->Next != NULL)n = n->Next;
		n->Next = end;
	}
	void Print() {
		Node* i = Head;
		while (i->Next != NULL)
		{
			cout << i->Data << " ";
			i = i->Next;
		}
		cout << i->Data << endl;
	}
	void Delete(Node* prev, Node* del) {
		if (del->Next == NULL)
			prev->Next = NULL;
		else prev->Next = del->Next;

	}
	void Sort() {
		MergeSort(&Head);
	}
	void RemoveDublicate(Node* Head) {
		Node *curr = Head, *Nex = Head;
		//while (Head->)
	}
private:
	int Length(Node* linkedList) {
		int ret = 1;
		while (linkedList->Next != NULL) { ret++;linkedList = linkedList->Next; }
	}
	/*
	MergeSort(headRef)
	1) If head is NULL or there is only one element in the Linked List
		then return.
	2) Else divide the linked list into two halves.
		FrontBackSplit(head, &a, &b);  a and b are two halves
	3) Sort the two halves a and b.
		MergeSort(a);
		MergeSort(b);
	4) Merge the sorted a and b(using SortedMerge() discussed here)
		and update the head pointer using headRef.
		headRef = SortedMerge(a, b);
	*/
	void FrontBackSplit(Node* source, Node** l, Node** r) {
		Node* slow = source;
		Node* fast = source->Next;
		//Advance slow one and advance fast two.
		while (fast != NULL) {
			fast = fast->Next;
			if (fast != NULL) {
				fast = fast->Next;
				slow = slow->Next;
			}
		}

		//Now fast and the end of the list and slow is before the midpoint
		*l = source;
		*r = slow->Next;
		slow->Next = NULL;
	}
	Node* SortedMerge(Node* l, Node* r) {
		Node* ret = NULL;
		//Base Case
		if (l == NULL)return r;
		if (r == NULL)return l;
		if (l->Data <= r->Data) {
			ret = l;
			ret->Next = SortedMerge(l->Next, r);
		}
		else {
			ret = r;
			ret->Next = SortedMerge(l, r->Next);
		}
		return ret;
	}
	void MergeSort(Node** root) {
		Node* head = *root;
		if (head == NULL || head->Next == NULL) return;
		Node* l;
		Node* r;
		FrontBackSplit(head, &l, &r);
		MergeSort(&l);
		MergeSort(&r);
		*root = SortedMerge(l, r);
	}

};