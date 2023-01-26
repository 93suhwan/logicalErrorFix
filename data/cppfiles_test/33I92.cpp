#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int check[600] = {}, pre[600] = {};
  set<int> s;
  s.insert(0);
  check[0]++;
  for (int i = 0; i < n; i++) {
    check[a[i]]++;
    s.insert(a[i]);
    for (int j = 1; j < 512; j++) {
      if (check[j]) {
        if (pre[j] < a[i]) {
          pre[j] = a[i];
          int k = a[i] ^ j;
          check[k]++;
          s.insert(k);
        }
      }
    }
  }
  cout << s.size() << '\n';
  for (int i : s) cout << i << ' ';
}
