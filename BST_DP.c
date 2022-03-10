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
  printf("Enter a NUMBER\n");
  scanf("%d",&n);
  return n;
}
Tree *create(int n)
{
  Tree *Node = (Tree*)malloc(sizeof(Tree));
  Node->data = n;
  Node->left = NULL;
  Node->right = NULL;
  return Node; 
}
Tree *insert(Tree **root, int n)
{
  if(*root == NULL)
        *root = create(n);
  else
   if(n >= (*root)->data)
       insert(&(*root)->left,n);
  else
       insert(&(*root)->right,n);
    return *root;
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
    insert(&seed,num());
    insert(&seed,num());
    insert(&seed,num());

    climbing(seed);
}