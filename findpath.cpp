#include "iostream"
#include "list"
using namespace std;

bool GetNodePath(BinaryTreeNode * pRoot, BinaryTreeNode * pNode, list<BinaryTreeNode *> & path)  
{  
    if(pRoot == pNode)  
    {     
        path.push_back(pRoot);  
        return true;  
    }  
    if(pRoot == NULL)  
        return false;  
    path.push_back(pRoot);  
    bool found = false;  
    found = GetNodePath(pRoot->m_pLeft, pNode, path);  
    if(!found)  
        found = GetNodePath(pRoot->m_pRight, pNode, path);  
    if(!found)  
        path.pop_back();  
    return found;  
}  


BinaryTreeNode * GetLastCommonParent(BinaryTreeNode * pRoot, BinaryTreeNode * pNode1, BinaryTreeNode * pNode2)  
{  
    if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL)  
        return NULL;  
    list<BinaryTreeNode*> path1;  
    bool bResult1 = GetNodePath(pRoot, pNode1, path1);  
    list<BinaryTreeNode*> path2;  
    bool bResult2 = GetNodePath(pRoot, pNode2, path2);  
    if(!bResult1 || !bResult2)   
        return NULL;  
    BinaryTreeNode * pLast = NULL;  
    list<BinaryTreeNode*>::const_iterator iter1 = path1.begin();  
    list<BinaryTreeNode*>::const_iterator iter2 = path2.begin();  
    while(iter1 != path1.end() && iter2 != path2.end())  
    {  
        if(*iter1 == *iter2)  
            pLast = *iter1;  
        else  
            break;  
        iter1++;  
        iter2++;  
    }  
    return pLast;  
}  
