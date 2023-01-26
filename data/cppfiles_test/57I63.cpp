#include <bits/stdc++.h>
using namespace std;
bool good(vector<long long> a, long long k) {
  long long n = a.size();
  for (long long i = 0; i < n; i++) {
    long long sum = 0;
    for (long long j = i; j < n; j++) {
      sum += a[j];
      if (sum == k) return 1;
      if (sum > k) break;
    }
  }
  return 0;
}
vector<long long> r;
void gen(long long i, long long second, long long n, long long k) {
  if (i == n) {
    if (second != 0) return;
    if (!good(r, k)) {
      for (long long i : r) cout << i << " ";
      cout << '\n';
      exit(0);
    }
    return;
  }
  if (second == 0) return;
  for (long long j = 1; j <= second; j++) {
    r[i] = j;
    second -= j;
    gen(i + 1, second, n, k);
    second += j;
  }
}
void solve() {
  long long second, n, k;
  cin >> second >> n >> k;
  if (second >= (n / k * 2 * k + n - n / k * k)) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
