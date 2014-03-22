#include<iostream>
#include<queue>
using namespace std;

struct huffman_node
{
	char str;
	double fre;
	int symbol;
	huffman_node *left;
	huffman_node *right;
	huffman_node *parent;
	
	huffman_node(char string, double frequce):str(string),fre(frequce)
	{
		symbol = -1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

struct cmp
{
	bool operator() (huffman_node* &node1, huffman_node* &node2)
	{
		return node1->fre > node2->fre;
	}
};

huffman_node* createHuffman(huffman_node* array[], int len)
{
	priority_queue<huffman_node*, vector<huffman_node *>, cmp> queue(array, array+len);
	huffman_node *head = NULL;
	while(queue.size()>1)
	{
		huffman_node *first = queue.top();
		queue.pop();
		huffman_node *second = queue.top();
		queue.pop();
		head = new huffman_node('#', first->fre + second->fre);
		
		head->left = first;
		first->parent = head;
		first->symbol = 0;
		head->right = second;
		second->parent = head;
		second->symbol = 1;
		queue.push(head);
	}
	return head;
}
		
void print(huffman_node *root)
{
	if(root != NULL)
	{
		cout<<root->fre<<" ";
		print(root->left);
		print(root->right);
	}
}


int main()
{
	huffman_node *node1 = new huffman_node('a',0.2);
	huffman_node *node2 = new huffman_node('b',0.4);
	huffman_node *node3 = new huffman_node('c',0.3);
	
	huffman_node* a[3] = {node1, node2, node3};
	huffman_node* root = createHuffman(a, 3);
	
	print(root);
	return 0;
	
    
}