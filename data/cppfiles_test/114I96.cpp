#include <bits/stdc++.h>
using namespace std;
template <class val>
inline val gcd(val a, val b) {
  return (a ? gcd(b % a, a) : b);
}
template <class val>
inline val fmul(val a, val b, val m) {
  if (!b) return 0;
  if (!(b - 1)) return a;
  if (b % 2)
    return (fmul(a, b / 2, m) * 2 + a) % m;
  else
    return (fmul(a, b / 2, m) * 2) % m;
}
template <class val>
inline bool getBit(val pos, val mask) {
  return ((mask >> pos) & 1);
}
void fastio() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
void init() {
  freopen(
      "test"
      ".inp",
      "r", stdin);
  freopen(
      "test"
      ".out",
      "w", stdout);
}
const int N = int(1e6) + 1;
int pt(long long x) {
  int dem = 0;
  while (x > 0) {
    dem++;
    x /= 10;
  }
  return dem;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 10], dem = 0;
    unordered_map<long long, long long> mp;
    vector<long long> ve;
    mp.clear();
    ve.clear();
    int ok = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;
    for (int i = 2; i <= n; i++) {
      if (ok == 1) break;
      if (mp[a[i - 1]] == 1) ve.push_back(a[i]);
      for (auto t : ve) {
        if (dem == n / 2) {
          ok = 1;
          break;
        }
        if (t != a[i]) {
          dem++;
          cout << t << ' ' << a[i] << '\n';
        }
      }
    }
  }
  return 0;
}
