#include <bits/stdc++.h>
using namespace std;
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
long long expo(long long a, long long b, long long mod) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return r;
}
vector<pair<long long, vector<long long> > > ar;
bool check(long long hero) {
  for (auto it : ar) {
    vector<long long> cave = it.second;
    for (long long x : cave) {
      if (x < hero) {
        hero++;
      } else {
        return 0;
      }
    }
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long> > v(n);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    for (int j = 0; j < x; j++) {
      long long k;
      cin >> k;
      v[i].push_back(k);
    }
  }
  for (int i = 0; i < n; i++) {
    long long maxE = v[i][0] + 1;
    for (int j = 1; j < v[i].size(); j++) {
      if (v[i][j] > v[i][j - 1]) {
        long long diff = abs(v[i][j] - v[i][j - 1]);
        if (diff == 1) {
        } else if (diff == 0) {
        } else {
          maxE = max(maxE, v[i][j] - j + 1);
        }
      }
    }
    ar.push_back({maxE, v[i]});
  }
  sort(ar.begin(), ar.end());
  long long l = 1, r = 1e10;
  long long ans = 1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
  ar.clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(6);
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
}
