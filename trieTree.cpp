#include "iostream"
using namespace std;

struct node 
{
    int count;
    node* next[26];
    node()
    {
        count=0;
        for (int i=0;i<26;i++)
            next[i] = NULL;
    }
};

void insert(node* &root, char *s)
{
    if (root ==NULL)
        return;
    node* temp = root;
    for (int i=0; s[i]; i++)
    {
        int x = s[i] - 'a';
        if (temp->next[x]==NULL)
        {
            temp->next[x] = new node;
        }
        temp = temp->next[x];
    }
    temp->count++;
}

int search(node* root, char *s)
{
    if(root==NULL)
        return 0;
    node* temp = root;
    for(int i=0; s[i]; i++)
    {
        int x = s[i] - 'a';
        if(temp->next[x] != NULL)
            temp = temp->next[x];
        else
            return 0;
    }
    return temp->count;
}



int main()
{
    node *root = new node;
    insert(root, "a");
    insert(root, "abc");
    insert(root, "abcde");
    insert(root, "abcde");
    cout<<search(root, "ab")<<endl;
    cout<<search(root, "abcde")<<endl;
    return 0;

}
