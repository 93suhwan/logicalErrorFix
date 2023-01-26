#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> arr;
bool go(long long m) {
  vector<long long> a(n, 0);
  vector<long long> cnt = arr;
  for (long long i = n - 1; i >= 2; i--) {
    long long b = max((long long)0, min(cnt[i] + a[i] - m, cnt[i]));
    long long d = b / 3;
    a[i - 2] += 2 * d;
    a[i - 1] += d;
    cnt[i] -= 3 * d;
  }
  for (long long i = 0; i < n; i++) {
    if (cnt[i] + a[i] < m) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cin >> n;
    arr = vector<long long>(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long s = 0;
    long long e = 1e9;
    long long ans = -1;
    while (s <= e) {
      long long mid = s + (e - s) / 2;
      if (go(mid)) {
        ans = mid;
        s = mid + 1;
      } else
        e = mid - 1;
    }
    cout << ans << '\n';
  }
}
