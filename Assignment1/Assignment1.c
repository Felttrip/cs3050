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

#include <stdio.h>

//structure for adjacency node, each vertex will have its own set of nodes
typedef struct _aNode{
    int index;  //index of vertex
    struct node *nextPtr; //pointer for next vertex
}aNode;                                                                   

//function prototypes
int readInput(char *filename);
void buildList(aNode *node, int nextV);

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
  if(readInput(argv[1])) //if file fails to read exit program
    return 1;

  else
    printf("good open");
  
  

  return 0;
}

//function to read input
int readInput(char *filename)
{
  //Needed variables
  FILE *fPtr;  //File pointer
  int v1, v2;  //Variables to represent verticies
  
  //Attempt to open file
  if((fPtr=fopen(filename,"r"))==NULL)
  {
    printf("Error reading file, exiting now\n"); 
    return 1; //return 1 if error
  }  
return 0;
}
