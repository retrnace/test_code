#include</test/linkedlist/ll.h>

ll_t *  create_ll(void){

	node_t *  head =  (node_t *) malloc(sizeof(node_t));
	ll_t * list  = (ll_t *) malloc (sizeof(ll_t));
	list->head = head;
} 


int build_list(ll_t * list, int num_nodes){

	node_t * node = list->head; 
	node_t * next;
	int i = 2;	
	
	if (num_nodes == 1){
		node->data = 1;
		node->next = NULL;
		return 1;		
	}

	node->data = 1;
	while (num_nodes > (i-1) ){
		next = (node_t *) malloc( sizeof(node_t));
		next->data = i++;
		node->next = next;
		node = next;
		printf("%d\n", i);

	} 


	node->next = NULL;	
 
}


int add_node(ll_t * list, int value){

	node_t * node = list->head;
	node_t * next = (node_t *) malloc (sizeof(node_t));
	next->data = value;
	next->next = NULL; 
	while (node->next != NULL){
		node = node->next;
	}
	
	node->next = next;


}

int print_list(ll_t * list){

	node_t * node = list->head;
	int i = 1;
	if (node == NULL){
		printf("no list\n");
		return 0;
	}
	printf("node #%d = %d\n", i, node->data);
	node = node->next;
	while(node != NULL ){
		printf("node #%d = %d\n", ++i, node->data);
		node = node->next;
	}

	return 1;
}


int main(void){

	ll_t * list; 
	printf("************ linked list test program *******\n");
	list = create_ll();
	build_list(list,10);
	print_list(list);
	add_node(list, 233);
	print_list(list);

	return 1;

}




