-------------------------------------------------------------------------------
 Problem Statement:
-------------------------------------------------------------------------------
  Given a binary tree, convert the preorder traversal of the tree to a doubly 
  linked list.


-------------------------------------------------------------------------------
 Solution Explaination:
-------------------------------------------------------------------------------
  Current test case creates a full 4-level binary tree with each node's 
  values corresponding to the position of each node in a left-to-right BFS.  
  Note that complete trees can be represented as an array.

  buildTree() builds a tree from a provided integer array, skipping nodes
  with values less than zero.  This fuction does no error checking and assumes 
  the tree is well definied.

  treeToList() converts the tree to a doubly linked list by performing a 
  preorder traversal on the tree and adds a new element to the end of the 
  list at each new traversed tree node.

  Time complexity of treeToList() is O(n). It is equivalent to a simple 
  preorder DFS of the tree.
-------------------------------------------------------------------------------


Jason Zhao.  Nov 2016.

