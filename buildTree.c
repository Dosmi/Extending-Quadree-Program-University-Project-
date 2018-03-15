
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "tests.h"

// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// function for task 1

void destroyTheTree( Node* node)
{
  int i;
  if(node->child[0] == NULL)
  {
    free(node);
  }
  else
  {
    for(i = 0; i < 4; i++)
    {
      destroyTheTree(node->child[i]);
    }

    free(node);
  }
}

// function for task 2

void growTree ( Node* node )
{
  int i;

  if (node->child[0] == NULL)
    makeChildren( node );
  else
  {
    for (i = 0; i < 4; i++)
    {
      growTree ( node->child[i] );
    }
  }
}

// the following two functions are to make specific Level Full Trees

Node *makeSpecificLevelFullTree(int level)
{
  Node* head;
  int i;

  head = makeNode( 0.0,0.0, 0);
  makeBranch(head,level);

  return head;
}

void makeBranch ( Node* parent, int level )
{
  int i;

  makeChildren( parent );
  if (parent->level < level-1)
  {
    for ( i = 0; i < 4; i++)
    { makeBranch(parent->child[i],level); }
  }
}

// function for task 3 (v)

void limitedGrowTree( Node* node, int limit)
{
  int i;

  if ( node->child[0] == NULL)
  // if node has no children...
  {
    if ( node->level < limit )
    // ... and does not exceed the limit
    { makeChildren( node ); }
    // create children
  }

  else
  {
    for ( i = 0; i < 4; i++)
    // otherwise grow the tree recursively
    { limitedGrowTree( node->child[i], limit ); }
  }
}

// following two functions are for task 4

// generateTree monitors how many children are added once we have visited every leaf, and repeats the process if required.
void generateTree ( Node* node, double tolerance, int choice )
{

  int count;
  do
  {
    count = 0;
    growingIfPass( node, tolerance, choice, &count );
  } while (count > 0);

}

// growingIfPass visits every leaf node and calls the indicator function, adding children if required.

void growingIfPass ( Node* node, double tolerance, int choice, int* count)
{
  int i;

  if (node->child[0] == NULL)
  {
    if (!indicator( node,  tolerance,  choice ) )
    {
      (*count)++;
      makeChildren( node );
    }
  }

  else
  {
    for ( i = 0; i < 4; i++)
    {
      growingIfPass ( node->child[i], tolerance, choice, count );
    }

  }

  return;
}
