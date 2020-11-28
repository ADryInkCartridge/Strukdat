// ngods stack skoy
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode
{
    char word;
    struct stacknode *next;
}nodes;

typedef struct stacks
{
    nodes *top;
    unsigned size;
}stacks;

void initialize(stacks *stack)
{
    stack->top=NULL;
    stack->size=0;
}

bool empty (stacks *stack)
{
    return (stack->top==NULL);
}
void push(stacks *stack, char word_in)
{
    nodes *newnode = (nodes*) malloc(sizeof(newnode));
    if (newnode)
    {
        stack->size++;
        newnode->word=word_in;

        if (empty(stack))
        {
            newnode->next=NULL;
        }
        else
        {
            newnode->next=stack->top;
        }
        stack->top=newnode;
    }
}

void pop(stacks *stack)
{
    if (!empty(stack))
    {
        nodes *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
}

bool compare(stacks *stack)
{
    nodes *temp =stack->top;
    while (stack->size>1 && stack->top!=NULL)
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        if (temp->word==stack->top->word)
        {
            free(temp);
            pop(stack);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main ()
{
    stacks palin;
    initialize(&palin);
    char word;
    while (word!='\n')
    {
        word=getchar();
        push(&palin,word);
    }

    bool flag=compare(&palin);

    if (flag==true)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
}
