#include <bits/stdc++.h>
using namespace std;
const long long MAX18 = 1e18 + 5;
const int MOD = 1e9 + 5;
const int MAX9 = 1e9 + 5;
const int MAX = 1e6 + 5;
const int MAX5 = 1e5 + 5;
inline long long mygcd(long long x, long long y) {
  return x % y == 0 ? y : mygcd(y, x % y);
}
inline long long mylcm(long long x, long long y) { return x / mygcd(x, y) * y; }
inline long long mymax(long long x, long long y) { return x < y ? y : x; }
inline long long mymin(long long x, long long y) { return x > y ? y : x; }
inline long long mypow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
long long T, a[500], mi, n, m, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int tt = (1); tt <= (T); tt++) {
    map<int, int> M;
    map<int, int> sum;
    map<int, int> C;
    ans = 0;
    cin >> n >> m;
    for (int i = (1); i <= (m); i++) cin >> a[i];
    for (int i = (1); i <= (m); i++) M[a[i]]++, sum[a[i]]++;
    mi = M.begin()->second;
    for (auto it = sum.begin(); it != sum.end(); it++) {
      if (it != sum.begin()) it->second = mi + it->second;
      mi = it->second;
    }
    for (int i = (1); i <= (m); i++) {
      for (auto it = C.begin(); it != C.end(); it++) {
        if (it->first < a[i])
          ans += it->second;
        else
          break;
      }
      C[a[i]]++;
    }
    cout << ans << endl;
  }
  return 0;
}
