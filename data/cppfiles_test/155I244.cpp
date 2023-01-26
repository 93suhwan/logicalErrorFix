#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n, c1 = 1, z = 0, o = 0;
    cin >> n;
    int a[n], b[n], f[200002];
    memset(f, 1, 200002);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '0')
        z++;
      else
        o++;
    if (z != n && o != n) {
      for (int i = 0; i < n; i++)
        if (s[i] == '0')
          if (b[i] <= z) f[b[i]] = 0;
      for (int i = 0; i < n; i++)
        if (s[i] == '1')
          if (b[i] > z) f[b[i]] = 0;
      int k = 1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
          if (f[b[i]] == 0)
            ;
          else {
            while (f[k] == 0) k++;
            b[i] = k++;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          if (f[b[i]] == 0)
            ;
          else {
            while (f[k] == 0) k++;
            b[i] = k++;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << '\n';
  }
  return 0;
}
