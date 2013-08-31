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
    struct node *next; //pointer for next vertex
}aNode;                                                                   

//function prototypes
void readInput(char *filename);
void buildList(aNode *node, int nextV);

//main function
int main(int argc,char **argv)
{
return 0;
}
