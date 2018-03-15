
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "tests.h"

// main

int main( int argc, char **argv ) {

  int choice;
  printf("List of tasks:\n");
  printf("1. Delete tree:\n");
  printf("2. Grow tree\n");
  printf("3. Maximum tree level\n");
  printf("4. Grow tree with indicator\n");
  printf("Enter task number 1-4\n");

  scanf ("%d", &choice);

  switch (choice)
  {
    case 0:
        exit(0);

    case 1:
        task1();
        printf("Started from a non-uniform level 3 tree and deleted.\n");

    break;

    case 2:
        task2();
        printf("Started from a non-uniform level 3 tree and grew the tree once.\n");

    break;

    case 3:
        task3();
        printf("Started from a non-uniform level 3\n");

    break;

    case 4:
        task4();
        printf("Settled choice = 1, tolerance = 0.2 and started with full level 2 tree.\n");

    break;

    default:
        printf("Invalid task. Press 0 to exit the program.\n");

  }

/*
code for task 3 to know the type sizes

    printf("Size of Node      %d bytes\n", sizeof(Node) );
    printf("Size of level     %d bytes\n", sizeof(head->level) );
    printf("Size of xy        %d bytes\n", sizeof(head->xy) );
    printf("Size of child     %d bytes\n", sizeof(head->child) );
*/


  return 0;
}
