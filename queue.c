#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct  {
    int value ;
    struct node *next;
} node;

void prni(char * input_var,int input_val){
    printf("{%s} : [%d]\n",input_var,input_val);
}
void prnd(char * input_var,double input_val){
    printf("{%s} : [%fl]\n",input_var,input_val);
}
void prns(char * input_var,char * input_val){
    printf("{%s} : [%s]\n",input_var,input_val);
}
void prndbg(char * input){
    printf("%s\n",input);
}

node * add_element( node * inp_node,int value){
    node *ip=inp_node;
    // prni("add_element",value);
    // prni("size of inp_node",sizeof(inp_node));

    /* if atleast one node exists*/
    if(inp_node!=NULL){
        // prni("***add_element in before if",value);
        while(inp_node->next!=NULL){
            inp_node=(node *) inp_node->next;
        }
        // prni("add_element in if",value);
        /***
         *  get to the last node, allocate a new node to the next of the current node
         *  make the new node active by assiging its address to working node
         *  assign value to working nodes data(value) field
         *  make the next as NULL
         ***/
        inp_node->next=(struct node *) malloc(sizeof(node));
        inp_node=(node *) inp_node->next;
        inp_node->value=value;
        inp_node->next=NULL;
        return ip; // Return the first element of the list
    }
    else{
        inp_node=(node *) malloc(sizeof(node));
        // prni("@@@ add_element in else",value);
        inp_node->value=value;
        inp_node->next=NULL;
        return inp_node; //Return the current element of the list
    }
}

void print_queue(node *inp_node){
    prndbg("------------------------------------------------");
    prndbg("Function Called : print_queue");
    if(inp_node == NULL){
        prndbg(" Queue is empty");
    }
    else {
        while(inp_node!=NULL){
            prni("inp_node",inp_node->value);
            inp_node=(node *) inp_node->next;
        }
    }
}

node * remove_any_element(node *inp_node,int val_for_removal){
    node *prev_node;
    node *curr_node;
    node *ip=inp_node;
    /***
     * Traverse through the list keep the address of prev node handy 
     * and find the element to remove
     * once found,change the next node of prev element to the next node of the curr element
     * free the current node
     ***/
    prndbg("Function Called : remove_any_element");
    while(inp_node!=NULL){
        if(inp_node->value==val_for_removal){
            prni("Found value for removal",val_for_removal);
            curr_node=inp_node;
            prev_node->next=curr_node->next;
            free(curr_node);
            break;
        }
        else{
            prev_node=inp_node;
            inp_node=(node *) inp_node->next;
        }
    }
    return ip;
}

node * dequeue(node * inp_node){
    node * next_node;
    prndbg("Function Called : dequeue");
    if (inp_node!=NULL){
        next_node=(node *) inp_node->next;
        prni("Element removed ",inp_node->value);
        free(inp_node);
        return next_node;
    }
    else{
        prndbg("Nothing to dequeue");
        return NULL;
    }
}

int main(){
    node *queue;
    queue=NULL;
    for (int i=10;i<17;i++){
        queue=add_element(queue,i);
    }
    print_queue(queue);
    queue=remove_any_element(queue,13);
    print_queue(queue);
    queue=dequeue(queue);
    print_queue(queue);
    queue=dequeue(queue);
    print_queue(queue);
    queue=dequeue(queue);
    print_queue(queue);
    queue=dequeue(queue);
    print_queue(queue);
}

/****
void input_screen(){
    char inp_item='0';
    do{
        printf("Enter 1) Add element 2) Remove element 3) Remove any element 4) exit\n");
        inp_item=get_char();
        if (inp_item != '1' && inp_item !='2' && inp_item !='3' && inp_item !='4'){
            continue;
        }
        if(inp_item=='1'){

        }
        else if(inp_item=='2'){

        }
        else if(inp_item=='3'){

        }
        else if(inp_item=='4'){
            printf("Thank you working with us\n");
            break;
        }
        else {
            continue;
        }
    }while(inp_item!='4');
    
}
***/
