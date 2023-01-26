#include <bits/stdc++.h>
using namespace std;
long gcd_calculator(long a, long b) {
  if (b == 0) return a;
  return gcd_calculator(b, a % b);
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void DFSUtil(int u, vector<int> adj[], vector<bool>& visited) {
  visited[u] = true;
  cout << u << " ";
  for (int i = 0; i < adj[u].size(); i++)
    if (visited[adj[u][i]] == false) DFSUtil(adj[u][i], adj, visited);
}
void DFS(vector<int> adj[], int V) {
  vector<bool> visited(V, false);
  for (int u = 0; u < V; u++)
    if (visited[u] == false) DFSUtil(u, adj, visited);
}
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};
void printPostorder(struct Node* node) {
  if (node == NULL) return;
  printPostorder(node->left);
  printPostorder(node->right);
  cout << node->data << " ";
}
void printInorder(struct Node* node) {
  if (node == NULL) return;
  printInorder(node->left);
  cout << node->data << " ";
  printInorder(node->right);
}
void printPreorder(struct Node* node) {
  if (node == NULL) return;
  cout << node->data << " ";
  printPreorder(node->left);
  printPreorder(node->right);
}
void printLevelOrder(Node* root) {
  if (root == NULL) return;
  queue<Node*> q;
  q.push(root);
  while (q.empty() == false) {
    Node* node = q.front();
    cout << node->data << " ";
    q.pop();
    if (node->left != NULL) q.push(node->left);
    if (node->right != NULL) q.push(node->right);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int n;
  string s1, s2;
  for (int i = 0; i < t; i++) {
    cin >> n;
    cin >> s1 >> s2;
    string x1 = "";
    long long ans = 0;
    for (int j = 0; j < n; j++) {
      if ((s1[j] == '1' && s2[j] == '0') || (s1[j] == '0' && s2[j] == '1')) {
        ans += 2;
        x1 += '3';
      } else {
        x1 += s1[j];
      }
    }
    int count_0 = 0;
    for (int j = 0; j < x1.length(); j++) {
      if (x1[j] == '0') {
        count_0++;
      }
    }
    int a[x1.length()];
    for (int j = 0; j < x1.length(); j++) {
      a[j] = 0;
    }
    int c1 = 0;
    for (int j = 0; j < x1.length(); j++) {
      if (x1[j] == '1') {
        if (j - 1 >= 0 && x1[j - 1] == '0' && a[j - 1] == 0) {
          c1++;
          a[j - 1] = 1;
        } else if (j + 1 < x1.length() && x1[j + 1] == '0' && a[j + 1] == 0) {
          c1++;
          a[j + 1] = 1;
        }
      }
    }
    count_0 = count_0 - c1;
    if (count_0 < 0) {
      count_0 = 0;
    }
    ans += (count_0 * 1) + (c1 * 2);
    cout << ans << "\n";
  }
}
