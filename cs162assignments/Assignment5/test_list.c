#include "list.h" 
#include <stdio.h> 
#include <stdlib.h> 

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

struct node * push(struct node * head, int s){
	/*if (head == NULL){
		head = (struct node*) malloc(sizeof(struct node));
	}*/
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


int main (){
	char ans[2];
	int num;
	struct node *head = NULL;
	do {
		do {

			printf("Enter a number: ");
			scanf("%d", &num);
			
			head = push(head, num);//Can change to append 
			
			printf("Do you want another num (y or n): "); 
			scanf("%1s",ans);
			

			
		} while(ans[0] == 'y');

		printf("Sort ascending or descending (a or d)? "); 
		scanf("%1s",ans);
		if(ans[0] == 'a') 
			head = insert_middle(head , 2,2);
			//head=sort_ascending(head);
		else if(ans[0] == 'd') 
			head=sort_descending(head);
		print(head, length(head));
		printf("Do you want to do this again (y or n)? ");
		 scanf("%1s",ans);
		head = clear(head);
		} while(ans[0] == 'y');
		return 0; }
		                                                                             