#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x % MOD * y % MOD);
      if (x > MOD) x %= MOD;
    }
    y = (y % MOD * y % MOD);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
void union1(long long parent[], int x, int y) { parent[y] = x; }
int find1(long long parent[], int x) {
  if (parent[x] == -1) {
    return x;
  }
  return find1(parent, parent[x]);
}
int main(void) {
  long long t, n, x, y, k, m, r, p, d, u, v, q, a, b, z, w, l;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    unordered_map<long long, long long> mp;
    unordered_map<long long, vector<long long>> v1;
    unordered_map<long long, long long> indices;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
    }
    vector<pair<int, int>> p;
    long long res = 0;
    for (auto x : mp) {
      if (x.second >= k) {
        long long r = k, c = 1;
        while (r--) {
          v1[x.first].push_back(c++);
        }
      } else {
        p.push_back({x.second, x.first});
        res += x.second;
      }
    }
    int f = 0, c1 = 0;
    long long temp = res % k;
    res -= temp;
    for (int i = 0; i < p.size(); i++) {
      while (c1 < res && p[i].first--) {
        c1++;
        v1[p[i].second].push_back((f % k) + 1);
        f++;
      }
    }
    for (auto x : v1) {
      indices[x.first] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (indices[v[i]] < v1[v[i]].size()) {
        cout << v1[v[i]][indices[v[i]]++] << " ";
      } else
        cout << 0 << " ";
    }
    cout << endl;
  }
}
