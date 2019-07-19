#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *l_node;
    struct Node *r_node;
} node;

node * add_element(node *inp_node,int data){
    node *ip=inp_node;
    node *curr_node;
    if(inp_node != NULL){
        while(inp_node->r_node !=NULL){
            inp_node=(node *) inp_node->r_node;
        }
        curr_node=inp_node;
        inp_node->r_node=( node *) malloc(sizeof(node));//allocate a new node and set it to right 
        inp_node=(node *) inp_node->r_node; //set the new node as working node
        inp_node->l_node=( node *) curr_node; // assign the left(prev node addr) addr of working node to curr nodes addr
        inp_node->data=data;
        inp_node->r_node=NULL;
        return ip;
    }
    else {
        // create the root node;
        inp_node=(node *)malloc(sizeof(node));
        inp_node->l_node=NULL;
        inp_node->data=data;
        inp_node->r_node=NULL;
        return inp_node;
    }
}

int main(){
    node * dl,* drev;
    dl=NULL;
    drev=NULL;

    for (int i=1;i<10;i++){
        dl=add_element(dl,i); 
    }

    while(dl!=NULL){
        printf(" Val %d \n",dl->data);
        drev=dl->l_node;
        dl=dl->r_node;
    }

    dl=drev->r_node;
    printf("\n Reversing ......\n\n");
    while(dl!=NULL){
        printf(" Val %d \n",dl->data);
        dl=(node *) dl->l_node;
    }

}