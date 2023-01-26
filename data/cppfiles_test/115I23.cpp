#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
long long n, h;
bool good(long long x, vector<long long>& v) {
  long long cnt(0);
  for (int i = 0; i < n - 1; ++i) {
    cnt += min(x, v[i + 1] - v[i]);
  }
  cnt += x;
  return cnt >= h;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    vector<long long> v(n);
    for (auto& x : v) cin >> x;
    long long r = 1e9;
    long long l = 0;
    while (r > l + 1) {
      long long m = (l + r) >> 1;
      if (good(m, v))
        r = m;
      else
        l = m;
    }
    cout << r << "\n";
  }
  return 0;
}
