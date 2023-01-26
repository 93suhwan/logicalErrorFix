#include <bits/stdc++.h>
using namespace std;
void io(string in = "", string out = "", string err = "") {
  if (fopen(in.c_str(), "r")) {
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
  }
}
void conv();
int main() {
  io(""
     ".inp",
     ""
     ".out");
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q = 1;
  while (Q--) {
    conv();
  }
  return 0;
}
void dfs(int i, vector<int>& ord, const vector<array<int, 2>>& x) {
  if (i >= 0) {
    dfs(x[i][0], ord, x);
    ord.push_back(i);
    dfs(x[i][1], ord, x);
  }
}
bool dfs(int i, int cost, int& k, vector<bool>& dup, const vector<bool>& sp,
         const vector<array<int, 2>>& x) {
  if (i >= 0 && cost <= k) {
    if (dfs(x[i][0], cost + 1, k, dup, sp, x))
      dup[i] = 1;
    else if (sp[i])
      dup[i] = 1, k -= cost;
    if (dup[i]) dfs(x[i][1], 1, k, dup, sp, x);
    return dup[i];
  }
  return 0;
}
void conv() {
  int N, K;
  string c;
  cin >> N >> K >> c;
  vector<array<int, 2>> x(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> x[i][j];
      --x[i][j];
    }
  }
  vector<int> ord;
  dfs(0, ord, x);
  vector<bool> sp(N, 0);
  char lst = c[ord.back()];
  for (int i = N - 2; i >= 0; --i) {
    int u = ord[i], v = ord[i + 1];
    if (c[u] != c[v]) lst = c[v];
    if (c[u] < lst) sp[u] = 1;
  }
  vector<bool> dup(N, 0);
  dfs(0, 1, K, dup, sp, x);
  for (int i : ord) {
    for (int t = 1 + dup[i]; t--;) {
      cout << c[i];
    }
  }
}
