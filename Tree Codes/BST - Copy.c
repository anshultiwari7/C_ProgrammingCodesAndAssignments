#include <stdio.h>

struct node
{
int x;
struct node *right,*left;
}*root=NULL,*temp,*temp1,*temp2;


void create()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("\n\nEnter data you want to insert :  ");
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




int flag=1;
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
 temp1=t;
 delete(t->left,data);
 }
 else
 {
   if(t->right==NULL && t->left==NULL)
   {
     if(temp1->right==t)
     {
      temp1->right=NULL;
      if(flag)
      printf("Deleted element is : %d ",t->x);
      free(t);
     }
     else
     {
      temp1->left=NULL;
      if(flag)
      printf("Deleted element is : %d ",t->x);
      free(t);
     }
     return;
   }
   else
   if(t->right==NULL && t->left!=NULL)
   {
       if(temp1->right==t)
       {
        temp1->right=t->left;
        if(flag)
        printf("Deleted element is : %d ",t->x);
        t=NULL;
        free(t);
       }
       else
       //if(temp1->left==t)
       {
        temp1->left=t->left;
        if(flag)
        printf("Deleted element is : %d ",t->x);
        t->left=NULL;
        free(t);

       }
        return;
   }
   else
   if(t->left==NULL && t->right!=NULL)
   {
       if(temp1->right==t)
       {
        temp1->right=t->right;
        t=NULL;
        if(flag)
        printf("Deleted element is : %d ",t->x);
        free(t);
       }
       else
       //if(temp2->left==t)
       {
        temp2->left=t->right;
              //  printf("Deleted element is : %d ",t->x);
        t=NULL;
        free(t);
       }
       return;
  }
   else
   {
    int p;
    struct node *tempx=t->right;

    while(tempx->left!=NULL)
        tempx=tempx->left;
        p=tempx->x;
        //t->x=tempx->x;
       // tempx->x=p;
  //    call(p);
        //ag=1;
        //free()
        flag=0;
        printf("\nDeleted element is :  %d \n\n",t->x);
        delete(root,p);
        t->x=p;
   }
 }
}

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
   printf("\n\nEnter your choice below :-\n1.Insert.\n2.Delete.\n3.Display.\n4.Maximum Depth.\n5.Mirror Image.\n\n");
   scanf("%d",&p);
    switch (p)
    {
    case 1:
    insert();
    break;
    case 2:
    printf("Enter the value of the node you want to delete :  ");
    scanf("%d",&data);
    delete(root,data);
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
