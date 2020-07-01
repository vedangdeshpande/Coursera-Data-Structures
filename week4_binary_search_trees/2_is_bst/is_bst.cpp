#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool recIsBinarySearchTree(int i, const vector<Node>& tree)
{
  bool a = true;
  bool b = true;

  if(tree[i].left != -1)
  {
    if(tree[tree[i].left].key < tree[i].key)
    {
      a = recIsBinarySearchTree(tree[i].left, tree);
    }
    else
    {
      return false;
    }
  }

  if(tree[i].right != -1)
  {
    if(tree[tree[i].right].key > tree[i].key)
    {
      b = recIsBinarySearchTree(tree[i].right, tree);
    }
    else
    {
      return false;
    }
  }

  return a && b ;
}

  void in_orderRec(const vector<Node>& tree, int i, vector<int> &result)
  {
    if(tree[i].left != -1)
    {
      in_orderRec(tree, tree[i].left, result);
    }
    result.push_back(tree[i].key);
    if(tree[i].right != -1)
    {
      in_orderRec(tree, tree[i].right, result);
    }
  }

  vector <int> in_order(const vector<Node>& tree, vector<int> &result) {
    // Finish the implementation
    // You may need to add a new recursive method to do that

    in_orderRec(tree, 0, result);
    return result;
  }

bool IsBinarySearchTree(const vector<Node>& tree, int n) {
  // Implement correct algorithm here

  // return recIsBinarySearchTree(0, tree);

  vector<int> result;
  in_order(tree, result);
  int i;
  for(i=0; i<n-1; i++)
  {
    if(result[i] > result[i+1])
    {
      return false;
    }
  }

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) 
  {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if(nodes == 0)
  {
    cout << "CORRECT" << endl;
    return 0;
  }
  if(IsBinarySearchTree(tree, nodes))
  {
    cout << "CORRECT" << endl;
  } 
  else 
  {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
