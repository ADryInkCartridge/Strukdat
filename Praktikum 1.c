#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front,
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (queue_isEmpty(queue))
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);

        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

void swap (int *a,int *b)
{
	int temp = *a;
	*a   = *b;
	*b   = temp;

}

void in (Queue *queue,int input[],int tc)
{
	int i=0;
	queue_push(queue, input[i]);
	//printf("Q=%d IN=%d\n",queue->_rear->data,input[i]);
	i++;
	while (i<tc)
	{
		if (queue->_rear->data==input[i])
		{
			input[i]=input[0];
		}
		else
		{
			queue_push(queue,input[i]);
			//printf("Q=%d IN=%d\n",queue->_rear->data,input[i]);
		}
		i++;
	}
}

int main(int argc, char const *argv[])
{
    Queue urut;
    queue_init(&urut);
	int tc;
	scanf("%d",&tc);
	int input[tc];
	for (int i=0;i<tc;i++)
	{
		scanf("%d",&input[i]);
		//printf("%d ",input[i]);
	}
	for (int i=0;i<tc;i++)
	{
		for (int j=0;j<i;j++)
		{
			if (input[i]<input[j])
			{
				swap(&input[i],&input[j]);
			}
		}
	}
	for (int i=0;i<tc;i++)
	{
		//printf("%d ",input[i]);
	}


	in(&urut,input,tc);
    // cetak isi queue
    while (!queue_isEmpty(&urut)) {
        printf("%d ", queue_front(&urut));
        queue_pop(&urut);
    }
    return 0;
}
