#include "iostream"
using namespace std;

//KMP
void Next(char *str, int *next, int len)
{
	int i=0, j=-1;
	next[0] = -1;
	while(i<len)
	{
		if(j==-1 || str[i]==str[j])
		{
			i++;
			j++;
			//next[i] = j;
			if(str[i] != str[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
		{
			j = next[j];
		}
	}
}

int kmp(char *str, char *str_r, int len, int len_r)
{
	int *next = new int[len_r];
	Next(str_r, next, len_r);
	int i=0, j=0;
	while(i<len && j<len_r)
	{
		if(str[i]==str_r[j] || j==-1)
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if(j<len_r-1)
		return -1;
	else
		return i-len_r+1;
}


//trieTree
const int Max = 26;
struct trieNode
{
	int count;
	bool is_end;
	trieNode* next[Max];
	trieNode()
	{
		count = 1;
		for(int i=0;i<Max;i++)
			next[i] = NULL;
	}
};

void insert(trieNode* &root, char *str)
{
	int i=0;
	if(root==NULL)
		root = new trieNode;
	trieNode *p = root;
	while(str[i] != '\0')
	{
		int index = str[i]-'a';
		if(p->next[index] == NULL)
			p->next[index] = new trieNode;
		else
			p->next[index]->count++;
		p = p->next[index];
		i++;
	}
}

bool find(trieNode *root, char *str)
{
	if(root == NULL)
		return false;
	int i=0;
	int index;
	trieNode *p = root;
	while(str[i] != '\0')
	{
		index = str[i] - 'a';
		if(p->next[index] == NULL)
			return false;
		else
			p = p->next[index];
		i++;
	}
	return true;
}

void pre_str(trieNode *root)
{
	if(root==NULL)
		return;
	trieNode *p = root;
	for(int i=0;i<Max;i++)
	{
		if(root->next[i] != NULL)
		{
			if(root->next[i]->count > 1)
			{
				cout<<char(i+'a');
				pre_str(root->next[i]);
			}
			if(root->next[i]->count ==1)
				cout<<endl;
		}
	}
}



int main()
{
//	char str[] = {'a', 'b', 'a', 'b', 'c'};
//	char str1[] = {'a', 'b', 'a'};
//	cout<<kmp(str, str1, 5, 3)<<endl;
	
	char str[10] = {0};
	char str1[10] = {0};

	trieNode *root = NULL;
	cin>>str;
	cin>>str1;
	insert(root, str);
	insert(root, str1);
	cout<<find(root, "abc")<<endl;
	cout<<find(root, "asdfg")<<endl;
	pre_str(root);
	return 0;
}








