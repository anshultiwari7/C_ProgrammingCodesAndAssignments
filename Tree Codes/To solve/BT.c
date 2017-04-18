#include<stdio.h>

int a[10],max=10;


struct node
{

int x;

struct node *right , *left ;

}*root=NULL,*temp,*temp1,*temp2;




void insert( struct node *t , int i )

{

if( i >= max )
    return ;


if(root==NULL )

{


temp=(struct node*)malloc( sizeof( struct node ));

temp->right = temp->left = NULL ;

root = temp ;

t=temp;

temp->x = a[i] ;

}


if(2*i+1 <= max-1)

{

temp1=(struct node*)malloc( sizeof( struct node ));

temp1->right=temp1->left=NULL;

t->left=temp1;

temp1->x=a[2*i+1];

insert(temp1->left,i+1);

}


if( 2*i+2 <= max-1)

{

temp2=(struct node*)malloc( sizeof( struct node ));

temp2->right=temp2->left=NULL;

t->right=temp2;

temp2->x=a[2*i+2];

insert(temp2->right,i+2) ;

}

return ;

}



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





void levelorder(struct node* root)
{
  int h = maxDepth(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}






int main()

{
int i=0;

printf("Enter values : ");

for(i=0;i<=9;i++)
{
printf("\n\nEnter the value at %d index of array :  ",i);
scanf("%d",&a[i]);
}

insert(root,0);

levelorder(root);

return 0;

}
