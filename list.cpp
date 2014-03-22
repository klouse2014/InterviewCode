#include "iostream"
using namespace std;

struct Node
{
	int m_value;
	Node *next;
};

void insert(Node* &head, int value)
{
	if(head == NULL)
	{
		head = new Node;
		head->m_value = value;
		head->next = NULL;
	}
	else
	{
		insert(head->next, value);
	}
}

void print(Node* head)
{
	Node* p = head;
	while(p != NULL)
	{
		cout<<p->m_value<<" ";
		p = p->next;
	}
	cout<<endl;
}

Node* reverse(Node* head)
{
	Node *p = head;
	Node *q = p->next;
	Node *r = q->next;
	p->next = NULL;
	while(r != NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	return q;
}

Node* merge(Node* head1, Node* head2)
{
	Node *p, *q;
	if(head1->m_value > head2->m_value)
	{
		p = head1;
		head1 = head1->next;
	}
	else
	{
		p = head2;
		head2 = head2->next;
	}
	q = p;

	while(head1 != NULL && head2 != NULL)
	{
		if(head1->m_value > head2->m_value)
		{
			p->next = head1;
			p = p->next;
			head1 = head1->next;
		}
		else
		{
			p->next = head2;
			p = p->next;
			head2 = head2->next;
		}
	}
	if(head1 != NULL)
		p->next = head1;
	else
		p->next = head2;
	
	return q;
}

void midNode(Node *head)
{
	Node *p, *q;
	p = q = head;
	while(q->next != NULL && q->next->next != NULL)
	{
		p = p->next;
		q = q->next->next;
	}
	cout<< p->m_value<<endl;
}

bool hasCircle(Node *head)
{
	Node *p = head;
	Node *q = head->next;
	while(q)
	{
		p = p->next;
		q = q->next;
		if(q==NULL)
			break;
		q = q->next;
		if(p = q)
			return true;
	}
	if(q==NULL)
		return false;
}

int removeNode(Node *node)
{
	Node *p = node->next;
	int temp = node->m_value;
	node->m_value = p->m_value;
	node->next = p->next;
	delete p;
	return temp;
}
	



int main()
{
	Node *head = NULL;
	Node *head1 = NULL;
	int x,y;
	cin>>x;
	while(x!=-999)
	{
		insert(head, x);
		cin>>x;
	}
	print(head);
	midNode(head);
	removeNode(head);
	print(head);
	return 0;
}
	
