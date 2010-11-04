/*
 *  Stack.h
 *  TP1
 *
 *  Created by Francois-Guillaume Ribreau on 04/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _STACK_H
#define _STACK_H

#include "env.h"

typedef struct Stack* pStack;

struct Stack
{
	pStack prev;
	pStack next;
	void* data;
} Stack;

pStack	Stack_create	(void);
void	Stack_push		(pStack*, void*);
void*	Stack_pop		(pStack*);
void	Stack_delete	(pStack*);
bool	Stack_isEmpty	(pStack stack);
int		Stack_size		(pStack stack);
#endif
