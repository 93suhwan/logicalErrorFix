#include <bits/stdc++.h>
using namespace std;
void fIO() { freopen("input.txt", "r", stdin); }
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (auto &&i : v) {
    os << i << '\n';
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &&i : v) {
    os << i << ' ';
  }
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (size_t i = 0; i < v.size(); i++) {
    is >> v[i];
  }
  return is;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U> &p1, const pair<T, U> &p2) {
  return {p1.first + p2.first, p1.second + p2.second};
}
long long powx(long long a, long long b, long long mod) {
  long long ans = 1;
  a = a % mod;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long powll(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a);
    a = (a * a);
    b >>= 1;
  }
  return ans;
}
long long gcdx(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcdx(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long ncrx(long long n, long long r, long long mod) {
  r = min(r, n - r);
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= (n - i + 1);
    ans %= mod;
    ans *= powx(i, mod - 2, mod);
    ans %= mod;
  }
  return ans;
}
long long ncr(long long n, long long r) {
  r = min(r, n - r);
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= (n - i + 1);
    ans /= i;
  }
  return ans;
}
double pi = acos(-1.0);
long long mod = 1000000007;
void testCase() {
  long long n;
  cin >> n;
  vector<vector<long long>> r(n, vector<long long>(5));
  cin >> r;
  vector<long long> top_idx(5, 0);
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      if (r[i][j] < r[top_idx[j]][j]) {
        top_idx[j] = i;
      }
    }
  }
  for (auto &&top : top_idx) {
    bool best = true;
    for (long long i = 0; i < n; i++) {
      if (i == top) {
        continue;
      }
      long long better_at = 0;
      for (long long j = 0; j < 5; j++) {
        if (r[i][j] > r[top][j]) {
          better_at++;
        }
      }
      if (better_at < 3) {
        best = false;
        break;
      }
    }
    if (best) {
      cout << top + 1 << '\n';
      return;
    }
  }
  cout << "-1\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long tc = 0; tc < t; ++tc) {
    testCase();
  }
  return 0;
}
