#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 5;
long long a[MAX];
long long b[MAX];
long long n;
bool check(long long mid) {
  for (long long i = 1; i <= n; i++) a[i] = b[i];
  for (long long i = n; i >= 3; i--) {
    if (a[i] < mid) return false;
    long long spare = a[i] - mid;
    spare = min(spare, b[i]);
    spare -= (spare) % 3;
    spare /= 3;
    a[i - 1] += spare;
    a[i - 2] += spare * 2;
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] < mid) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> b[i];
  long long ip = 0, ik = (long long)1e9 + 9;
  while (ip + 1 < ik) {
    long long mid = (ip + ik) >> 1;
    if (check(mid))
      ip = mid;
    else
      ik = mid;
  }
  cout << ip << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long z = 0; z < t; z++) solve();
  return 0;
}
