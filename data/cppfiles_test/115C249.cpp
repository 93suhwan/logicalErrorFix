#include <bits/stdc++.h>
const unsigned long long MAXN = 1e18;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    unsigned long long h;
    cin >> n >> h;
    vector<unsigned long long> a(n);
    for (unsigned long long &x : a) cin >> x;
    unsigned long long l = 1, r = MAXN;
    while (l <= r) {
      unsigned long long m = (l + r) / 2;
      unsigned long long sum = m;
      for (int i = 0; i < n - 1; ++i) {
        sum += min(m, a[i + 1] - a[i]);
      }
      if (sum < h)
        l = m + 1;
      else
        r = m - 1;
    }
    cout << r + 1 << '\n';
  }
}
