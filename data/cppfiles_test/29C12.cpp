#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e8;
const int maxn = 1e5 + 2;
void init() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n, 0);
  long long a = 0, b = 0;
  for (auto &x : arr) {
    cin >> x;
    if (x == 0) a++;
    if (x == 1) b++;
  }
  long long ans = 1LL << a;
  ans *= (long long)b;
  cout << ans << '\n';
}
int main() {
  init();
  int tc = 1;
  cin >> tc;
  while (tc) {
    solve();
    tc--;
  }
}
