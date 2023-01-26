#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot;
map<long long, int> mp;
long long f[N][6];
int col[N];
int getid(string s) {
  if (s == "white")
    return 0;
  else if (s == "yellow")
    return 3;
  else if (s == "blue")
    return 1;
  else if (s == "green")
    return 4;
  else if (s == "red")
    return 2;
  else if (s == "orange")
    return 5;
}
void insert(long long u, int _col) {
  stack<long long> st;
  while (u) {
    st.push(u);
    u >>= 1;
  }
  while (!st.empty()) {
    int &p = mp[st.top()];
    if (!p) p = ++tot, assert(tot < N);
    st.pop();
    if (st.empty()) col[p] = _col;
  }
}
long long getans(int n) {
  if (n == 0) return 0;
  long long res = 1, sum = 4;
  for (int i = 1; i < n; i++) {
    sum = sum * sum % 1000000007;
    res = res * sum % 1000000007;
  }
  return res;
}
void dfs(long long u, int de) {
  int id = mp[u], idl = mp[id * 2], idr = mp[id * 2 + 1];
  if (!id) return;
  dfs(u * 2, de - 1);
  dfs(u * 2 + 1, de - 1);
  if (de == 1) {
    if (col[id] != -1)
      f[id][col[id]] = 1;
    else
      for (int i = 0; i < 6; i++) f[id][i] = 1;
    return;
  }
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 6; k++) {
        if ((col[id] != -1 && i != col[id]) || j % 3 == i % 3 || k % 3 == i % 3)
          continue;
        f[id][i] =
            (f[id][i] + (idl ? f[idl][j] : getans(de - 1)) *
                            (idr ? f[idr][k] : getans(de - 1)) % 1000000007) %
            1000000007;
      }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(col, -1, sizeof(col));
  cin >> n >> m;
  if (m == 0) {
    cout << getans(n) * 6 % 1000000007;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    long long x;
    string s;
    cin >> x >> s;
    insert(x, getid(s));
  }
  dfs(1, n);
  long long ans = 0;
  for (int i = 0; i < 6; i++) ans = (ans + f[1][i]) % 1000000007;
  cout << ans;
  return 0;
}
