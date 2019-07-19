#include<stdio.h>
#include<stdlib.h>

struct date{
    int day;
    int month;
    int year;
};

struct struct_ptrs{
    int *ptr;
    int *ptr1;
};

struct lnk_lst{
    int data;
    struct lnk_lst *next;
};

void test_lnk_lst01(){
    struct lnk_lst node1,node2,node3;
    struct lnk_lst *trav_lst;
    trav_lst=&node1;
    node1.data=10;
    node1.next=&node2;
    node2.data=11;
    node2.next=&node3;
    node3.data=12;
    node3.next=(struct lnk_lst *) 0;

    while(trav_lst!=(struct lnk_lst *) 0){
        printf("Value of in node :%d\n",trav_lst->data);
        trav_lst=trav_lst->next;
    }
}

void test_char_pointer()
{
    char *string="abcdef";
    printf("%s\n", string);
    // string = (char *)malloc(5);
    string = "defgeh";  // <<<<<<<<<< why *string="abc" is not working. How string = "abc" is working?
    printf("%s\n", string);
}

void ptr1() {
    int *p;
    int c=9;
    p=&c;
    printf(" c is %d and ptr is %d\n",c,*p);
    c=10;
    printf(" c is %d and ptr is %d\n",c,*p);
}

void test_struct_ptrs(){
    struct struct_ptrs int_ptrs;
    struct struct_ptrs *int_ptr_of_ptr;
    int i=10,j;

    int_ptrs.ptr=&i;
    int_ptrs.ptr1=&j;
    int_ptr_of_ptr->ptr=&i;
    int_ptr_of_ptr->ptr1=&j;
    j=20;
    printf("Value of i : %d \n",*int_ptrs.ptr);
    printf("Value of j : %d \n",*int_ptrs.ptr1);
    printf("Value of p2p i : %d \n",*int_ptr_of_ptr->ptr);
    printf("Value of p2p j : %d \n",*int_ptr_of_ptr->ptr1);
}

void pass_by_ref(int *i){
    *i=9;
}

void test_pass_by_ref(){
    int y=10;
    printf("Before Value of y :%d\n",y);
    pass_by_ref(&y);
    printf("After Value of y :%d\n",y);

}

void test_struct() {
    struct date todays_date,*ptr_date;
    ptr_date=&todays_date;
    // 
    todays_date.day=22;
    todays_date.month=10;
    todays_date.year=2018;
    //
    printf("Todays day is   :%d\n",todays_date.day);
    todays_date.day=21;
    //
    printf("Todays day is   :%d\n",ptr_date->day);
    printf("Todays month is :%d\n",ptr_date->month);
    printf("Todays year is  :%d\n",ptr_date->year);
    printf("Todays date is  :%d/%d/%d \n",ptr_date->day,ptr_date->month,ptr_date->year%100);
}

void test_ptr02(){
    int *iVar;
    iVar=(int*)malloc(sizeof(int));
    printf("Input variable :");
    scanf("%d",iVar);
    printf("you entered :%d \n",*iVar);
    free(iVar);
}

int main(int argc,char**argv){
    ptr1();
    test_struct();
    test_struct_ptrs();
    test_pass_by_ref();
    test_lnk_lst01();
    test_char_pointer();
    return 0;
}
