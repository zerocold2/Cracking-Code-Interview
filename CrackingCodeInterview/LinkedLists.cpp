#include "Main.h"


struct Node {

	int Data;
	Node* Next;
};

class LinkedLists
{
	Node* Head = NULL;
public:
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
		while (Head->Next != NULL)
		{
			cout << Head->Data << " ";
			Head = Head->Next;
		}
		cout << Head->Data << endl;
	}
	void Delete(Node* prev, Node* del) {
		if (del->Next == NULL)
			prev->Next = NULL;
		else prev->Next = del->Next;

	}

	void RemoveDublicate(Node* Head) {
		Node *curr = Head, *Nex = Head;
		//while (Head->)
	}
};