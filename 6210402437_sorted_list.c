//6210402437 Tanapon Srinakron
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
   int data; 
   struct node *next;
};

struct Node *createNode(int n){  //Use to create new node every round
   struct node *new_Node;
   new_Node = (struct node *)malloc(sizeof(struct node));
   new_Node->data = n;
   new_Node->next = NULL;
   return new_Node;
}

void sortingList(struct node **head, struct node *new_node){ //Use to compare between old linklist and new data
   struct node *tmp;
   if(*head == NULL || (*head)->data >= new_node->data){ // Condition check that head has data less than new data?
      new_node->next = *head; //New data point next to old head
      *head = new_node; //head point to new data
   }
   else{ //Check between linklist and insert it
      tmp = *head;
      while(tmp->next != NULL && (tmp->next)->data < (new_node)->data){//Check that position can insert new data by use while loop check
         tmp=tmp->next;
      }
      new_node->next = tmp->next; //New data point to tmp->next
      tmp->next = new_node; // tmp->next point to new data
   }
}

int main(){
   int num;
   struct node *head = NULL,*new_node,*tmp;

   while (scanf("%d",&num) == 1){
      if(num <= -1){
         break;
      }
      new_node = createNode(num);
      sortingList(&head,new_node);
      }
      for(tmp=head;tmp;tmp=tmp->next){
      printf("%d\n",tmp->data);
   }
}
