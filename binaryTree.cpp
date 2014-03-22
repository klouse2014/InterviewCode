#include "iostream"
#include "stdio.h"
#include "stack"
#include "queue"
using namespace std;

struct binaryNode
{
    int m_value;
    binaryNode *left;
    binaryNode *right;
    binaryNode(int value):m_value(value),left(NULL),right(NULL){}
};

void insert(binaryNode* &root, int value)
{
    if(root == NULL)
        root = new binaryNode(value);
    else
    {
        if(value > root->m_value)
            insert(root->right, value);
        else 
            insert(root->left, value);
    }
}


void preorder(binaryNode *root)
{
    binaryNode *p = root;
    stack<binaryNode *> stk;
    stk.push(p);
    while(!stk.empty())
    {
        p = stk.top();
        stk.pop();
        cout<<p->m_value<<" ";
		if(p->right!= NULL)
        	stk.push(p->right);
		if(p->left != NULL)
        	stk.push(p->left);
    }
    cout<<endl;
}

void inorder(binaryNode *root)
{
	binaryNode *p = root;
	stack<binaryNode *> stk;
	while(p!=NULL || !stk.empty())
	{
		while(p!=NULL)
		{
			stk.push(p);
			p = p->left;
		}
		if(!stk.empty())
		{
			p = stk.top();
			stk.pop();
			cout<<p->m_value<<" ";
			p = p->right;
		}
	}
	cout<<endl;
}


void postorder(binaryNode *root)
{
	binaryNode *p = root;
	int pivot;
	stack<binaryNode *> stk;
	stack<int> stk_cmp;

	while(p!=NULL || !stk.empty())
	{
		while(p!=NULL)
		{
			stk.push(p);
			stk_cmp.push(0);
			p = p->left;
		}
		if(!stk.empty())
		{
			p = stk.top();
			pivot = stk_cmp.top();
			if(pivot == 0)
			{
				stk_cmp.pop();
				stk_cmp.push(1);
				p = p->right;
			}
			else
			{
				cout<<p->m_value<<" ";
				stk.pop();
				stk_cmp.pop();
				p = NULL;
			}
		}
	}
	cout<<endl;
}

void levelorder(binaryNode *root)
{
	binaryNode *p = root;
	queue<binaryNode *> Queue;
	Queue.push(p);
	while(!Queue.empty())
	{
		p = Queue.front();
		Queue.pop();
		cout<<p->m_value<<" ";
		if(p->left != NULL)
			Queue.push(p->left);
		if(p->left != NULL)
			Queue.push(p->right);
	}
	cout<<endl;
}


int main()
{
	binaryNode *root = NULL;
	int x;
	while(1==scanf("%d", &x))
		insert(root, x);

	preorder(root);
	inorder(root);
	postorder(root);
	levelorder(root);
	return 0;
}




			
















    


