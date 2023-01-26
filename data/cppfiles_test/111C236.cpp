#include <bits/stdc++.h>
using namespace std;
int find(int a, vector<int>& parent) {
  if (parent[a] == a) return a;
  return parent[a] = find(parent[a], parent);
}
void unions(int i, int j, vector<int>& parent, vector<int>& sz) {
  i = find(i, parent);
  j = find(j, parent);
  if (i == j) return;
  if (sz[i] > sz[j]) {
    swap(i, j);
  }
  parent[j] = i;
  sz[j] += sz[i];
}
void paranthesis(vector<string>& res, string s, int open, int close, int n) {
  if (s.length() == 2 * n) {
    res.push_back(s);
    return;
  }
  if (open < n && res.size() < n) paranthesis(res, s + "(", open + 1, close, n);
  if (close < open && res.size() < n)
    paranthesis(res, s + ")", open, close + 1, n);
}
void solve() {
  int n;
  cin >> n;
  vector<string> res;
  paranthesis(res, "", 0, 0, n);
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
