#include <bits/stdc++.h>
using namespace std;
vector<int> ds[300008];
bool vis[300008];
void solve(int t) {
  int i, j, n, m, k;
  string s;
  char ch;
  cin >> n;
  cin >> ch;
  cin >> s;
  int ans = 2;
  for (i = 0; i < n; i++) {
    if (s[i] != ch) break;
  }
  if (i == n) {
    cout << 0 << endl;
    return;
  }
  if (s[n - 1] == ch) {
    cout << 1 << endl << n << endl;
    return;
  }
  for (i = 0; i <= n + 2; i++) vis[i] = 0;
  for (i = 0; i < n; i++) {
    if (s[i] != ch) {
      for (j = ds[i + 1].size() - 1; j >= 0; j--) {
        vis[ds[i + 1][j]] = 1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    }
  }
  cout << 2 << endl << n - 1 << " " << n << endl;
  return;
}
int main() {
  int t, tt = 1, i, j;
  for (i = 1; i < 300008; i++) {
    for (j = i; j < 300008; j += i) {
      ds[j].push_back(i);
    }
  }
  cin >> tt;
  for (t = 1; t <= tt; t++) solve(t);
  return 0;
}
