#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
using namespace std;
struct Node {
  int p, size;
};
const int N = 1e6 + 10;
int n, m;
Node nodes[N];
void make() {
  for (int i = 1; i <= n * m; i++) {
    nodes[i].p = i;
    nodes[i].size = 1;
  }
}
int find(int x) {
  return nodes[x].p = (nodes[x].p == x ? x : find(nodes[x].p));
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return;
  }
  if (nodes[a].size > nodes[b].size) {
    swap(a, b);
  }
  nodes[a].p = b;
  nodes[b].size += nodes[a].size;
  nodes[a].size = 0;
}
void calc(int x, int i, int j) {
  if (((x & 1) == 0) && (j != 1)) {
    merge((i - 1) * m + j, (i - 1) * m + j - 1);
  }
  if (((x & 2) == 0) && (i != n)) {
    merge((i - 1) * m + j, i * m + j);
  }
  if (((x & 4) == 0) && (j != n)) {
    merge((i - 1) * m + j, (i - 1) * m + j + 1);
  }
  if (((x & 8) == 0) && (i != 1)) {
    merge((i - 1) * m + j, (i - 2) * m + j);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> n >> m;
  make();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x;
      calc(x, i, j);
    }
  }
  map<int, int> mark;
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp = find((i - 1) * m + j);
      if (!mark[tmp]) {
        mark[tmp] = true;
        res.push_back(nodes[tmp].size);
      }
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
