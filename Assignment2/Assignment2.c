/*--------------------->Machine Problem 2<---------------------+
 * NAME:      Nathaniel Thompson                               !
 * COURSE:    Advanced Algorithm Design                        !
 * PROFESSOR: Y. Saab                                          !
 * TERM:      Fall, 2013                                       !
 * PROJECT:   Machine Problem 2                                !
 * FILENAME:  Assignment2.c                                    !
 *                                                             !
 * OBJECTIVE                                                   !
 *   The objective of this program is to determine whether     !
 *   a graph G is sortable by the defined paramiters in the    !
 *   assignment document.                                      !
 *                                                             !
 * IDEA                                                        !
 *   Create a adjacency list, a source array and a color array.!
 *   Starting with a source vertex do a DFS and color the      !
 *   respective verticies grey or black.  After the DFS is     !
 *   compleated scan through the color list to find any white  !
 *   verticies.  If there are unvisited vertecies then the     !
 *   Graph can not be sorted. This will run in linear time     !
 *   because DFS will be compleated in linerar time and the    !
 *   single scan of the color array will be compleated in      !
 *   linear time giving a combined complexity of O(2n).        !
 *-------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#define MAXV 50

//structure for adjacency node, each vertex will have its own set of nodes
typedef struct _aNode{
    int index;  //index of vertex
    struct _aNode *nextPtr; //pointer for next vertex (not used for this assignment but my be used later)
}aNode;                                                                   

//structure for color of vertecies
typedef struct _dfsVert{
    int color; // 0 is white, 1 is grey, 2 is black
    
}dfsVerts;

//function prototypes
int readInput(char *filename); //reads input
int buildList(int v1, int v2); //builds list
void dfsVisit(int index);  //visits verts in DFS
void DFS(void);  //Begins DFS
int walk(void);  //used for debuging
void print(void);//used for debuging

//global array
aNode **array; //adjacency list
int *sourceArr; //array of sources
dfsVerts *cVerts;  //verts for coloring purposes

//global count for the array, this keeps track of the size of the array;
int max;

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
  }

  //print();  //debug code

  
  DFS();

  //check if we have unvisited vertecies
  int flag = 0;
  for(i=1;i<=max;i++)
  {
    if(cVerts[i].color==0)
    {
      flag = 1;
      printf("NO");
      break;
    }
  }
  if(flag==0)
    printf("Yes");

  return 0;
}

//function to read input
int readInput(char *filename)
{
  //Needed variables
  FILE *fPtr;  //File pointer
  int v1; 
  int v2;  //Variables to represent verticies
  max = 0;
  //Attempt to open file
  if((fPtr=fopen(filename,"r"))==NULL)
  {
    printf("Error reading file, exiting now\n"); 
    return 1; //return 1 if error
  }
  
  //read file line by line
  while(fscanf(fPtr,"%d %d",&v1,&v2)!=EOF)
  {
    if(v1>=max)  //keep track of the size of the array
      max=v1;
    if(v2>=max)
      max=v2; 
  }  
  
  //build source array, adjacency list array, and colored verts array
  sourceArr = malloc(sizeof(int)*max);
  array = malloc(sizeof(aNode)*max);
  cVerts = malloc(sizeof(dfsVerts)*max);
  
  int i;
  //set all the values in the sourceArr to 0
  for(i=0;i<max;i++)
  {
    sourceArr[i]=1;
  }

  //rewind and actualy read the doc
  rewind(fPtr);
  while(fscanf(fPtr,"%d %d",&v1,&v2)!=EOF)
  {
    sourceArr[v2]=0;  //sets non source indexies to 0
    buildList(v1,v2); //build adjaceny list
    
  }
  
return 0;
}


//list building function
int buildList(int v1, int v2)
{
  if(array[v1]==NULL)//check to see if vertex has been initialized
  {
    aNode *tempVert = malloc(sizeof(aNode)); //create vertex 1
    tempVert->index=v1;                      // set index
    aNode *tempVert2 = malloc(sizeof(aNode));//create vertex 2
    tempVert2->index = v2;                   // set index
    tempVert2->nextPtr = NULL;               //make index 2 pointer null      
    tempVert->nextPtr = tempVert2;           // have next point to vert 2
    array[v1]=tempVert;                      //set corisponding element in array
    cVerts[v1].color = 0;                   //set color to white 
    return 0;
  }
  
  else //edge already exists
  {

    aNode *tempVert = malloc(sizeof(aNode)); //create vertex
    tempVert->index = v2;                   //set index
    tempVert->nextPtr = NULL;               //set next ptr
    aNode *curr=array[v1];                  //initialize curr pointer
    while(curr->nextPtr!=NULL) // step through adjacency list untill the end is reached
    {
      curr=curr->nextPtr;
    }
    curr->nextPtr=tempVert;
  }

  if(array[v2]==NULL)//check to see if v2 has been created from connecting vertex
  {
    aNode *tempVert = malloc(sizeof(aNode));//create vertex
    tempVert->index=v2;                     //set index
    tempVert->nextPtr=NULL;                 //set pointer to null
    array[v2]=tempVert;                    // put in array
    cVerts[v2].color = 0;                  //set color to white
    return 0;

  }
  return 0;
}

//DFS
void DFS(void)
{
  int i;
  //do a DFS for every source vertex listed
  for(i=1;i<=max;i++)
  {
    if(sourceArr[i]==1)
    {
      dfsVisit(i);
    }
  }
}

//DFS Visit
void dfsVisit(int index)
{
  aNode *curr = array[index]; //curr pointer = vertecie sent
  cVerts[index].color = 1; //set grey
  while(curr->nextPtr!=NULL) //while loop to DFS
  {
    
    if(cVerts[curr->nextPtr->index].color == 0) //if the next vertex is white
    { 
      dfsVisit(curr->nextPtr->index);  //visit it
    }
    curr=curr->nextPtr; //next vert
  }
  cVerts[curr->index].color = 2; //set color to black

}

//print function for debuging
void print(void)
{
  aNode *curr;
  int i;
  printf("Adjacency List\n");
  for(i=1;i<=max;i++)
  {
    curr = array[i];
    while(curr!=NULL)
    {
      printf("%d -> ",curr->index);
      curr=curr->nextPtr;
    }
    printf("\n");
  }
  
  printf("\n Source List\n");
  for(i=1;i<=max;i++)
  {
    if(sourceArr[i]==1)
    {
      printf("%d\n",i);
    }
  }

  printf("\n color list\n");
  for(i=1;i<=max;i++)
  {
    if(cVerts[i].color==0)
      printf("%d = white, ",i);
    if(cVerts[i].color==1)
      printf("%d = grey, ",i);
    if(cVerts[i].color==2)
      printf("%d = black, ",i);
  }

}

//walk used for debuging
int walk(void)
{ 
  int next = max;  //set the starting vertex to max(a known vertex)
  int count = 0;
  do
  {
    next=array[next]->index;
    count++;
  }
  while(next!=max);
  
  if(count==max)
    printf("YES");
  else
    printf("NO");
return 0;
}
