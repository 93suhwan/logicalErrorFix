#include <bits/stdc++.h>
using namespace std;
void init_code() {}
void reverse(string& s) {
  int i = 0, j = s.length() - 1;
  while (i < j) {
    swap(s[i], s[j]);
    i++;
    j--;
  }
}
void solve();
int main() {
  init_code();
  ios::sync_with_stdio(0);
  solve();
}
int l(int b, int a) { return log(a) / log(b); }
void dfs(vector<vector<int> >& e, int node, vector<bool>& v) {
  v[node] = true;
  for (int i = 0; i < e[node].size(); i++) {
    if (!v[e[node][i]]) {
      dfs(e, e[node][i], v);
    }
  }
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v;
    int c = 1, ind = 0, si = 0, mc = INT_MAX;
    for (int i = 1; i <= n; i++) {
      if (i == n || s[i] != s[i - 1]) {
        v.push_back(c);
        if (c < mc) {
          mc = c, si = ind;
        }
        c = 0;
        ind = i;
      }
      c++;
    }
    if (v.size() % 2 == 1) {
      cout << s << endl;
      continue;
    }
    while (mc--) {
      if (s[si] == 'b')
        s[si] = 'a';
      else
        s[si] = 'b';
      si++;
    }
    cout << s << endl;
  }
}
