#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode {
 public:
  T data;
  std::vector<TreeNode<T>*> children;
  TreeNode(T data) { this->data = data; }
};
void print_tree(TreeNode<int>* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << ":";
  for (int i = 0; i < root->children.size(); i++) {
    cout << root->children[i]->data << ",";
  }
  cout << "\n";
  for (int i = 0; i < root->children.size(); i++) {
    print_tree(root->children[i]);
  }
}
int count_Nodes(TreeNode<int>* root) {
  int ans = 1;
  for (int i = 0; i < root->children.size(); i++) {
    ans += count_Nodes(root->children[i]);
  }
  return ans;
}
int max_Nodes(TreeNode<int>* root) {
  int ans = root->data;
  for (int i = 0; i < root->children.size(); i++) {
    ans = max(ans, max_Nodes(root->children[i]));
  }
  return ans;
}
int Sumof_Nodes(TreeNode<int>* root) {
  int ans = root->data;
  for (int i = 0; i < root->children.size(); i++) {
    ans += Sumof_Nodes(root->children[i]);
  }
  return ans;
}
int height_Nodes(TreeNode<int>* root) {
  int ans = 1;
  int max_ans = 0;
  for (int i = 0; i < root->children.size(); i++) {
    max_ans = max(max_ans, height_Nodes(root->children[i]));
  }
  ans += max_ans;
  return ans;
}
TreeNode<int>* Take_input() {
  int root_data;
  cin >> root_data;
  TreeNode<int>* root = new TreeNode<int>(root_data);
  std::queue<TreeNode<int>*> nodes;
  nodes.push(root);
  while (nodes.size() != 0) {
    TreeNode<int>* frontNode = nodes.front();
    nodes.pop();
    int num_child;
    cin >> num_child;
    for (int i = 0; i < num_child; i++) {
      int child_data;
      cin >> child_data;
      TreeNode<int>* child = new TreeNode<int>(child_data);
      frontNode->children.push_back(child);
      nodes.push(child);
    }
  }
  return root;
}
int f(int a, int b) {
  if (a - 2 < b) {
    return 1;
  } else {
    return f(9, 9);
  }
}
long long help[1000001];
void helper() {
  for (long long i = 0; i < 1000001; i++) {
    help[i] = i;
  }
  for (long long i = 2; i < 1000001; i++) {
    for (long long j = 2 * i; j < 1000001; j += i) {
      if (j == help[j]) {
        help[j] = i;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  do {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = i + 2;
    }
    for (auto x : a) {
      cout << x << " ";
    }
    cout << "\n";
  } while (--t);
  return 0;
}
