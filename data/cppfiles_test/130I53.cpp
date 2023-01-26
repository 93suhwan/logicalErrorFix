#include <bits/stdc++.h>
using namespace std;
template <class T = long long>
void readArray(vector<T> &v, long long n) {
  T a;
  for (long long i = 0; i < n; i = i + 1) {
    cin >> a;
    v.push_back(a);
  }
}
template <class T = long long>
void printArray(vector<T> &v, long long a = 0) {
  for (long long i = a; i < v.size(); i = i + 1) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
const long long mod = 998244353;
double logy(long long n, long long b) {
  if (b == 0) {
    return (-1);
  }
  if (n == 1) {
    return (0);
  }
  return ((double)log10(n) / (double)log10(b));
}
long long power(long long k, long long n, long long m = mod) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k) % m;
    }
    k = (k * k) % m;
    n = n / 2;
  }
  return (res);
}
double powerD(double k, long long n) {
  double res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k);
    }
    k = (k * k);
    n = n / 2;
  }
  return (res);
}
long long gcdExtend(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return (b);
  }
  long long x1, y1;
  long long g = gcdExtend(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return (g);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
const long long N = 1000009;
const long long M = 100005;
const long long inf = 1e9;
const long long minf = -1e9;
long long n, m, k, a1, a2, a3, h, t;
string str, str1, str2;
bool ok = true;
long long askQuery(long long a, long long b, long long c) {
  cout << ("?") << " " << (a + 1) << " " << (b + 1) << " " << (c + 1) << endl;
  long long x;
  cin >> x;
  return (x);
}
void naruto() {
  long long a, b, c, d, e, f, i, j, x, y, z, tt;
  long long p, q, u, w;
  cin >> n;
  x = y = -1;
  long long g[2];
  vector<long long> ans(n, -1);
  i = 2;
  z = askQuery(i, i - 1, i - 2);
  for (i = 3; i < n; i++) {
    p = askQuery(i, i - 1, i - 2);
    if (p != z) {
      g[z] = i - 3;
      g[p] = i;
      ans[i - 3] = z;
      ans[i] = p;
      break;
    }
    z = p;
  }
  z = 0;
  for (i = 0; i < n; i++) {
    if (ans[i] != -1) {
      z += (ans[i] == 0);
      continue;
    }
    ans[i] = askQuery(g[0], g[1], i);
    z += (ans[i] == 0);
  }
  cout << ("!") << " ";
  cout << z << " ";
  for (i = 0; i < n; i++) {
    if (!ans[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << ("") << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    naruto();
  }
}
