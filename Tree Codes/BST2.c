#include <stdio.h>

struct node
{
int x;
struct node *right,*left;
}*root=NULL,*temp,*temp1,*temp2;


void create()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data you want to insert :  ");
scanf("%d",&temp->x);
temp->right=NULL;
temp->left=NULL;
}

search_place(struct node *t)
{
if(t->x>temp->x && t->left==NULL)
t->left=temp;
else
if(t->x<temp->x && t->right==NULL)
t->right=temp;
else
if(t->x>temp->x && t->left!=NULL)
search_place(t->left);
else
search_place(t->right);
}

void insert()
{
  char ch;
  do
  {
  create();
  if(root==NULL)
  root=temp;
  else
  search_place(root);

  fflush(stdin);
  printf("\n\nDo you want to continue ?  Y/N : ");
  ch=getch();
 }while((ch=='y')||(ch=='Y'));
}



struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}






struct node* deleteNode(struct node* root, int data)
{
    // base case
    if (root == NULL)
    {
        printf("\n\nEmpty tree or node does'nt exist :(\n\n");
        return root;

    }

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (data < root->x)
        root->left = deleteNode(root->left, data);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (data > root->x)
        root->right = deleteNode(root->right, data);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            printf("\nDeleted element is :  %d  \n\n",root->x);
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            printf("\nDeleted element is :  %d  \n\n",root->x);
            free(root);

            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->x = temp->x;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->x);
    }
    return root;
}



int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}






/*
void delete(struct node *t,int data)
{
 if(t==NULL)
 {
 printf("Tree is empty. :(");
 return;
 }
 if(t->x<data)
 {
 temp1=t;
 delete(t->right,data);
 }
 else
 if(t->x>data)
 {
 temp2=t;
 delete(t->left,data);
 }
 else
 {
   if(t->right==NULL && t->left==NULL)
   {
     if(temp1->right==t)
     {
      temp1->right=NULL;
      printf("Deleted element is : %d ",t->x);
      free(t);
      return;
     }
     else
     {
      temp2->left=NULL;
      printf("Deleted element is : %d ",t->x);
      free(t);
      return;
     }
   }
   else
   if(t->right==NULL && t->left!=NULL)
   {
       if(temp1->right==t)
       {
        temp1->right=t->left;
        printf("Deleted element is : %d ",t->x);
        t->left=NULL;
        free(t);
        return;
       }
       else
       if(temp2->left==t)
       {
        temp2->left=t->left;
        printf("Deleted element is : %d ",t->x);
        t->left=NULL;
        free(t);
        return;
       }
   }
   else
   if(t->left==NULL && t->right!=NULL)
   {
       if(temp1->right==t)
       {
        temp1->right=t->right;
        t->right=NULL;
        printf("Deleted element is : %d ",t->x);
        free(t);
        return;
       }
       else
       if(temp2->left==t)
       {
        temp2->left=t->right;
        printf("Deleted element is : %d ",t->x);
        t->right=NULL;
        free(t);
        return;
       }
   }
   else
   {
    int p;
    struct node *tempx=t->right;

    while(tempx->left!=NULL)
        tempx=tempx->left;
        p=t->x;
        t->x=tempx->x;
        tempx->x=p;
  //    call(p);
        //free()
        delete(root,p);
   }
 }
}
*/

//void call(int p)
//{

  //  delete(root,p);

//}



void preorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }

        printf("%d ", t->x);
    if (t->left != NULL)
        preorder(t->left);
    if (t->right != NULL)
        preorder(t->right);

}



void inorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->left != NULL)
        inorder(t->left);
        printf("%d ", t->x);
    if (t->right != NULL)
        inorder(t->right);
}


void postorder(struct node *t)
{
    if (root == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (t->left != NULL)
        postorder(t->left);
    if (t->right != NULL)
        postorder(t->right);
    printf("%d ", t->x);
}



void mirror(struct node* node)
{
  if (node==NULL)
    return;
  else
  {
    struct node* temp;

    /* do the subtrees */
    mirror(node->left);
    mirror(node->right);

    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}





/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->x);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}



void levelorder(struct node* root)
{
  int h = maxDepth(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}



void reverselevelorder(struct node* root)
{
    int h = maxDepth(root);
    int i;
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printGivenLevel(root, i);
}




int main()
{
 int data;
 char ch;
 int p;
  do
  {
   printf("\n\nEnter you choice below :-\n1.Insert.\n2.Delete.\n3.Display.\n4.Maximum Depth.\n5.Mirror Image.\n\n");
   scanf("%d",&p);
    switch (p)
    {
    case 1:
    insert();
    break;
    case 2:
    printf("Enter the value of the node you want to delete :  ");
    scanf("%d",&data);
    deleteNode(root,data);
    break;
    case 3:
    printf("\n\nPREORDER  :");
    preorder(root);
    printf("\n\nINORDER   :");
    inorder(root);
    printf("\n\nPOSTORDER :");
    postorder(root);
    printf("\n\nLEVELORDER :");
    levelorder(root);
    printf("\n\nREVERSE LEVEL ORDER :");
    reverselevelorder(root);
    break;
    case 4:
    printf("\n\nMaximum depth is :  %d\n\n",maxDepth(root));
    break;
    case 5:
    mirror(root);
    printf("\n\nMirror image done.\nCheck your tree now.\n\n");
    break;
    default:
    printf("Wrong Choice Entered");
    break;
    }
  fflush(stdin);
  printf("\n\nDo you want to do any more Operetion?  Y/N : ");
  ch=getch();
 }while((ch=='y')||(ch=='Y'));


 return 0;
}
