// Binary search tree with raw pointers (no classes).
// The tree built from the inserts below:
//
//            8
//          /   \
//         3     10
//        / \      \
//       1   6      14
//          / \    /
//         4   7  13
//
// Expected output:
//   inorder:  1 3 4 6 7 8 10 13 14
//   preorder: 8 3 1 6 4 7 10 14 13
//   find 6: yes
//   find 5: no
//   depth of 8: 0
//   depth of 4: 3
//   depth of 13: 3
//   depth of 99: -1

#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;
};

Node *insert(Node *root, int v); // returns the (possibly new) root
bool find(const Node *root, int v);
void inorder(const Node *root);
void preorder(const Node *root);
int findDepth(const Node *root, int v); // -1 if v is not in the tree
void destroy(Node *root);

int main() {
  Node *root = nullptr;
  int values[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  for (int i = 0; i < 9; i++) {
    root = insert(root, values[i]);
  }

  std::cout << "inorder:  ";
  inorder(root);
  std::cout << std::endl;
  std::cout << "preorder: ";
  preorder(root);
  std::cout << std::endl;

  std::cout << "find 6: " << (find(root, 6) ? "yes" : "no") << std::endl;
  std::cout << "find 5: " << (find(root, 5) ? "yes" : "no") << std::endl;
  std::cout << "depth of 8: " << findDepth(root, 8) << std::endl;
  std::cout << "depth of 4: " << findDepth(root, 4) << std::endl;
  std::cout << "depth of 13: " << findDepth(root, 13) << std::endl;
  std::cout << "depth of 99: " << findDepth(root, 99) << std::endl;

  destroy(root);
}

Node *insert(Node *root, int v) {
  if (root == nullptr) {
    Node *n = new Node;
    n->value = v;
    return n;
  }
  if (v < root->value) {
    root->left = insert(root->left, v);
  } else if (v > root->value) {
    root->right = insert(root->right, v);
  }
  return root;
}

bool find(const Node *root, int v) {
  if (root == nullptr) {
    return false;
  }
  if (v == root->value) {
    return true;
  }
  if (v < root->value) {
    return find(root->right, v);
  }
  return find(root->left, v);
}

void inorder(const Node *root) {
  if (root == nullptr) {
    return;
  }
  std::cout << root->value << " ";
  inorder(root->left);
  inorder(root->right);
}

void preorder(const Node *root) {
  if (root == nullptr) {
    return;
  }
  std::cout << root->value << " ";
  preorder(root->left);
  preorder(root->right);
}

int findDepth(const Node *root, int v) {
  if (root == nullptr) {
    return -1;
  }
  if (v == root->value) {
    return 0;
  }
  if (v < root->value) {
    return 1 + findDepth(root->left, v);
  }
  return 1 + findDepth(root->right, v);
}

void destroy(Node *root) {
  if (root == nullptr) {
    return;
  }
  delete root;
  destroy(root->left);
  destroy(root->right);
}
