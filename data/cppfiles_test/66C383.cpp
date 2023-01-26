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
bool okay(long long int n) {
  if (n % 3 == 0) return false;
  if (n % 10 == 3) return false;
  return true;
}
void solve(long long int the) {
  char ch;
  double aa, bb, cc, dd, xx;
  string s1, s2, s3, s4, str;
  long long int i, j, a, b, c, d, k, n, m, l, r, x, y, z, low, high, mid,
      sum = 0, ans = 0, temp = 0, t, q;
  vector<long long int> v;
  a = 1;
  while (v.size() < 1001) {
    if (okay(a)) {
      v.push_back(a);
    }
    a++;
  }
  cin >> t;
  while (t--) {
    cin >> k;
    cout << v[k - 1] << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  io_code();
  long long int t = 1, c = 1;
  while (t--) {
    solve(c);
    c++;
  }
  return 0;
}
