
#include "Stack.h"

pStack Stack_create(void){
	return (NULL);
}

//Ajouter une donnée à la pile
void Stack_push(pStack* stack, void *data){
	
	if (stack != NULL){
		pStack p_p = *stack;
		pStack p_l = NULL;
		
		p_l = _malloc (sizeof (*p_l));
		if (p_l != NULL)
		{
			p_l->data = data;
			p_l->next = NULL;
			p_l->prev = p_p;
			if (p_p != NULL)
				p_p->next = p_l;
			*stack = p_l;
		}
		else
		{
			fprintf (stderr, "Memoire insuffisante\n");
			exit (EXIT_FAILURE);
		}
	}
	return;
}


//Retirer une donnée de la pile
void* Stack_pop (pStack* stack){
	void *ret = NULL;
	
	if (stack != NULL && *stack != NULL){
		pStack p_l = *stack;
		pStack p_p = p_l->prev;
		
		if (p_p != NULL)
			p_p->next = NULL;
		ret = p_l->data;
		_free (p_l);
		p_l = NULL;
		*stack = p_p;
	}
	return (ret);
}

//Dériger le curseur vers la fin de la pile
void Stack_delete(pStack* stack){
	if (stack != NULL && *stack != NULL){
		while (*stack != NULL)
			Stack_pop (stack);
	}
	return;
}

bool Stack_isEmpty(pStack stack){
	return stack == NULL;
}

int Stack_size(pStack stack){
	if(stack == NULL)
		return 0;
	
	int i = 0;
	
	while(stack){
		i++;
		stack = stack->next;
	}
	
	return i;
}

void Stack_forEach(pStack stack, void (*forEachCallback)(void*, pStack)){
	//Boucle sur la liste chainée + comparaison de index
	do{	
		(*forEachCallback)(stack->data, stack);
	}while((stack = stack->prev));
}

void Stack_free(pStack stack){
	void __callback(void* data, pStack stack){
		_free(data);//Libération du data
		_free(stack);//Libération du hash
	}
	
	Stack_forEach(stack, __callback);
}

