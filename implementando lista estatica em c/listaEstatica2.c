 
 
  
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
												     
									                #include "listaEstatica2.h"
													                
													Lista*	cria_lista_vazia	(	)	{	
																																																																			 
														Lista	*nova_lista	=	(	Lista*	)	malloc	(	sizeof	(	Lista	)	)	;
														                 
														                 
														nova_lista	->	primeiro	=	0	;
														                  
														nova_lista	->	ultimo	=	0	;
														                  
														nova_lista	->	pos	=	-1	;
														                 
														                 
														return	nova_lista	;
														                 
													} 
														               
														               
														               
													int	vazia	(	Lista*	l	)	{
														                 
														return	(	l	->	primeiro	==	l	->	ultimo	)	;
      											
													}
																	
													//	Insere	um	item	na	lista
													
													//	Pr�-condi��o:	Lista	existente	e	n�o	cheia
													
													//	P�s-condi��o:	Item	inserido	no	final	da	lista
																	
													void	insere	(	Lista*	l	,	TipoItem	x	)	{
														
												
														if	(	l	->	ultimo	>=	TAM_MAX	)	{
															
															printf	(	"	Erro	:	Lista	cheia,	n�o	�	poss�vel	inserir	%d	\n	\n	"	,	x	)	;
															
															return	;
																	        
														}
														
																	
														l	->	item	[	l	->	ultimo	]	=	x	;	//	Adiciona	o	item	na	�ltima	posi��o	dispon�vel
														
														l	->	ultimo	++	;	//	Atualiza	o	�ndice	do	�ltimo	elemento
													}
																	
													//	Retira	um	item	da	lista
													
													//	Pr�-condi��o:	Lista	existente	e	item	presente	na	lista
													
													//	P�s-condi��o:	Item	removido	e	elementos	ajustados
																	
													void	retira	(	Lista*	l	,	TipoItem	x	)	{
														
																		
														if	(	vazia	(	l	)	)	{
																	    	
															printf	(	"	Erro	:	Lista	vazia	,	n�o	�	poss�vel	remover	%d	\n	\n	"	,	x	)	;
															
															return	;
																	        
														}
														
																	
														int	i	,	encontrado	=	0	;
														
																	    
														for	(	i	=	0	;	i	<	l	->	ultimo	;	i	++	)	{
																	        
															if	(	l	->	item	[	i	]	==	x	)	{
																				
																encontrado	=	1	;
																	            
																break	;
																	            
															}
																	        
														}
														
																	
														if	(	!	encontrado	)	{
																	        
															printf	(	"	Erro	:	Item	%d	n�o	encontrado	na	lista	\n	\n	"	,	x	)	;
																	        
															return	;
														
														}
														
																	
														for	(	;	i	<	l	->	ultimo	-	1	;	i	++	)	{
																	    	
															l	->	item	[	i	]	=	l	->	item	[	i	+	1	]	;
																	        
														}
														
																	
														l	->	ultimo	--	;
																	    
													}
																	
													//	Retorna	o	primeiro	item	da	lista		
																												
													//	Pre-condicao	:	ponteiro	nao	nulo	para	estrutura	lista	
																																
													//	Pos-condicao	:	retorna	o	primeiro	item
																	
													TipoItem	primeiro	(	Lista	*	l	)	{
																			
														l	->	pos	=	-1	;
																		
														return	proximo	(	l	)	;
																		
													}
															
													//	Retorna	o	proximo	item	da	lista		
																													
													//	Pre-condicao	:	ponteiro	nao	nulo	para	estrutura	lista
																															
													//	Pos-condicao	:	retorna	proximo	item
																	
													TipoItem	proximo	(	Lista*	l)	{
																			
														l	->	pos	++	;
														
																		
														if	(	l	->	pos	>=	l	->	ultimo	)
																		
															return	-1	;	//	acabou	itens
																			
														else
																		
															return	l	->	item	[	l	->	pos	]	;
															
													}
													
													//	Imprime	os	itens	da	lista
													
													//	Pre-condicao	:	ponteiro	nao	nulo	para	estrutura	lista
													
													//	Pos-condicao	:	nenhuma
																				
													void	imprime	(	Lista*	l	)	{
																					
														if	(	vazia	(	l	)	)
																	
															printf	(	"	Lista	vazia	\n	\n	"	)	;
																	
														else	{
																			
															int	i	=	0	;
															
															printf	(	"	[	"	)	;
															
															
															for	(	i	=	l	->	primeiro	;	i	<	l	->	ultimo	;	i	++	)
																			
																printf	(	"	%d	"	,	l	->	item	[	i	]	)	;
																
																			
															printf	(	"	]	\n	\n	"	)	;
																		
														}
																	
													}
																	
													//	imprime	usando	as	funcoes	iteradoras
													
													//	para	percorrer	a	lista
																	
													void	imprime2	(	Lista	*	l	)	{
																		
														if	(	vazia	(	l	)	)
																	
														printf	(	"	Lista	vazia	\n	\n	"	)	;
																	
														else	{
																				
															TipoItem	x	=	primeiro	(	l	)	;
																				
															printf	(	"	[	"	)	;
																			
																			
														do
																				
															printf	(	"	%d	"	,	x	)	;
																				
														while	(	(	x	=	proximo	(	l	)	)	!=	-1	)	;
														
																				
														printf	(	"	]	\n	"	)	;
																					
														}
																	
													}
