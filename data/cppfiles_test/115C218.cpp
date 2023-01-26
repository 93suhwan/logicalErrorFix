#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long a = 0;
    cin >> a;
    v.push_back(a);
  }
  long long s = k / n;
  long long e = k;
  while (s <= e) {
    long long mid = s + (e - s) / 2;
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++) {
      if (v[i] + mid > v[i + 1]) {
        ans = ans + (v[i + 1] - v[i]);
      } else {
        ans = ans + mid;
      }
    }
    ans = ans + mid;
    if (ans >= k) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
