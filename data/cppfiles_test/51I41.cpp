#include <bits/stdc++.h>
using namespace std;
const long long int mod = (long long int)(998244353);
const long long int mod2 = (long long int)1e9 + 7;
long long int test = 1;
vector<long long int> read(int n) {
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void solve() {
  long long int i, j, k, m, n, cnt = 0, ans = 0, sum = 0;
  cin >> n;
  if (n & 1LL) {
    cout << n / 2 << " " << n / 2 + (n % 2) << "\n";
  } else {
    long long int l = 0, h = 1e9;
    while (l <= h) {
      long long int mid = l + (h - l) / 2;
      if (mid * (mid + 1) / 2 >= n) {
        ans = mid;
        h = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (ans * (ans + 1) / 2 == n) {
      cout << 0 << " " << ans << "\n";
    } else {
      long long int dif = ans * (ans + 1) / 2 - n;
      long long int l = 0, h = 1e9;
      while (l <= h) {
        long long int mid = l + (h - l) / 2;
        if (mid * (mid + 1) / 2 >= dif) {
          sum = mid;
          h = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      cout << -sum << " " << ans << "\n";
    }
  }
  test++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i = 1;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
