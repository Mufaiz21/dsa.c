#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;

};
void print_ll(struct Node *);
struct Node *create_new_node(int data);
struct Node *insert_at_head(struct Node *,struct Node *);
void free_ll_mem(struct Node *head);
int main(){
    struct Node *head =NULL;
    int array_size;
    printf("enter size:");
    fflush(stdout);
    scanf("%d",&array_size);
    for(int i=0; i<array_size;i++){
        int current_data;
        printf("enter data %d: ",i+1);
        fflush(stdout);
        scanf("%d",&current_data);
        struct Node *new_node=create_new_node(current_data);
        head=insert_at_head(head,new_node);
    } 
    printf("\nLinked list:\n");
    print_ll(head);
    free_ll_mem(head);
    return 0;
}

struct Node *create_new_node(int data){
    struct Node *new_node=malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;

}
struct Node *insert_at_head(struct Node *head,struct Node *new_node){
    new_node->next=head;
    head=new_node;
    return new_node;
}
void insert_at_tail(struct Node *head,struct Node *new_node){
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
void print_ll(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    }
    void free_ll_mem(struct Node *head){
    struct Node *to_delete;
    while(head!=NULL){
      to_delete=head;
      head=head->next;
      free(to_delete);
    }
}