#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long modpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long bpow(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long modinv(long long a, long long m = MOD) { return modpow(a, m - 2, m); }
const int N = 2e5 + 5;
vector<int> adj[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long> > v[5];
    vector<vector<long long> > rank(n + 1, vector<long long>(5));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        long long x;
        cin >> x;
        rank[i][j] = x;
        v[j].push_back({x, i});
      }
    }
    vector<long long> topper;
    for (long long i = 0; i < 5; i++) {
      sort(v[i].begin(), v[i].end());
      topper.push_back(v[i][0].second);
    }
    long long ans = -2;
    for (long long _ = 0; _ < (long long)topper.size(); _++) {
      long long t = topper[_];
      long long val = 0;
      for (long long i = 0; i < n; i++) {
        if (i == t) {
          continue;
        }
        long long cnt = 0;
        for (long long j = 0; j < 5; j++) {
          if (rank[t][j] < rank[i][j]) {
            cnt++;
          }
        }
        if (cnt >= 3) {
          val++;
        }
      }
      if (val == n - 1) {
        ans = t;
        break;
      }
    }
    cout << ans + 1 << '\n';
  }
}
