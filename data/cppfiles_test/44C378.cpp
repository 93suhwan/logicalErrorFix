#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
struct Modint {
  long long x;
  Modint() : x(0) {}
  Modint(long long x)
      : x(x >= 0 || x % mod == 0 ? x % mod : mod - (-x) % mod) {}
  Modint operator+(Modint a) { return Modint(*this) += a; }
  Modint operator-(Modint a) { return Modint(*this) -= a; }
  Modint operator*(Modint a) { return Modint(*this) *= a; }
  Modint operator/(Modint a) { return Modint(*this) /= a; }
  Modint operator-() { return Modint(0) - Modint(*this); }
  Modint& operator+=(Modint a) {
    x += a.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  Modint& operator-=(Modint a) {
    if (x < a.x) x += mod;
    x -= a.x;
    return *this;
  }
  Modint& operator*=(Modint a) {
    x = x * a.x % mod;
    return *this;
  }
  Modint operator/=(Modint a) {
    (*this) *= a.inv();
    return *this;
  }
  Modint inv() { return pow(mod - 2); }
  Modint pow(long long exp) {
    Modint ans(1), powed = (*this);
    while (exp) {
      if (exp % 2) ans *= powed;
      powed *= powed;
      exp /= 2;
    }
    return ans;
  }
  bool operator==(Modint a) { return x == a.x; }
  bool operator!=(Modint a) { return x != a.x; }
  bool operator<(Modint a) { return x < a.x; }
  bool operator<=(Modint a) { return x <= a.x; }
  bool operator>(Modint a) { return x > a.x; }
  bool operator>=(Modint a) { return x >= a.x; }
};
Modint min(Modint a, Modint b) { return Modint(min(a.x, b.x)); }
Modint min(vector<Modint> a) {
  Modint ans = a[0];
  for (long long i = long long(1); i < long long(a.size()); i++)
    if (a[i] < ans) ans = a[i];
  return ans;
}
Modint max(vector<Modint> a) {
  Modint ans = a[0];
  for (long long i = long long(1); i < long long(a.size()); i++)
    if (a[i] > ans) ans = a[i];
  return ans;
}
long long min(vector<long long> a) {
  long long ans = a[0];
  for (long long i = long long(1); i < long long(a.size()); i++)
    if (a[i] < ans) ans = a[i];
  return ans;
}
long long max(vector<long long> a) {
  long long ans = a[0];
  for (long long i = long long(1); i < long long(a.size()); i++)
    if (a[i] > ans) ans = a[i];
  return ans;
}
ostream& operator<<(ostream& os, Modint a) {
  os << a.x;
  return os;
}
istream& operator>>(istream& is, Modint& a) {
  long long x;
  is >> x;
  a = Modint(x);
  return is;
}
vector<int> getint(long long n) {
  vector<int> a(n);
  for (long long i = long long(0); i < long long(n); i++) cin >> a[i];
  return a;
}
vector<long long> getlong(long long n) {
  vector<long long> a(n);
  for (long long i = long long(0); i < long long(n); i++) cin >> a[i];
  return a;
}
void printvl(vector<long long> a) {
  for (auto v : a) cout << v << " ";
  cout << endl;
}
void printvm(vector<Modint> a) {
  for (auto v : a) cout << v << " ";
  cout << endl;
}
void printvi(vector<int> a) {
  for (auto v : a) cout << v << " ";
  cout << endl;
}
vector<Modint> fact(1e5 + 5);
Modint ncr(int n, int r) {
  Modint denom = fact[n - r] * fact[r];
  return fact[n] * denom.inv();
}
vector<int> parent;
vector<long long> numver;
void DSU(int n) {
  parent = vector<int>(n);
  numver = vector<long long>(n);
}
void make_set(int v) {
  parent[v] = v;
  numver[v] = 1;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (numver[a] < numver[b]) swap(a, b);
    parent[b] = a;
    numver[a] += numver[b];
  }
}
vector<long long> sieve;
void sv() {
  sieve = vector<long long>(1e3 + 1, 1);
  int limit = 1e3;
  for (long long num = long long(2); num < long long(limit + 1); num++) {
    int k = 2;
    if (sieve[num] == 0) continue;
    while (num * k <= limit) {
      sieve[num * k] = 0;
      k++;
    }
  }
}
const long long inf = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    int ans = 0;
    if ((a - b) & 1)
      ans = -1;
    else if (a == 0 && b == 0)
      ans = 0;
    else if (a == b)
      ans = 1;
    else
      ans = 2;
    cout << ans << endl;
  }
}
