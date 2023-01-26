#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int Mod = 998244353;
int T;
long long n;
long long a[N];
template <typename T>
T myceil(T x, T y) {
  return x / y + (x % y != 0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  vector<pair<long long, long long> > dpvec, tmp;
  for (int _ = 1; _ <= T; _++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    dpvec.clear();
    tmp.clear();
    tmp.emplace_back(a[n], 1);
    long long ans = 0;
    for (long long i = n - 1; i >= 1; i--) {
      dpvec.emplace_back(a[i], 1);
      long long last = a[i];
      for (auto [y, val] : tmp) {
        auto k = myceil(a[i], y);
        auto x = a[i] / (k);
        ans += i * val * (k - 1);
        ans %= Mod;
        if (last != x) {
          dpvec.emplace_back(x, val);
          last = x;
        } else {
          dpvec.back().second += val;
        }
      }
      tmp.swap(dpvec);
      dpvec.clear();
    }
    cout << ans << endl;
  }
  return 0;
}
