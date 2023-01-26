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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    long long i;
    long long x;
    vector<long long> v;
    cin >> n;
    long long best = -1;
    for (i = 1; i <= n; i = i + 1) {
      cin >> x;
      best = max(x, best);
      v.push_back(x);
    }
    long long f = 0;
    if (v[n - 1] == best) {
      cout << 0 << "\n";
      continue;
    }
    f++;
    vector<long long> v2;
    long long mini = 1000000000000007;
    for (i = 0; i <= n - 1; i = i + 1) {
      if (v[i] > v[n - 1]) {
        v2.push_back(v[i]);
        mini = min(mini, v[i]);
      }
    }
    while (!v2.empty()) {
      long long jh = v2.back();
      if (jh == best) break;
      v2.pop_back();
      if (jh >= mini) {
        f++;
        mini = jh + 1;
      }
      if (mini == best) break;
    }
    cout << f << "\n";
  }
}
