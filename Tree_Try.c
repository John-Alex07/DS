#include <stdio.h>
#include <stdlib.h>
typedef struct TREE
{
    int data;
    struct TREE *left;
    struct TREE *right;
}Node;
Node *tempor(int n)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int menu()
{
      int ch;
      printf("Enter -1 to create a LEFT BRANCH\n");
      printf("Enter 1 to create a RIGHT BRANCH\n");
      printf("Enter 2 for both\n");
      printf("Enter 0 to STOP\n");
      scanf("%d",&ch);      
      return ch;
}
Node *Tree(Node *root)
{
    int ch;
    int i = 2;
   do
   {
       Node *t = root;
       ch=menu();
     switch(ch)
     {
         case 1:
          t->right = tempor(i);
          t = t->right;
         break;
         case -1:
         t->left = tempor(i);
         t = t->left;
         break;
         case 2:
         t->right = tempor(i);
         t->left = tempor(i);
         printf("Enter -1 to EXTEND LEFT\n");
         printf("ANY NUMBER to EXTEND RIGHT\n");
         int c;
         scanf("%d",&c);
         if(c == -1)
         t = t->left;
         else
         t = t->right;
         break;
         default:
         printf("INVALID INPUT\n");
     }
     i++;
   }while(ch);
   return root;
}
void postorder(Node *root)
{
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = tempor(1);
    printf("ROOT CREATED\n");
    Tree(root);
    postorder(root);
}
