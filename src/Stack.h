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

pStack	stack_new		(void);
void	stack_push		(pStack*, void*);
void*	stack_pop		(pStack*);
void	stack_delete	(pStack*);

#endif

