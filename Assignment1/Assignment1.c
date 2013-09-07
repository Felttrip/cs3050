/*--------------------->Machine Problem 1<---------------------+
 * NAME:      Nathaniel Thompson                               !
 * COURSE:    Advanced Algorithm Design                        !
 * PROFESSOR: Y. Saab                                          !
 * TERM:      Fall, 2013                                       !
 * PROJECT:   Machine Problem 1 -- Machine Problem 1           !
 * FILENAME:  Assignment1.c                                    !
 *                                                             !
 * OBJECTIVE                                                   !
 *   The objective of this program is to determine whether     !
 *   a graph G is a simple cycle or not.                       !
 *                                                             !
 * IDEA                                                        !
 *   Create a adjacency list and then check said list for      !
 *   simple cycle criteria                                     !
 *-------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#define MAXV 50

//structure for adjacency node, each vertex will have its own set of nodes
typedef struct _aNode{
    int index;  //index of vertex
    struct _aNode *nextPtr; //pointer for next vertex
}aNode;                                                                   

//function prototypes
int readInput(char *filename);
int buildList(int v1, int v2);

//global array
aNode *array[MAXV];

//main function
int main(int argc,char **argv)
{
  //check for correct number of args
  if(argc!=2)
  {
    printf("USAGE: ./a.out <INPUT.txt>\n"); 
    return 0;
  }

  //read inputs
  int eCheck=readInput(argv[1]);
  if(eCheck==1) //if file fails to read exit program
    return 1;
  else if (eCheck==2)
  {
    printf("NO");
    return 1;
  }
  else
  {
    printf("good open");
    int i;
    aNode *curr;
    for(i=0;i<5;i++)
    {
      curr=array[i];
      while(curr!=NULL)
      {
        printf("%d ",curr->index);
        curr=curr->nextPtr;
      }
      printf("\n");
    }
  }
  
  

  return 0;
}

//function to read input
int readInput(char *filename)
{
  //Needed variables
  FILE *fPtr;  //File pointer
  int v1; 
  int v2;  //Variables to represent verticies
  
  //Attempt to open file
  if((fPtr=fopen(filename,"r"))==NULL)
  {
    printf("Error reading file, exiting now\n"); 
    return 1; //return 1 if error
  }
  
  //read file line by line
  while(fscanf(fPtr,"%d %d",&v1,&v2)!=EOF)
  {
   if(buildList(v1,v2))
     return 2;
  }  
return 0;
}

//list building function
int buildList(int v1, int v2)
{
  if(array[v1]==NULL)//check to see if vertex has been initialized
  {
    aNode *tempVert = malloc(sizeof(aNode));//create vertex
    tempVert->index=v2;                     //set index
    tempVert->nextPtr=NULL;                 //set pointer to null
    array[v1]=tempVert;
    return 0;
  }
  else //vertex already exists
  {
    /*aNode *tempVert = malloc(sizeof(aNode)); //create vertex
    tempVert->index = v2;                    
    tempVert->nextPtr = NULL;                 
    aNode *curr=array[v1];
    while(curr->nextPtr!=NULL) // step through adjacency list untill the end is reached
    {
      curr=curr->nextPtr;
    }
    curr->nextPtr=tempVert;*/
    //each edge is listed once so if a vertex has a seccond listing then it will fail
    return 1;
  }
  
}
