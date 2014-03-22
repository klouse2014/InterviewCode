#include "iostream"
#include "stack"
using namespace std;
 
struct Node
{
    char m_str;
    Node* left;
    Node* right;
    Node(char s, Node* leftnode=NULL, Node* rightnode=NULL):m_str(s),left(leftnode),right(rightnode){}
};

void insert(Node* &root)
{
    char s;
    cin>>s;
    if(s=='#')
        return;
    else
    {
        root = new Node(s);
        insert(root->left);
        insert(root->right);
    }
}

void convert(Node *root, Node* &first, Node* &last)
{
    stack<Node* > stk;
    Node* p = root;
    Node* pre = NULL;
    while(p!=NULL || !stk.empty())
    {
        while(p != NULL)
        {
            stk.push(p);
            p = p->left;
        }
        if(!stk.empty())
        {
            p = stk.top();
            stk.pop();
            if(pre == NULL)
                first = p;
            if(pre != NULL)
            {
                p-> left = pre;
                pre->right = p;
            }
            pre = p;
            p = p->right;
        }
    }
    last = pre;
}

int main()
{
    Node *root, *first, *last;
    insert(root);

    convert(root, first, last);
    while(first != NULL)
    {
        cout<<first->m_str<<" ";
        first = first -> right;
    }
    cout<<endl;
    while(last != NULL)
    {
        cout<<last->m_str<<" ";
        last = last -> left;
    }
    cout<<endl;

    return 0;
}

