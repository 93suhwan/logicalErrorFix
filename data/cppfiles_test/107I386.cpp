#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;
const long long N = 2e5 + 5;
const long long M = 1e9 + 7;
bool chk(vector<long long> a, long long x, long long y) {
  long long A = 0, B = 0;
  for (long long i = 2; i < a.size(); i++)
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
      A++;
    else if (a[i] < a[i - 1] && a[i] < a[i + 1])
      B++;
  if (A == x && B == y) return 1;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long tests;
  cin >> tests;
  while (tests--) {
    vector<long long> a;
    long long n, x, y;
    bool ok = 0;
    cin >> n >> x >> y;
    if (n == 2) {
      if (!x && !y)
        cout << "1 2\n";
      else
        cout << "-1\n";
      continue;
    }
    if (abs(x - y) > 1 || x + y > n - 2) {
      cout << "-1\n";
      continue;
    }
    if (x >= y) {
      long long l = 1;
      long long r = n;
      while (l <= r) {
        a.push_back(l++);
        if (l > r) break;
        a.push_back(r--);
      }
      long long idx = 1 + 2 * y;
      if (x > y) idx++;
      sort(a.begin() + idx, a.begin() + n);
    } else {
      long long l = 1;
      long long r = n;
      while (l <= r) {
        a.push_back(r--);
        if (l > r) break;
        a.push_back(l++);
      }
      long long idx = 2 * y;
      sort(a.begin() + idx, a.begin() + n);
    }
    for (auto h : a) cout << h << " ";
    cout << "\n";
  }
}
