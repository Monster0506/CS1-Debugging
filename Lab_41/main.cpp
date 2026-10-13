// Expected output:
//   Inorder Traversal: 1 2 4 7 8 9 16 55 64 87 99
//   Preorder Traversal: 8 4 1 2 7 55 16 9 87 64 99
//   Postorder Traversal: 2 1 7 4 9 16 64 99 87 55 8
//   Find 16: Found
//   Find 5: Not Found
//   Find 99: Found
//   Depth of node 8: 0
//   Depth of node 99: 3
//   Depth of node 5: -1
//   Copy has 100: Yes
//   Original has 100: No
//   Assigned inorder: 1 2 4 7 8 9 16 55 64 87 99

#include <iostream>

#include "btree.hpp"

int main() {
  btree<int> tree;

  int elements[] = {8, 4, 55, 1, 7, 16, 87, 2, 9, 64, 99};
  for (int val : elements) {
    tree.insert(val);
  }

  tree.insert(8);   // duplicates are ignored
  tree.insert(99);

  std::cout << "Inorder Traversal: ";
  tree.inorder(std::cout);
  std::cout << std::endl;

  std::cout << "Preorder Traversal: ";
  tree.preorder(std::cout);
  std::cout << std::endl;

  std::cout << "Postorder Traversal: ";
  tree.postorder(std::cout);
  std::cout << std::endl;

  int find_elements[] = {16, 5, 99};
  for (int val : find_elements) {
    std::cout << "Find " << val << ": "
              << (tree.find(val) ? "Found" : "Not Found") << std::endl;
  }
  std::cout << "Depth of node 8: " << tree.findDepth(8) << std::endl;
  std::cout << "Depth of node 99: " << tree.findDepth(99) << std::endl;
  std::cout << "Depth of node 5: " << tree.findDepth(5) << std::endl;


  btree<int> copy(tree);
  copy.insert(100);
  std::cout << "Copy has 100: " << (copy.find(100) ? "Yes" : "No") << std::endl;
  std::cout << "Original has 100: " << (tree.find(100) ? "Yes" : "No") << std::endl;

  btree<int> assigned;
  assigned = tree;
  std::cout << "Assigned inorder: ";
  assigned.inorder(std::cout);
  std::cout << std::endl;

  return 0;
}
