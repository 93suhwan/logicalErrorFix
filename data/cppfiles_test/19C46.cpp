#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000007;
const long long INF = 1000000000000000;
void rec(unordered_map<long long, long long> &y, long long *arr, long long n,
         long long val) {
  if (n < 0) return;
  y[val - *arr]++;
  y[val + *arr]++;
  rec(y, arr + 1, n - 1, val - *arr);
  rec(y, arr + 1, n - 1, *arr + val);
  rec(y, arr + 1, n - 1, val);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  long long t;
  cin >> t;
  for (long long tno = 1; tno <= t; tno++) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    unordered_map<long long, long long> helper;
    rec(helper, a, n, 0);
    if (helper[0] >= 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
