#include <bits/stdc++.h>
using namespace std;
bool conv(long long n, const vector<long long>& a, long long k) {
  long long counter = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    counter += (n / a[i]);
    n -= (n / a[i]) * a[i];
    if (n <= 0) {
      break;
    }
  }
  if (counter > k) {
    return true;
  }
  return false;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = (long long)pow(10, a[i]);
  }
  long long res = 0;
  long long counter = 0;
  for (int i = 0; i < n - 1; ++i) {
    res += ((a[i + 1] / a[i]) - 1) * a[i];
    counter += ((a[i + 1] / a[i]) - 1);
    if (counter > k) {
      while (counter > k) {
        res -= a[i];
        counter--;
      }
      res += a[i];
      counter++;
    }
  }
  if (counter <= k) {
    res += (k + 1 - counter) * a[n - 1];
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
