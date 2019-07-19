#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *l_node;
    int data;
    struct Node *r_node;
} node;

node *add_element(node *inp_node, int data)
{
    node *ip = inp_node;
    node *curr_node;

    if (inp_node != NULL)
    {
        while (inp_node->r_node != NULL)
        {
            inp_node = inp_node->r_node;
        }
        curr_node = inp_node;
        inp_node->r_node = (node *)malloc(sizeof(node));
        inp_node = inp_node->r_node;
        inp_node->data = data;
        inp_node->l_node = curr_node;
        inp_node->r_node = NULL;
        return ip;
    }
    else
    {
        inp_node = (node *)malloc(sizeof(node));
        inp_node->data = data;
        inp_node->l_node = inp_node->r_node = NULL;
        return inp_node;
    }
}

void print_elements(node *inp_node)
{
    node *curr_node;
    printf("-----------------------------------------------------\n");
    while (inp_node != NULL)
    {
        curr_node = inp_node;
        printf("Value is %d\n", inp_node->data);
        inp_node = inp_node->r_node;
    }
    /***  while (curr_node != NULL) 
    *  { 
    *      printf("Value in reverse %d\n", curr_node->data);
    *      curr_node = curr_node->l_node; 
    *  } 
    ***/
}

node *remove_element(node *inp_node, int data){
    node *ini_node,*curr_node,*prev_node,*next_node;
    ini_node=inp_node;
    
    while(inp_node!=NULL){
        /* Seek the node to be acted upon */
        if(inp_node->data!=data){
            /*  printf("%d %d\n",inp_node->data,data); */
            inp_node=inp_node->r_node;
        }
        else{ /* node found */
            /*
            * When the node to be deleted is found 
            * 1) Process if its the first node in the list
            * 2) Process if its the last node in the list
            * 3) Process all other nodes
            */
            if(inp_node->l_node ==NULL){
                next_node=inp_node->r_node;
                inp_node->r_node=NULL;
                next_node->l_node=NULL;
                inp_node = next_node;
                return inp_node;
            }
            else if(inp_node->r_node == NULL){/*  Remove the last element */
                next_node = inp_node->l_node;
                inp_node->r_node = NULL;
                next_node->r_node = NULL;
                return ini_node;
            }
            else {
                curr_node=inp_node;
                prev_node=curr_node->l_node;
                next_node=curr_node->r_node;
                prev_node->r_node=next_node;
                next_node->l_node=prev_node;
                // inp_node=next_node;
                return ini_node;
            }
        }
    }
    return ini_node; /* return the passed list as default case*/
}

int main(int argc, char *argv[])
{
    node *queue;
    queue = NULL;
    int cntr = 3;

    if (argc > 1)
    {
        cntr = atoi(argv[1]);
    }

    for (int i = 1; i <= cntr; i++)
    {
        queue = add_element(queue, i);
    }
    print_elements(queue);
    for (int i=1;i<=cntr;i++){
        if( (i%2) == 0){
            printf("---------------------\n");
            printf("Removing %d\n",i);
            queue=remove_element(queue,i);
            print_elements(queue);
            printf("---------------------\n");
            printf("DONE Removed %d\n",i);
        }
    }
}