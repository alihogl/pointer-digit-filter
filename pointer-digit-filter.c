#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node {
	int data;
	struct Node *next;
};

struct Node *root=NULL;

 
void print(struct Node *head) {
	while(head!=NULL) {
		printf("%d  ", head->data);
		head = head->next;
	}
}

void addValues(int number) {
	  int n = log10(number) + 1;
      int i;
      int *array = calloc(n, sizeof(int));
      for ( i = 0; i < n; ++i, number /= 10 )
       {
        array[i] = number % 10;
         }
   

	struct Node *firstValue = (struct Node *) malloc(sizeof(struct Node));
	struct Node *tempPtr;
	firstValue->data = array[n-1];
	firstValue->next=NULL;
	
	root = firstValue;
	
	tempPtr = root;
	

	
	for(i= n - 2; i>=0; i--) {
		while(tempPtr->next!=NULL) {
			tempPtr= tempPtr->next;
		}
			struct Node *newValue = (struct Node *) malloc(sizeof(struct Node));
			newValue->data=array[i];
			newValue->next=NULL;
			tempPtr->next = newValue;
	}
	
}

void alignElements() {
	struct Node *ptr1 = (struct Node *) malloc(sizeof(struct Node));
	struct Node *ptr2 = (struct Node *) malloc(sizeof(struct Node));
	struct Node *ptr3 = (struct Node *) malloc(sizeof(struct Node));
	
	ptr1 = root;
	ptr2 = root->next;
	ptr3 = root;
	

	
	
	while(ptr1->next!=NULL) {
		
		while(ptr2!=NULL) {
			
			if(ptr1->data!=ptr2) {
				
				if(ptr1->data==ptr2->data && ptr1!=ptr2) {
					ptr3->next = ptr2->next;
					ptr2->next = ptr1->next;
					ptr1->next = ptr2;
					break;
				}
				
			}
			
			ptr2 = ptr2->next;
			ptr3 = ptr3->next;
			
			
		}
		ptr1=ptr1->next;
		ptr2=ptr1->next;
		ptr3=ptr1;

		
	}



}


void grouping(struct Node *p,int val){
	
	struct Node *ptr1 = (struct Node *) malloc(sizeof(struct Node));
	struct Node *ptr2 = (struct Node *) malloc(sizeof(struct Node));
	struct Node *ptr3 = (struct Node *) malloc(sizeof(struct Node));

	ptr1 = p;
	
	int i;
	int sayac = 1;
	int istek = val;
	
	
	

	while(ptr1!=NULL){
			if(ptr1==NULL) {
				
				break;
			}
		ptr2=ptr1->next;
		while(ptr2!=NULL) {
				
				if(ptr1->data==ptr2->data) {

						ptr2=ptr2->next;
						
			
					sayac++;
				}	
				else {
					break;
				}	
		}
		
	if(sayac>istek) {
		for(i=0; i<sayac-istek; i++) {
			ptr3 = ptr1->next;
			ptr1->next=ptr3->next;
			free(ptr3);
		}
		
		}
		
		sayac=1;	
		ptr1=ptr2;
	}
	
}


int main() {

	int no;
	printf("Enter a number : ");
	scanf("%d", &no);
	
	if(no<=0 || no>999999999) {
	
		printf("Please set the number between 1 and 9 digits.");
		return 0;
	}
	
	addValues(no);
	alignElements();
	int i;
   	struct Node *head=root;
   
   	
	printf("Enter max number of repetitions : ");
	scanf("%d", &i);
	
	if(i<=0) {
		printf("Please enter a value greater than 0 for grouping..");
		return 0;
	}
	
	printf("\nBefore grouping : \n");
	print(head);
	grouping(head,i);
	printf("\nAfter grouping : \n");
		
	print(head);
	
	return 0;
}
