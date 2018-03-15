
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "tests.h"

// test functions

Node *makeFullTree()
{
  Node* head;
  int i;

  head = makeNode( 0.0,0.0, 0);
  makeChildren(head);

  for (i = 0; i < 4; i++)
  {
    makeChildren(head->child[i]);
  }
  return head;
}

Node *makeNonUniformTree()
{
  Node* head;
  int i,j;

  head = makeNode( 0.0,0.0, 0);
  makeChildren(head);

    for (i = 0; i < 2; i++)
    {
      makeChildren(head->child[i]);
      for (j = 0; j < 2; j++)
      {
        makeChildren(head->child[i]->child[j]);
      }
    }
    return head;
}


void task1()
{
   Node* head;
   head = makeNonUniformTree();

   destroyTheTree ( head );
}

void task2()
{
  Node* head;
  head = makeNonUniformTree();

  growTree( head );
  writeTree( head );
  destroyTheTree ( head );
}

void task3()
{
  Node* head;
  head = makeNonUniformTree();

  limitedGrowTree( head, 3 );
  writeTree( head );
  destroyTheTree ( head );
}

void task4()
{
  Node* head;
  head = makeSpecificLevelFullTree(2); // makes a full level 2 tree

  generateTree( head, 0.2, 1);

  writeTree( head );
  destroyTheTree ( head );
}
