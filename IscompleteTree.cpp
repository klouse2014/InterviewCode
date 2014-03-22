bool IsCompleteBinaryTree(BinaryTreeNode * pRoot)  
{  
    if(pRoot == NULL)  
        return false;  
    queue<BinaryTreeNode *> q;  
    q.push(pRoot);  
    bool mustHaveNoChild = false;  
    bool result = true;  
    while(!q.empty())  
    {  
        BinaryTreeNode * pNode = q.front();  
        q.pop();  
        if(mustHaveNoChild) // 已经出现了有空子树的节点了，后面出现的必须为叶节点（左右子树都为空）  
        {  
            if(pNode->m_pLeft != NULL || pNode->m_pRight != NULL)  
            {  
                result = false;  
                break;  
            }  
        }  
        else  
        {  
            if(pNode->m_pLeft != NULL && pNode->m_pRight != NULL)  
            {  
                q.push(pNode->m_pLeft);  
                q.push(pNode->m_pRight);  
            }  
            else if(pNode->m_pLeft != NULL && pNode->m_pRight == NULL)  
            {  
                mustHaveNoChild = true;  
                q.push(pNode->m_pLeft);  
            }  
            else if(pNode->m_pLeft == NULL && pNode->m_pRight != NULL)  
            {  
                result = false;  
                break;  
            }  
            else  
            {  
                mustHaveNoChild = true;  
            }  
        }  
    }  
    return result;  
}  
