#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
long long n, k, ans;
void solve() {
  ans = 1e15;
  cin >> n >> k;
  for (int i = 30; i >= 0; i--)
    ans = min(ans, ((n >> i) << i) ^ (((k >> i) + 1) << i));
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int __ = 1;
  cin >> __;
  while (__--) solve();
  return 0;
}
