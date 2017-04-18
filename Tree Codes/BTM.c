#include <stdio.h>
#include <stdlib.h>

// For Queue Size
#define SIZE 50

struct node
{
    int data;
    struct node *right,*left;
};


struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};


struct node* newNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node**) malloc(queue->size * sizeof( struct node* ));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}


int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{  return queue->rear == queue->size - 1; }

int hasOnlyOneItem(struct Queue* queue)
{  return queue->front == queue->rear;  }

void Enqueue(struct node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}


struct node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node* temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}


struct node* getFront(struct Queue* queue)
{  return queue->array[queue->front]; }



int hasBothChild(struct node* temp)
{
    return temp && temp->left && temp->right;
}



void insert(struct node **root, int data, struct Queue* queue)
{

    struct node *temp = newNode(data);


    if (!*root)
        *root = temp;

    else
    {

        struct node* front = getFront(queue);


            if (!front->left)
            front->left = temp;

        else

            if (!front->right)
            front->right = temp;

            if (hasBothChild(front))
            Dequeue(queue);
    }


    Enqueue(temp, queue);
}



void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
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



int main()
{
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i,z;

    for(i = 1; i <= 10; ++i)
    {

     printf("\nEnter data :  ");
     scanf("%d",&z);
        insert(&root,z, queue);
    }
    levelorder(root);

    return 0;
}
