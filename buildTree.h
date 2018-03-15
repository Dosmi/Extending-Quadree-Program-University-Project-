
// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node* parent );

// task 1
void destroyTheTree( Node* node );

// task 2
void growTree ( Node* node );

// task 3
Node *makeSpecificLevelFullTree(int level); // makes a Full Tree of a specified level
void makeBranch( Node* parent, int level);
void limitedGrowTree( Node* node, int limit);

// task 4

// monitors how many children are added once we have visited every leaf, and repeats the process if required.
void generateTree ( Node* node, double tolerance, int choice );

// visits every leaf node and calls the indicator function, adding children if required.
void growingIfPass ( Node* node, double tolerance, int choice, int* count);
