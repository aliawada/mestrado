													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													
													#include "listaEstatica2.c"
													
													int	main	(	)	{
														
													    //	Criando	uma	lista	vazia
													    
													    Lista	*minhaLista	=	cria_lista_vazia	(	)	;
													    
													    if	(	!	minhaLista	)	return	1	; //	Evita	erro	se	malloc	falhar
													
													    //	Inserindo	elementos
													    
													    insere	(	minhaLista	,	10	)	;
													    
													    insere	(	minhaLista	,	20	)	;
													    
													    insere	(	minhaLista	,	30	)	;
													    
													    printf	(	"	\n	Lista	apos	insercoes	:	\n	\n"	);	
													    
													    imprime	(	minhaLista	)	;
													
													    //	Removendo	um	elemento
													    
													    retira	(	minhaLista	,	20	)	;
													
													    printf	(	"	\n	Lista	apos	remover	20	:	\n	\n	"	)	;	
													    
													    imprime	(	minhaLista	)	;
													
													    //	Testando	lista	vazia
													    
													    while	(	!	vazia	(	minhaLista	)	)	{
													    	
													        retira	(	minhaLista	,	minhaLista	->	item	[	0	]	)	;
													        
													    }
													
													    printf	(	"	\n	Lista	apos	remover	todos	os	elementos	:	\n	\n	"	)	;
													    
													    imprime	(	minhaLista	)	;
														
														//	Liberando	a	memória	alocada
														
													    free	(	minhaLista	)	;
														
													    return	0;
													}

