#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const double PI = acos(-1);
const long long int INF = 1e8;
const long long int MAX = 200005;
long long int min(long long int a, long long int b) { return a < b ? a : b; }
long long int min(long long int a, long long int b, long long int c) {
  a = min(a, b);
  a = min(a, c);
  return a;
}
long long int max(long long int a, long long int b) { return a > b ? a : b; }
long long int max(long long int a, long long int b, long long int c) {
  a = max(a, b);
  a = max(a, c);
  return a;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int res = 1;
  a = a % m;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = ((a % m) * (a % m)) % m;
    b >>= 1;
  }
  return res;
}
long long int Ceil(long long int a, long long int b) {
  long long int res = a / b;
  if (a % b != 0) res++;
  return res;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const T &t : v) {
    os << t << " ";
  }
  os << '\n';
  return os;
}
long long int dxx[] = {1, 1, 0, -1, -1, -1, 0, 1};
long long int dyy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long int dx[] = {1, 0, -1, 0};
long long int dy[] = {0, 1, 0, -1};
struct pll {
  long long int x, y;
};
bool comp(pll a, pll b) {
  if (a.x == b.x)
    return a.y < b.y;
  else
    return a.x < b.x;
}
void io_code() {}
void solve(long long int the) {
  char ch;
  long double aa, bb, cc, dd, xx;
  string s1, s2, s3, s4, str;
  long long int i, j, a, b, c, d, k, n, m, l, r, x, y, z, low, high, mid,
      sum = 0, ans = 0, temp = 0, t, q;
  cin >> n;
  vector<long long int> v(n);
  cin >> v;
  a = 0;
  for (long long int i = 0; i < n; i++) {
    if (v[i] == 1) a++;
  }
  vector<long long int> v1;
  if (a == n) {
    v1.push_back(n + 1);
    for (long long int i = 1; i < n + 1; i++) {
      v1.push_back(i);
    }
    cout << v1;
    return;
  }
  long long int pre = 0;
  for (long long int i = 0; i < n; i++) {
    v1.push_back(i + 1);
    if (!pre && v[i] == 0) {
      if (i == n - 1 || v[i + 1] == 1) {
        pre = 1;
        v1.push_back(n + 1);
      }
    }
  }
  cout << v1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  io_code();
  long long int t = 1, c = 1;
  cin >> t;
  while (t--) {
    solve(c);
    c++;
  }
  return 0;
}
