#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Tree;
int num()
{
    int n;
    printf("Enter a NUMBER to be Inserted\n");
    scanf("%d",&n);
    return n;
}
Tree *Leaf(int n)
{
  
   Tree *Node = (Tree*)malloc(sizeof(Tree));
   Node->data = n;
   Node->left = NULL;
   Node->right = NULL;
   return Node;
}
Tree *Plant(Tree *root,int n)
{
    if(root == NULL)
        {
            root = Leaf(n);
            return root;
        }
    else
    if(root->data <= n)
       root->right = Plant(root->right,n);
    else
       root->left = Plant(root->left,n);
    return root;
}
void climbing(Tree *root)
{
    if(root == NULL)
      return;
    printf("%d ",root->data);
    climbing(root->left);
    climbing(root->right);
}
int main()
{
    Tree *seed = NULL;
    int numb;
    printf("Enter the number of Nodes in the tree\n");
    scanf("%d",&numb);

    for(int i = 0;i<numb;i++)
    {
      int n = num();
      seed = Plant(seed,n);
    }
    climbing(seed);
}