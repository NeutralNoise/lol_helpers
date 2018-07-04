//Bradley Macdonald
//2018
#include <iostream>
#include "../BinaryTree.h"


int main() {

  std::cout << "Binary Tree example\n";

  BinaryTree<int> tree;

  for(int i = 0; i < 100; i++) {
      TreeNode<int> * tmp = new TreeNode<int>;

      if(i <= 50) {
        tmp->id = i + 50;
      }
      else {
        tmp->id = i - 50;
      }
      tmp->val = 90 + i;
      tree.AddNode(tmp);
  }

  tree.Traverse();

  return 0;
}
