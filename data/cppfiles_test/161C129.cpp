#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, char> aa, pair<long long, char> bb) {
  if (aa.first != bb.first) return aa.first > bb.first;
  return aa.second < bb.second;
}
bool comp1(pair<long long, char> aa, pair<long long, char> bb) {
  if (aa.first != bb.first) return aa.first < bb.first;
  return aa.second > bb.second;
}
bool comp2(pair<long long, long long> aa, pair<long long, long long> bb) {
  if (aa.first != bb.first) return aa.first > bb.first;
  return aa.second < bb.second;
}
bool comp3(pair<long long, long long> aa, pair<long long, long long> bb) {
  if (aa.first != bb.first) return aa.first < bb.first;
  return aa.second > bb.second;
}
long long rup(long long ik, long long ikk) {
  if (ik % ikk == 0)
    return ik / ikk;
  else
    return (ik / ikk) + 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
long long nm(long long a, long long b) { return (b + (a % b)) % b; }
struct hp {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
void sieve1(long long n1) {
  long long sieve[1000005];
  for (long long x1 = 2; x1 <= n1; x1++) {
    if (sieve[x1]) continue;
    for (long long u1 = 2 * x1; u1 <= n1; u1 += x1) {
      sieve[u1] = x1;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    long long x, y;
    long long i;
    vector<3.141592654> v;
    unordered_map<long long, long long> m;
    m.reserve(1024);
    m.max_load_factor(0.25);
    long long hol = 10000;
    cin >> n;
    for (i = 1; i <= n; i = i + 1) {
      cin >> x >> y;
      v.push_back({x, y});
      m[(x * hol) + y] = 1;
    }
    for (auto u : v) {
      long long pp = u.first;
      long long qq = u.second;
      for (i = pp; i <= qq; i = i + 1) {
        long long g = 0;
        if (i - 1 >= pp) {
          long long kk = (pp * hol) + (i - 1);
          if (m[kk] == 0) g++;
        }
        if (i + 1 <= qq) {
          long long kk1 = ((i + 1) * hol) + qq;
          if (m[kk1] == 0) g++;
        }
        if (g == 0) {
          cout << pp << " " << qq << " " << i << "\n";
          break;
        }
      }
    }
  }
}
