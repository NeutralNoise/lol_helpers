//Bradley Macdonald
//2018
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "../BinaryTree.h"


int main() {

  std::cout << "Binary Tree example\n";
  BinaryTree<int> tree;

  unsigned long long id = rand() % 2000;

  for(int i = 0; i < 100; i++) {
    TreeNode<int> * tmp = new TreeNode<int>;
    //search for an id we don't have yet.
    while(tree.Search(id) != nullptr) {
      id = rand() % 2000;
    }
    tmp->id = id;
    tmp->val = rand() % 100 + 1;
    tree.AddNode(tmp);
  }

  tree.Traverse();

  return 0;
}
