#include <bits/stdc++.h>
using namespace std;
const double pie = acos(-1);
const double cd = 1e-9;
const long long mod = 1000000007;
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void _print() { cerr << "\n"; }
template <typename T>
void _print(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << "\n";
}
template <typename T, typename... hello>
void _print(T arg, const hello &...rest) {
  cerr << arg << ' ';
  _print(rest...);
}
long long dig_coun(long long n, long long x) {
  long long ans = 0;
  while (n > 0) {
    ans++;
    n /= x;
  }
  return ans;
}
void Sieve(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long mul(long long a, long long b) {
  a *= b;
  if (a >= mod) a %= mod;
  return a;
}
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
void solve(long long cas) {
  vector<long long> v;
  for (int i = 0; i < 7; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  sort((v).begin(), (v).end());
  if (v[0] + v[1] + v[2] == v[6]) {
    cout << v[0] << " " << v[1] << " " << v[2] << "\n";
  } else {
    cout << v[0] << " " << v[1] << " " << v[3] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solve(i);
  }
}
