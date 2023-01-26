#include <bits/stdc++.h>
using namespace std;
long long mod(long long x, long long MOD) {
  if (x > MOD) x -= MOD;
  return x;
}
long long _ceil(long long x, long long y) { return x / y + (x % y != 0); }
void wrt() {
  cout << "\n";
  return;
}
template <typename T1, typename... T2>
void wrt(T1 x, T2... args) {
  ((cout << x << ' '), wrt(args...));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& i : v) os << i << " ";
  return os;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& e : v) in >> e;
  return in;
}
const long long MOD = 998244353;
const long long N = 1e6 + 5, inf = 1e18 + 2;
long long n, m, x, u, v, k, p, q, i, j;
string s, t;
long long ans;
long long a[N];
void solve() {
  cin >> n >> k;
  vector<long long> a(n);
  cin >> a;
  vector<long long> posx, negx;
  for (long long i = 0; i < (n); ++i)
    if (a[i] > 0)
      posx.push_back(a[i]);
    else
      negx.push_back(-a[i]);
  sort((posx).begin(), (posx).end());
  sort((negx).begin(), (negx).end());
  if (((long long)(posx).size()) && ((long long)(negx).size()) &&
      posx[((long long)(posx).size()) - 1] <
          abs(negx[((long long)(negx).size()) - 1]))
    swap(posx, negx);
  ans = 0;
  i = 0;
  long long val;
  if (((long long)(negx).size())) {
    val = negx[((long long)(negx).size()) - 1];
    while (i < ((long long)(negx).size())) {
      j = i;
      if (j + k - 1 < ((long long)(negx).size()))
        ans += 2 * negx[j + k - 1];
      else
        ans += 2 * negx[((long long)(negx).size()) - 1];
      i = j + k;
    }
  }
  i = 0;
  if (((long long)(posx).size())) {
    val = posx[((long long)(posx).size()) - 1];
    while (i < ((long long)(posx).size())) {
      j = i + k - 1;
      if (j < ((long long)(posx).size()) - 1) {
        if (val == posx[j] && j + k - 1 == ((long long)(posx).size()) - 1 &&
            k != 1)
          ans += 2 * posx[j - 1], i = j;
        else
          ans += 2 * posx[j], i = j + 1;
      } else
        ans += posx[((long long)(posx).size()) - 1], i = j + 1;
    }
  }
  wrt(ans);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
