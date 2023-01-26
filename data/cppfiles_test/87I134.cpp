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
  long long t1 = 1;
  cin >> t1;
  while (t1--) {
    long long n, m1;
    cin >> n >> m1;
    long long i;
    unordered_map<pair<long long, long long>, long long, hp> m;
    vector<long long> v;
    long long x;
    vector<long long> v2;
    unordered_map<long long, deque<pair<long long, long long>>> adj;
    long long k;
    for (k = 1; k <= n; k = k + 1) {
      for (i = 1; i <= m1; i = i + 1) {
        cin >> x;
        v.push_back(x);
        v2.push_back(x);
      }
    }
    sort(v2.begin(), v2.end());
    for (i = 0; i <= (n * m1) - 1; i = i + 1) {
      long long jd = i / m1;
      long long jt = i % m1;
      adj[v2[i]].push_front({jd, jt});
    }
    for (i = 0; i <= (n * m1) - 1; i = i + 1) {
      sort(adj[v[i]].begin(), adj[v[i]].end(), comp3);
    }
    long long sum = 0;
    for (i = 0; i <= (n * m1) - 1; i = i + 1) {
      pair<long long, long long> jh = adj[v[i]][0];
      adj[v[i]].pop_front();
      m[jh] = 1;
      cout << jh.first << " " << jh.second << "\n";
      for (k = 0; k <= jh.second - 1; k = k + 1) {
        sum += m[{jh.first, k}];
      }
      cout << sum << "\n";
    }
    cout << sum << "\n";
  }
}
