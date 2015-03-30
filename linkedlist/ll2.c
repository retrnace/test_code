#include</test/linkedlist/ll.h>


int add_node(node_t ** head, int num){
	node_t * temp = * head;
	node_t *  node = (node_t *) malloc(sizeof(node_t));
	node->data = num;
	node->next = NULL;
	if (*head  == NULL){
		*head = node; 
		//printf("print %d\n", (*head)->data);
		return 1;
	}
			
	while (temp->next != NULL ){
		temp = temp->next;
	}
	temp->next = node;


}

void print_list(node_t * head){
	node_t * node = head;
	int i = 1;
	 
	while (node != NULL){
		printf("node #%d = %d\n", i++ , node->data);
		node = node->next;
	}

}

int add_lists(node_t * a,node_t * b, node_t ** sum){

	node_t * tempA = a;
	node_t * tempB = b; 
	node_t * newN; 
	//node_t * tempC = *sum;
	node_t * old ;
	int first = 1; 
	if ( a ==  NULL || b == NULL || *sum != NULL ){
		printf("error\n");
		return 0;
	}
	
	while ( tempA != NULL && tempB != NULL ){
		newN = (node_t * )malloc(sizeof(node_t));
		newN->next = NULL;
		newN->data = 0;
		if (tempA){	
			newN->data += tempA->data;
			tempA = tempA->next;
		}
		if(tempB){
			newN->data += tempB->data;
			tempB = tempB->next;
		}
		if (first){	
			first = 0;
			*sum = newN;
		}
		else {
			old->next = newN;
		}
		old = newN;
	}

}


int split_list(node_t * a, node_t ** odd, node_t ** even){
	int i = 0;
	node_t * nodeN;
	node_t * lastO;
	node_t * lastE;
	node_t * tempa = a;
	int firstE = 1; 
	int firstO = 1;
	
	while ( tempa != NULL ){
		nodeN = (node_t *)malloc(sizeof(node_t));
		
		nodeN->data = tempa->data;
		nodeN->next = NULL;
			
		//odd
		if (i ^=  0x1){
			if (firstO){
				firstO = 0;
				*odd = nodeN; 
			}
			else{
				lastO->next = nodeN;	
			}
			lastO = nodeN;
		}
		else {
			if (firstE){	
				firstE = 0; 
				*even = nodeN; 
			}
			else{
				lastE->next = nodeN;
			}
			lastE = nodeN;
		}
		
		tempa = tempa->next;	
	}

}
	

int main(void){
	int i = 0;
	node_t * head1 = NULL;
	node_t * head2 = NULL; 
	node_t * sum = NULL;
	node_t * sume = NULL;
	node_t * sumo = NULL;
	while(i < 20){
		add_node(&head1, i++);
	}
	print_list(head1);

	while (i < 40){
		add_node(&head2, i++);
	}
	print_list(head2);
	add_lists(head1,head2,&sum);
	print_list(sum);
	split_list(sum, &sumo,&sume);
	print_list(sumo);	
	print_list(sume);
	return 1; 



}




