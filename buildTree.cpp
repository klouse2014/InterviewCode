#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct treeNode
{
    char m_value;
    treeNode *left;
    treeNode *right;
    treeNode(char c, treeNode *m_left = NULL, treeNode *m_right = NULL):m_value(c), left(m_left), right(m_right){}
    
};

void buildTree(treeNode* &root, char *inorder, char *preorder, int len)
{
    if(len==0)
        return;
    char pivot = preorder[0];
    root = new treeNode(pivot);
    
    int i=0;
    while(inorder[i] != pivot)
        i++;
    buildTree(root->left, inorder, preorder+1, i);
    buildTree(root->right, inorder+i+1, preorder+i+1, len-i-1);
    
}

void postorder(treeNode *root)
{
    stack<treeNode *> stk;
    stack<bool> stk_bool;
    treeNode *p = root;
    
    while(p!=NULL || !stk.empty())
    {
        while(p!=NULL)
        {
            stk.push(p);
            stk_bool.push(false);
            p = p->left;
        }
        if(!stk.empty())
        {
            bool temp = stk_bool.top();
            if(temp)
            {
                p = stk.top();
                stk.pop();
                stk_bool.pop();
                cout<< p->m_value;
                p = NULL;
            }
            else
            {
                p = stk.top();
                stk_bool.pop();
                stk_bool.push(true);
                p = p->right;
            }
        }
    }
    
}

int main() {
    // Start typing your code here...
    char inorder[] = "dcfab";
    char preorder[] = "acdfb";
    treeNode *root = NULL;
    buildTree(root, inorder, preorder, strlen(inorder));
    
    postorder(root);
    
    return 0;
}