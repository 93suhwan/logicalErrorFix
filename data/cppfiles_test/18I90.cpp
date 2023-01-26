#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int a[12], n;
map<int, int> st;
void dfs(int u, int s) {
  if (u > n) {
    st[s]++;
    return;
  }
  dfs(u + 1, s + a[u]);
  dfs(u + 1, s);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  st.clear();
  dfs(1, 0);
  bool flag = false;
  for (auto &x : st)
    if (x.second >= 2) flag = true;
  puts(flag ? "YES" : "NO");
}
int main() {
  int T = 1;
  cin >> T;
  for (int turn = 1; turn <= T; turn++) solve();
}
