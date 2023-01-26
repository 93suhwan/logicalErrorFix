#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 5;
long long num[MAX];
void solve() {
  int n, k;
  cin >> n >> k;
  long long res = 0;
  k++;
  for (int i = 30; i >= 0 && n < k; i--) {
    if (((n >> i) & 1) == ((k >> i) & 1)) continue;
    if ((k >> i) & 1) res = res | (1 << i), n = n | (1 << i);
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
