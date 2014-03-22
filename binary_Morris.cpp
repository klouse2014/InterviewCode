void bst_morris_inorder(struct bst_node *root)  {  
   struct bst_node *p = root, *tmp;
   while (p) {  
       if (p->left == NULL) {  
           printf("%d ", p->key);  
           p = p->right;  
       }  
       else {  
           tmp = p->left;  
           while (tmp->right != NULL && tmp->right != p)  
               tmp = tmp->right;  
           if (tmp->right == NULL) {  
               tmp->right = p;  
               p = p->left;  
           }  
           else {  
               printf("%d ", p->key);  
               tmp->right = NULL;  
               p = p->right;  
           }  
       }  
   }  
}  
