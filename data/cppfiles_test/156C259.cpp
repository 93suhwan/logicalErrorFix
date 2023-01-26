#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  long long ans = sum - k;
  long long dif = sum - k;
  long long last = 1;
  long long steps;
  if (dif <= 0) {
    cout << 0 << endl;
    return;
  }
  while (n - last > 0) {
    steps = (sum - k - a[n - last] + a[0]) / (last + 1);
    if ((sum - k - a[n - last] + a[0]) % (last + 1) &&
        (sum - k - a[n - last] + a[0]) > 0)
      steps++;
    steps = max((long long)0, steps);
    ans = min(ans, steps + last);
    sum -= a[n - last] - a[0];
    last++;
  }
  cout << ans << endl;
}
int main() {
  long long t = 1;
  fast();
  cin >> t;
  while (t--) solve();
  return 0;
}
