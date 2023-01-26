#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
bool vis[maxn];
long long a[maxn], b[maxn], c[maxn];
bool check(long long x, long long n) {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
    c[i] = 0;
  }
  for (int i = n; i >= 3; i--) {
    long long temp = max(min(b[i], b[i] + c[i] - x), 0ll) / 3ll;
    b[i] -= temp * 3;
    c[i - 1] += temp;
    c[i - 2] += temp * 2;
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] + c[i] < x) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = 0, r = 1e18;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid, n))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l - 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
