#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* Next;
	Node* Prev;
};

void Insert_At_The_Beg(Node*& Head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->Next = temp;
	temp->Prev = temp;
	if (Head == NULL)
	{
		Head = temp;
		return;
	}
	Node* P = Head->Prev;
	P->Next = temp;
	temp->Next = Head;
	Head->Prev = temp;
	temp->Prev = P;
	Head = temp;
}
void Inset_At_The_End(Node*& Head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->Next = temp;
	temp->Prev = temp;
	if (Head == NULL)
	{
		Head = temp;
		return;
	}
	Node* P = Head->Prev;
	P->Next = temp;
	temp->Prev = P;
	Head->Prev = temp;
	temp->Next = Head;
}
void Insert_In_TheSpecific_Position(Node*& Head,int data,int Position)
{
	if (Position == 1)
	{
		Insert_At_The_Beg(Head, data);
		return;
	}
	Node* P = Head;
	for (int i = 1; i < Position - 1; i++)
	{
		P = P->Next;
		if (P == Head)
		{
			cout << "OUT OF RANGE";
			return;
		}
	}
	if (P->Next == Head)
	{
		Inset_At_The_End(Head, data);
		return;
	}
	else {
		Node* temp = new Node();
		temp->data = data;
		temp->Next = temp;
		temp->Prev = temp;
		Node* Q = P->Next;
		P->Next = temp;
		temp->Prev = P;
		temp->Next = Q;
		Q->Prev = temp;
	}
}
void SearchMAX(Node* Head,int data)
{
	if (Head == NULL)
	{
		cout << "LinkedList Is Empty";
		return;
	}
	Node* N = Head;
	int MAX = Head->data;
	do {
		if (N->data > MAX)
		{
			MAX = N->data;
		}
		N = N->Next;
	} while (N != Head);
	Node* P = Head;
	do {
		if (P->data == MAX)
		{
			break;
		}
		P = P->Next;
	} while (P != Head);
	if (P->data == MAX)
	{
		cout << "Found";
	}
	else {
		cout << "NOT Found";
	}

}






void Search(Node*& Head, int data)
{
	if (Head == NULL)
	{
		cout << "The Linked List Is Empty!";
		return;
	}
	Node* P = Head;
	do {
		if (P->data == data)
		{
			cout << "We Can Found the Number " << data<<endl;
			return;
		}
		P = P->Next;
	} while (P != Head );
	if (P == Head)
	{
		cout << "We Cannot Found " << data << endl;
	}
}
void SearchMAX(Node* Head, int data)
{

	if (Head == NULL)
	{
		cout << "Empty";
		return;
	}
	Node* S = Head;
	int MAX = Head->data;
	do {
		if (S->data > MAX)
		{
			MAX = S->data;
		}
		S = S->Next;
	} while (S != Head);
		Node* P = Head;
		do {
			if (P->data == MAX)
			{
				break;
			}
			P = P->Next;
		} while (P != Head);
		if (P->data == MAX)
		{
			cout << "Found";
		}
		else {
			cout << "Not Found";
		}
}

void DeleteNodeMAX(Node*& Head,int data) {
	if (Head == NULL)
	{
		cout << "Empty";
		return;
	}
	Node* N = Head;
	int MAX = N->data;
	do {
		if (N->data > MAX)
		{
			MAX = N->data;
		}
		N = N->Next;
	} while (N != Head);

	Node* P = Head;
	do {
		if (P->data == MAX)
		{
			break;
		}
		P = P->Next;

	} while (P != Head);
	if (P == Head)
	{
		Head = Head->Next;
		Node* q = Head->Prev;
		Head->Prev = q;
		q->Next = Head;
		delete P;
	}
	else {
		Node* q = P->Prev;
		q->Next = P->Next;
		q = P->Next;
		q->Prev = P->Prev;
		delete P;
	}
}


void  DeleteMINData(Node*& Head, int data)
{
	if (Head == NULL)
	{
		cout << "Empty!";
		return;
	}
	Node* N = Head;
	int MIN = Head->data;
	do {
		if (N->data < MIN)
		{
			MIN = N->data;
		}
		N = N->Next;
	} while (N != Head);
	Node* P = Head;
	do {
		if (P->data == MIN)
		{
			break;
		}
		P = P->Next;

	} while (P != Head);
	if (P == Head)
	{
		Head = Head->Next;
		Head->Prev = P->Prev;
		P->Prev->Next = Head;
		delete P;
	}
	else 
	{
		P->Prev->Next = P->Next;
		P->Next->Prev = P->Prev;
		delete P;

	}
}



void Delete(Node*& Head, int data)
{
	if (Head == NULL)
	{
		cout << "This LinkedList Is Empty!";
		return;
	}
	Node* P = Head;
	do
	{
		if (P->data == data)
		{
			break;
		}
		P = P->Next;
	} while (P!= Head);
	if (P->data != data )
	{
		cout << "We Cannot Found Number " << data << " To Delete It";
		return;
	}
	if (P == Head && P->Next == Head) {
		delete P;
		Head = NULL;
		cout << "Last Node deleted, List is now empty." << endl;
		return;
	}
	else if (P == Head) {
		cout << "We Found The Number <Head> " << data << " And We Will Delete It";
		Head = Head->Next;
		Node* Q = P->Prev;
		Head->Prev = Q;
		Q->Next = Head;
		delete P;
	}
	else {
		Node* Q = P->Prev;
		Q->Next = P->Next;
		Q = P->Next;
		Q->Prev = P->Prev;
		delete P;
	}
}
void Is_mirror(Node* Head)
{
	if (Head == NULL)
	{
		return ;
	}
	Node* P = Head;
	Node* Q = Head->Prev;
	if ((P->data == Q->data) && P->Next->data == Q->Prev->data)
	{
		cout << "Mirror";
	}
	else {
		cout << "Not Mirror";
	}
}

void Display(Node* Head)
{
	Node* P = Head;
	cout << "Head->";
	do {
		cout <<P->data<<"->";
		P = P->Next;
	} while (P != Head);
	cout << "(Back To Head)"<<endl;
}


int main()
{
	Node* List1 = NULL;
	Inset_At_The_End(List1, 1);
	Inset_At_The_End(List1, 2);
	Inset_At_The_End(List1, 30);
	Inset_At_The_End(List1, 2);
	Inset_At_The_End(List1, 1);
	Display(List1);
	Is_mirror(List1);
}
