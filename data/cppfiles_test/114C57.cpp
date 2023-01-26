#include <bits/stdc++.h>
using namespace std;
struct Node {
  map<int, int> child;
};
struct Trie {
  Trie() { root = fetchNode(); }
  int fetchNode() {
    nodes.push_back(Node());
    return nodes.size();
  }
  void insert(const vector<int>& v) {
    int current = root;
    for (int b : v) {
      if (nodes[current - 1].child.find(b) == nodes[current - 1].child.end()) {
        nodes[current - 1].child[b] = fetchNode();
      }
      current = nodes[current - 1].child[b];
    }
  }
  int getNextChild(int current, int b) {
    if (nodes[current - 1].child.find(b) == nodes[current - 1].child.end()) {
      return 0;
    } else {
      return nodes[current - 1].child[b];
    }
  }
  int root;
  vector<Node> nodes;
} trie;
int n;
vector<vector<int>> a;
vector<vector<int>> memo;
int Dp(int i, int node) {
  if (i == n) {
    if (node != 0) {
      return INT_MIN;
    } else {
      return 0;
    }
  }
  int& ret = memo[i][node];
  if (ret != -1) {
    return ret;
  }
  if (node == 0) {
    ret = a[i].back() + Dp(i + 1, 0);
  } else {
    ret = INT_MIN;
    for (int j = (int)a[i].size() - 1; j >= 0; --j) {
      int nextNode = trie.getNextChild(node, j + 1);
      ret = max(ret, a[i][j] + Dp(i + 1, nextNode));
      if (nextNode == 0) {
        break;
      }
    }
  }
  return ret;
}
void Trace(int i, int node) {
  if (i == n) {
    return;
  }
  if (node == 0) {
    cout << a[i].size() << " ";
    Trace(i + 1, 0);
  } else {
    for (int j = (int)a[i].size() - 1; j >= 0; --j) {
      int nextNode = trie.getNextChild(node, j + 1);
      int cost = a[i][j] + Dp(i + 1, nextNode);
      if (Dp(i, node) == cost) {
        cout << j + 1 << " ";
        Trace(i + 1, nextNode);
        break;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    a[i].resize(c);
    for (int j = 0; j < c; ++j) {
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  while (m--) {
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    trie.insert(b);
  }
  memo.assign(n, vector<int>(trie.nodes.size() + 1, -1));
  Dp(0, 1);
  Trace(0, 1);
  return 0;
}
