#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct ArrayList{
	
	int reservedSize; //tamaño reservado 
	int _size;      //tamaño de la lista
	void **pElements; //puntero a los elementos de la lista
	
	void (*add)();
	void (*remove)();
	void (*set)();
struct	ArrayList(*get)();
	void(*push)();
struct	ArrayList(*pop)();
	int(*indexOf)();
	int(*size)();
	int(*contains)();
	int(*containsAll)();
	int(*isEmpty)();
	struct ArrayList(*clone)();
struct	Arraylist(*subList)();
	void(*clear)();
}ArrayList;


ArrayList* newArrayList(void);

void add(ArrayList* pAL, int* pInt );
void mostrar(ArrayList* pAL, int index);
void removee(ArrayList* pAL, int index);
void set(ArrayList* pAL, int index, void*element);
ArrayList* get(ArrayList* pAL, int index);
void push(ArrayList* pAL, int index, void* numero);
void* pop(ArrayList* pAL, int index);
int size(ArrayList* pAL);
int isEmpty(ArrayList* pAL);
int contains(ArrayList* pAL, void* elements);
int indexOf(ArrayList* pAL, int numero);
ArrayList* clear(ArrayList* pAL);
ArrayList* clone(ArrayList* pAL);
ArrayList* subList(ArrayList* pAL, int from, int to);
int containsAll(ArrayList* pAL, int array[]);
//remove(ArrayList* pAL, int index);


//remove (ArrayList* pAL, int index);

int main()
{
	
int arrayAll[4];
int num, i, flag=0, index, directory;
int *auxNum;
int dimension;
int empty;
char respuesta;

arrayAll[0]=3;
arrayAll[1]=5;
arrayAll[2]=7;


 ArrayList* pAL;

	for(i=0;flag==0;i++)
	{
		printf("\n MENU \n");
		printf("\n \'A\' - new array");
		printf("\n \'B\' - add");
		printf("\n \'C\' - mostrar");
		printf("\n \'D\' - removee");
		printf("\n \'E\' - set");
		printf("\n \'F\' - get");
		printf("\n \'G\' - push");
		printf("\n \'H\' - pop");
		printf("\n \'I\' - indexOf");
		printf("\n \'J\' - size");
		printf("\n \'K\' - contains");
		printf("\n \'L\' - containsAll");
		printf("\n \'M\' - isEmpty");
		printf("\n \'N\' - clone");
		printf("\n \'Q\' - sublist");
		printf("\n \'O\' - clear");
		printf("\n \'P\' - EXIT");
		
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta=toupper(respuesta);
		while(respuesta!='A' && respuesta!='B' && respuesta!='C' && respuesta!='D' && respuesta!='E' && respuesta!='F' && respuesta!='G' && respuesta!='H' && respuesta!='I' && respuesta!='J' && respuesta!='K' && respuesta!='L' && respuesta!='M' && respuesta!='N' && respuesta!='O' &&respuesta!='P'  && respuesta!='Q')
	    {
	    printf("\n error reingrese: ");
	 	fflush(stdin);
		scanf("%c", &respuesta);
		respuesta=toupper(respuesta);
	    } 
		switch(respuesta)
		{
			case 'A': 
			          
					  pAL=newArrayList();
					  printf("\n ArrayList creado.");
					   
  					   break;
  					   
  			case 'B':
  					 printf("\n Ingrese elemento a guardar: ");
  					 auxNum=(int*)malloc(sizeof(int));
  					 fflush(stdin);
  					 scanf("%d", auxNum);
  				 	 add(pAL, auxNum);
  				 	 break;
  				 	 
		 	 case 'C':
                      mostrar(pAL, pAL->_size);
                      break;
                 
             case 'D':
                  printf("ingrese la posicion de la array que desea eliminar");
                  fflush(stdin);
                  scanf("%d", &index);
                  if(index>pAL->_size)
                  {
                  	break;
				  }
                  removee(pAL, index);       
                  break; 
                  
        	case 'E':
        		     printf("\n ingrese elemento a guardar: ");
        		     auxNum=malloc(sizeof(int));
					 scanf("%d", auxNum);
        		     printf("\n ingrese la posicion del elemento a guardar: ");
        		     fflush(stdin);
        		     scanf("%d", &index);
        		     
        		     printf("\n %d", *auxNum);
        		     printf("\n %d", index);
        		     
        		     //void set(ArrayList* pAL, int index, void*element)
        		            		     
        		     set(pAL, index, auxNum);
        		     
        		     break;
                      
                      
            case 'F':
            		printf("\n ingrese la posicion del elemento ");
        		    fflush(stdin);
        		    scanf("%d", &index);
        		    
            		directory=(int)get(pAL, index);
            		
            		printf("%d", directory);
            		break;
            		
            case 'G':
            		printf("\n ingrese elemento a guardar: ");
            		auxNum=(void*)malloc(sizeof(int));
            		fflush(stdin);
            		scanf("%d", auxNum);
            		
            		printf("\n ingrese la posicion del elemento ");
        		    fflush(stdin);
        		    scanf("%d", &index);
        		    
            		
            		push(pAL, index, &auxNum);
            		break;
        	case'H':
        			// pop
        			printf("\n ingrese posicon: ");
        			fflush(stdin);
        			scanf("%d", &index);
        			auxNum=(int*)pop(pAL, index);
        			printf("%d", *auxNum);
					removee(pAL, index);
					printf("borrado");
        			
        			break;
           case'I':
		     	//indexof
				  printf("\n ingrese numero: ");
				  auxNum=malloc(sizeof(int));
				  scanf("%d", auxNum);
				  				  
				 index=(int)indexOf(pAL, *auxNum);	
				 if(index!=-1)
				 {
				 printf("\n posicion del numero: %d", index);
				 }
				 else
				 {
				 	printf("\n error al encontrarlo.");
				 }
		     	break;
					
            case 'J':
            	
            		dimension=size(pAL);
            		printf("\n tamaño del size: %d ", dimension);
				break;
				
			case'K': //contains
					printf("\n ingresar numero: ");
					fflush(stdin);
					auxNum=(void*)malloc(sizeof(void));
					scanf("%d", &auxNum);
					contains(pAL, auxNum);
					
					if(contains(pAL, auxNum))
					{
						printf("\n Existe.");
					}
					else
					{
						printf("\n No existe.");
					}
					break;
					
				
			case'L': //containsAll
			
						containsAll( pAL, arrayAll);
						
				break;
			case'M'://isEmpty
					
					empty=isEmpty(pAL);
						printf(" (1 = algo tiene 0=vacio): %d", empty);	
				break;
			case'N'://clone
					clone(pAL);
					printf("\n ArrayList clonado");
				break;
			case'Q'://sublist
			
					subList(pAL, 0, *(int*)pAL->reservedSize);
					printf("\n Done");
				
				break;
			case 'O'://clear
			clear(pAL);
			break;
			
			case 'P':
				flag=1;
				printf("\n gracias.. vuelva pronto");
				printf("\n \n");
				break;
		}	
		

    }



 
system("pause");
return 0;
}




ArrayList* newArrayList(void)
{
	ArrayList* auxAl;
	//x=(ArrayList)malloc(sizeof(ArrayList)*10);
	
	auxAl=(ArrayList*)malloc(sizeof(ArrayList));
	auxAl->_size=0;
	auxAl->pElements= malloc(sizeof(int)* 1);//auxAl->_size); 
	
	
		    /*auxAl->size=0;
			auxAl->add=add;
			auxAl->removee=removee;
			auxAl->set=set;
    		auxAl->push=push;
			auxAl->indexOf=indexOf;
			auxAl->_size=_size;
			auxAl->contains=contains;
			auxAl->containsAll=containsAll;
			auxAl->isEmpty=isEmpty;
			auxAl->clone=clone;
			auxAl->clear=clear;*/
	
	
	return auxAl;
}

void add(ArrayList* pAL, int* pInt )
{
		if(pAL->_size < pAL->reservedSize)
		{
            
            
			pAL->pElements[pAL->_size]=pInt;
			pAL->_size++;
		
		}

	else
	{
		
		pAL->pElements=realloc(pAL->pElements,sizeof(void*) * pAL->reservedSize);
		pAL->reservedSize=pAL->reservedSize+10;
		
			pAL->pElements[pAL->_size]=pInt;
			pAL->_size++;
	}
	
}

void deleteArray(ArrayList* pAL, int index)
{

	pAL=NULL;
	
}

void mostrar(ArrayList* pAL, int size)
{
  int i;
  for (i=0; i<size; i++)
  {
    printf(" : %d",*(int*)pAL->pElements[i]);   
  }    
         
}

void removee(ArrayList* pAL, int index)
{
   
     int i, flag=0;
     
     for(i=0;i<pAL->_size;i++)
     {
     	if(pAL->pElements[i]==pAL->pElements[index])
     	{
	     		for(i=i;i<pAL->_size;i++)
	     		{
	     		  	*(int*)pAL->pElements[index]=*(int*)pAL->pElements[index+1];
	     		  	
				}
				free(pAL->pElements[pAL->_size]);
				pAL->_size--;
				flag=1;
				break;
		}
		

	 
	}
	
	if(flag!=1)
	printf("\n error con el indice especificado.");
     
       
  //for(i=index;i<=pAL->_size;i++)
  //{
  //*(int*)pAL->pElements[index-1]=*(int*)pAL->pElements[index+1];
  //}

     
}

void set(ArrayList* pAL, int index, void*element)
{
	
//	printf("\n size: %d - reservedSize: %d", *(int*)pAL->_size, *(int*)pAL->reservedSize);
	
	/*	while(*(int*)pAL->_size >= *(int*)pAL->reservedSize)
	{
		
		pAL->pElements=realloc(pAL->pElements,sizeof(void*) * 10);
		pAL->reservedSize=pAL->reservedSize+10;
		
			//*((int*)(pAL->pElements[index]))=*(int*)element;
			//pAL->_size++;
			printf("a");
	}
	
		if(pAL->_size < pAL->reservedSize)
		{
            
            
			*((int*)(pAL->pElements[index+1]))=*(int*)element;
			pAL->_size++;
		
		}*/
		
		if(pAL->_size>=index)
		{
		*(int*)pAL->pElements[index]=*(int*)element;
		 pAL->_size++;
		}


}


ArrayList* get(ArrayList* pAL, int index)
{
	return pAL->pElements[index];
}

void push(ArrayList* pAL, int index, void* numero)
{
	while(pAL->_size >=pAL->reservedSize)
	{
		pAL->pElements=realloc(pAL->pElements,sizeof(void*) * pAL->reservedSize);
		pAL->reservedSize=pAL->reservedSize+10;
		
		pAL->pElements[index]=numero;
		pAL->_size++;
	}
	if(pAL->_size<pAL->reservedSize)
	{
	 pAL->pElements[index]=pAL->pElements[index+1];	                               //////////////////////////////////////////////////////
	}
}

void* pop(ArrayList* pAL, int index)
{
	int* Ppop;
	Ppop=pAL->pElements[index];
	removee(pAL, index);
	return Ppop;
}

int size(ArrayList* pAL)
{
	return pAL->_size;
}

int isEmpty(ArrayList* pAL)
{
	if(pAL->_size<1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int contains(ArrayList* pAL, void* elements)
{
int	flag=0;
int i;

	for(i=0;i<pAL->_size;i++)
	{
		
		if(pAL->pElements[i]==elements)
		{
			
				return 1;
				
		}
		
	}

	return 0;

}

int indexOf(ArrayList* pAL, int numero)
{
	int i, flag=0;
	for(i=0;i<*(int*)pAL->_size;i++)
	{
		if(numero==*(int*)pAL->pElements[i])
		{
			flag=1;
			return i;
			//break;
		}
	}
	if(flag==0)
	{
		printf("\n no se encontr/ó");
		return -1;
	}
	
}

ArrayList* clear(ArrayList* pAL)
{
	pAL->_size=0;
	free(pAL);
}

ArrayList* clone(ArrayList* pAL)
{
	ArrayList* aux=newArrayList();
	int i;
	for(i=0;i<pAL->_size;i++)
	{
		add(aux,pAL->pElements[i]);
	}

	return aux;

}

ArrayList* subList(ArrayList* pAL, int from, int to)
{
	int i;
	
	ArrayList* newOne;
	
	newOne=newArrayList();
	
	//newOne=clone( newOne);	
	
	for(i=from;i<=to;i++)
	{
		newOne->pElements[i-from]=pAL->pElements[i];
	}
	return newOne;
}

int containsAll(ArrayList* pAL, int arrayAll[])
{
	int i, j=0;
	/*for(i=0;i<pAL->_size-1;i++)
	for(j=i+1;pAL->_size;j++)
	{
		if(*(int*)pAL->pElements[i]==arrayAll->pElements[j])
		{
			printf("%d - ", pAL->pElements[i]);
			k++;
		}
	}*/
	printf("A");
	
	for(i=0;i<pAL->_size;i++)
	{
		if(*(int*)pAL->pElements[i]==arrayAll[0])
		{
			printf("B");
		 for(i=0;i<pAL->_size;i++)
		 {
		 	if(*(int*)pAL->pElements[i]==arrayAll[1])
		 	{
		 		printf("C");
			 for(i=0;i<pAL->_size;i++)
			 {
			   if(*(int*)pAL->pElements[i]==arrayAll[2])
			   {
			   	printf("\n coincide la obtencion de todos los elementos.");
			   	j=1;
			   }
			   		
			 }
		    }
		 }	
		}
	}
	
	if(j==0)
	{
		printf("\n hay elementos que no coinciden");
	}
	
}


