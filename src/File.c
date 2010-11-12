

#include "File.h"

pFile File_create(){
	return NULL;
}


//Ajout un élément dans la file
void File_push(pFile* file, void* data){
	if (file != NULL)
	{
		pFile p_l = NULL;
		pFile p_p = NULL;
		
		File_first(file);
		/* (2) */
		p_l = *file;
		/* (3) */
		p_p = _malloc (sizeof (*p_p));
		if (p_p != NULL)
		{
			p_p->data = data;
			/* (4) */
			p_p->next = p_l;
			p_p->prev = NULL;
			if (p_l != NULL)
				p_l->prev = p_p;
			/* (5) */
			*file = p_p;
		}
		else
		{
			fprintf (stderr, "Memoire insuffisante\n");
			exit (EXIT_FAILURE);
		}
	}
	return;
}
	

void File_first(pFile* file){
	if (file != NULL && *file != NULL){
		while ((*file)->prev != NULL)
			File_prev(file);
	}
	return;
}

void File_prev(pFile* file){
	if (file != NULL && *file != NULL)
		*file = (*file)->prev;
	return;
}


bool File_isEmpty(pFile file){
	return file == NULL;
}

int File_size(pFile file){
	if(file == NULL)
		return 0;
	
	int i = 0;
	
	//pFile cursor = file;
	
	while(file){
		i++;
		file = file->next;
	}
	
	return i;
}

/* Retourne un élment de la file */
void* File_get(pFile* file)
{
	void *ret = NULL;
	
	if (file != NULL && *file != NULL)
	{
		pFile p_l = NULL;
		pFile p_p = NULL;
		
		/* (2) */
		File_last(file);
		p_l = *file;
		/* (3) */
		if (p_l != NULL)
			p_p = p_l->prev;
		ret = p_l->data;
		/* (4) */
		_free (p_l);
		p_l = NULL;
		/* (5) */
		if (p_p != NULL)
			p_p->next = NULL;
		*file = p_p;
	}
	return (ret);
}

void File_last(pFile* file){
	if (file != NULL && *file != NULL){
		while ((*file)->next != NULL)
			File_next(file);
	}
	return;
}

void File_next(pFile* file){
	if (file != NULL && *file != NULL)
		*file = (*file)->next;
	return;
}

