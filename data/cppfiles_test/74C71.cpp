#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
using namespace std;
int n, b[1000010], app[1000010], a[1000010], rmask, rmask2;
bool fd = false;
vector<int> ap[2], seq[3];
map<int, int> mp[70];
set<int> st;
void dfs(int l, int r, int difc, int difs, int mask) {
  if (l > r) {
    mp[difc + 32][difs] = mask;
    return;
  }
  dfs(l + 1, r, difc, difs, mask << 2);
  dfs(l + 1, r, difc + 1, difs + b[l], (mask << 2) | 1);
  dfs(l + 1, r, difc - 1, difs - b[l], (mask << 2) | 2);
  return;
}
void solve(int l, int r, int difc, int difs, int mask) {
  if (l > r) {
    if (mp[32 - difc].count(-difs) && (mask || mp[32 - difc][-difs])) {
      rmask = mp[32 - difc][-difs];
      rmask2 = mask;
      fd = true;
    }
    return;
  }
  solve(l + 1, r, difc, difs, mask << 2);
  if (fd) {
    return;
  }
  solve(l + 1, r, difc + 1, difs + b[l], (mask << 2) | 1);
  if (fd) {
    return;
  }
  solve(l + 1, r, difc - 1, difs - b[l], (mask << 2) | 2);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i;
  cin >> n;
  memset(app, -1, sizeof(app));
  for (i = 0; i < n; i++) {
    cin >> b[i];
    app[b[i]] = i;
    ap[b[i] % 2].push_back(b[i]);
    st.insert(b[i]);
  }
  if (st.size() < n) {
    cout << "YES" << endl << "0 ";
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
      cout << (*it) << " ";
    }
    for (i = st.size() + 1; i < n; i++) {
      cout << "0 ";
    }
    return 0;
  }
  if (ap[0].size() >= 3) {
    int x = ap[0][0], y = ap[0][1], z = ap[0][2];
    a[0] = (x + y - z) / 2, a[1] = (x + z - y) / 2, a[2] = (y + z - x) / 2;
    for (i = 3; i < ap[0].size(); i++) {
      a[i] = ap[0][i] - a[0];
    }
    for (i = 0; i < ap[1].size(); i++) {
      a[i + ap[0].size()] = ap[1][i] - a[0];
    }
    cout << "YES" << endl;
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return 0;
  }
  if (ap[1].size() >= 2 && ap[0].size() > 0) {
    int x = ap[0][0], y = ap[1][0], z = ap[1][1];
    a[0] = (x + y - z) / 2, a[1] = (x + z - y) / 2, a[2] = (y + z - x) / 2;
    for (i = 1; i < ap[0].size(); i++) {
      a[i] = ap[0][i] - a[0];
    }
    for (i = 2; i < ap[1].size(); i++) {
      a[i + ap[0].size()] = ap[1][i] - a[0];
    }
    cout << "YES" << endl;
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return 0;
  }
  if (n < 4) {
    cout << "NO" << endl;
    return 0;
  }
  int onn = n;
  n = min(n, (int)27);
  dfs(0, n / 2 - 1, 0, 0, 0);
  solve(n / 2, n - 1, 0, 0, 0);
  if (!fd) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (i = n / 2 - 1; i >= 0; i--) {
    seq[rmask & 3].push_back(b[i]);
    rmask >>= 2;
  }
  for (i = n - 1; i >= n / 2; i--) {
    seq[rmask2 & 3].push_back(b[i]);
    rmask2 >>= 2;
  }
  for (i = n; i < onn; i++) {
    seq[0].push_back(b[i]);
  }
  a[0] = 0;
  for (i = 1; i < 2 * seq[1].size(); i++) {
    a[i] = seq[(i & 1) + 1][i / 2] - a[i - 1];
  }
  for (i = 0; i < seq[0].size(); i++) {
    a[i + 2 * seq[1].size()] = seq[0][i] - a[0];
  }
  for (i = 0; i < onn; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
