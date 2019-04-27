/*********************************************************************** 
Program Filename: List.c
** Author: Sonia Camacho
** Date: 6-4-18
** Description: This program is now in C and I just had to write the meaty part of the functions
** Input:none
** Output: returns a linked list
*********************************************************************/

#include "list.h" 
#include <stdio.h> 
#include <stdlib.h> 

/********************************************************************* 
** Function: Length
** Description: this function returns the length of the linked list
** Parameters: the linked list
** Pre-Conditions: none
** Post-Conditions: the count
*********************************************************************/
int length(struct node * head){
    int count = 0;  
    struct node* current = head; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
/********************************************************************* 
** Function: Print
** Description: this prints out the linked list
** Parameters: the head and the spot to print until
** Pre-Conditions: none
** Post-Conditions: prints the list
*********************************************************************/
void print(struct node * head, int s){
	int i;
    struct node *current = head;
    printf("Your linked List: \n");
    while (current != NULL) {
    	for(i =0; i < s;i++){
		    printf("%d",current->val);
		    current=current->next;
		}
		printf("%s\n");
	}
}
/********************************************************************* 
** Function: Push
** Description: this will push in the numbers and populate it
** Parameters: the head and the number to insert
** Pre-Conditions:none
** Post-Conditions: populates the linked list
*********************************************************************/
struct node * push(struct node * head, int s){
	struct node *current = head;
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	if (current == NULL ){
		temp->next == NULL;
	}
    temp -> val  = s;
    temp -> next = current;
    head = temp;
    return head;
}
/********************************************************************* 
** Function: Append
** Description: this will add to the back
** Parameters: the head and the number
** Pre-Conditions:none
** Post-Conditions: populates it from the back
*********************************************************************/
struct node * append(struct node * head, int s){
	struct node *current = head;
    struct node *temp =  (struct node*) malloc(sizeof(struct node));
    while(current->next != NULL){
		current = current->next;
	}
    temp->val = s;
    temp->next = NULL;
    current->next = temp;
    return head;
}
/********************************************************************* 
** Function: clear
** Description: this will clear the entire array 
** Parameters: the head
** Pre-Conditions:none
** Post-Conditions: will clear it
*********************************************************************/
struct node * clear(struct node * head) {
   
   struct node* current = head;
   struct node* temp;
   temp = NULL;
   while (current != NULL) 
   {
       temp = current->next;
       free(current);
       current = temp;
   }  	
   head = NULL;
   current =NULL;
   return head;
}
/********************************************************************* 
** Function:Remove node
** Description: this will remove a particular node
** Parameters: head and spot
** Pre-Conditions: none
** Post-Conditions: removes one node
*********************************************************************/
struct node * remove_node(struct node * head, int s){
	int i ;
	struct node* temp_one  = head;
	struct node* temp_two ;
  
	for(i =0; i < s-1 ;i++){
		temp_one = temp_one->next;
	}
	temp_two = head;

	for(i =0; i < s ;i++){
		temp_two = temp_two->next;
	}
	temp_one->next = temp_two->next;
	
	
	return head;
}
/********************************************************************* 
** Function: sort ascending
** Description: this sorts it ascendings 
** Parameters: the head
** Pre-Conditions: none
** Post-Conditions: sorts asending
*********************************************************************/
struct node * sort_ascending(struct node * head){
   int i; 
   int j;
   int len = length(head);
   struct node* current = head;
   struct node* left;
   struct node* right;
   
   if (len == 2 && head->val > head->next->val){
   	left = head;
   	right = left->next;
   	left->next = right->next;
   	right->next = left;
   	head = right;
   	return head;

   } 
  
   for (i =0; i < len ;i ++){
       for (j = 0; j < len -1 ; j++){
	   	   if (current == head && (current->val > current->next->val)){
	   			left = current;
			   	right = left->next;
			   	left->next = right->next;
			   	right->next = left;
			   	head = right;
			   	current = right;
			  
	   			
	   		}
	   		 if (current->next->next != NULL && current->next->val > current->next->next->val){
	   			left = current->next;
			   	right = current->next->next;
			   	left->next = right->next;
			   	right->next = left;
			   	current->next = right;
			
	   		}
   		current = current->next;
   	}
  	current = head;
  
   }
   return head;
} 
/********************************************************************* 
** Function: sort descending 
** Description: this sorts opposite of ascending
** Parameters: the head
** Pre-Conditions: none
** Post-Conditions: sorts descending
*********************************************************************/
struct node * sort_descending(struct node * head){
   int i; 
   int j;
   int len = length(head);
   struct node* current = head;
   struct node* left;
   struct node* right;  
   if (len == 2 && head->val < head->next->val){
   	left = head;
   	right = left->next;
   	left->next = right->next;
   	right->next = left;
   	head = right;
   	return head;
   } 
   for (i =0; i < len ;i ++){
       for (j = 0; j < len -1 ; j++){
	   	   if (current == head && (current->val < current->next->val)){
	   			left = current;
			   	right = left->next;
			   	left->next = right->next;
			   	right->next = left;
			   	head = right;
			   	current = right;	     			
	   		}
	   		 if (current->next->next != NULL && current->next->val < current->next->next->val){
	   			left = current->next;
			   	right = current->next->next;
			   	left->next = right->next;
			   	right->next = left;
			   	current->next = right;
	   		}
   		current = current->next;
   	}
  	current = head;
   }
   return head;
}
/********************************************************************* 
** Function:insert middle
** Description:this puts one in the middle
** Parameters:the heaed and new val and the spot
** Pre-Conditions:none
** Post-Conditions: inserts the new node
*********************************************************************/
struct node * insert_middle(struct node * head, int new_node_val, int spot){
	 struct node* current = head;
	 int i;
	 struct node* temp = (struct node*) malloc(sizeof(struct node));
	 struct node* temp2;
	 temp ->val = new_node_val;
	 temp ->next = NULL;

	 if(spot == 1){
	 	temp ->next = head;
	 	head = temp;
	 	return head;
	 }
	 temp2 = head;
	 for (i = 0; i < spot - 1; ++i)
	 {
	 	temp2 = temp2 ->next;	
	 }
	 temp->next = temp2->next;
	 temp2->next = temp;
	 return head;
}
