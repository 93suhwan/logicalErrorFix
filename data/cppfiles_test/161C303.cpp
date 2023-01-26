#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long bexpmod(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return bexpmod((((a % mod) * (a % mod)) % mod), b / 2);
  }
  return ((a % mod) *
          (bexpmod((((a % mod) * (a % mod)) % mod), (b - 1) / 2) % mod)) %
         mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long mylcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long bexp(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return bexp((a * a), b / 2);
  }
  return (a * (bexp((a * a), (b - 1) / 2)));
}
long long nCr(long long n, long long k) {
  long double res = 1;
  for (long long i = 1; i <= k; ++i) res = res * (n - k + i) / i;
  return (long long)(res + 0.01);
}
void solve() {
  long long n;
  cin >> n;
  map<long long, vector<long long> > ini;
  vector<pair<long long, long long> > end;
  map<pair<long long, long long>, long long> ans;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    ini[x].push_back(y);
    end.push_back(make_pair(x, y));
  }
  for (auto sol : ini) {
    if (sol.second.size() == 1) {
      ans[make_pair(sol.first, sol.second[0])] = sol.first;
    } else {
      sort(sol.second.begin(), sol.second.end());
      for (long long i = sol.second.size() - 1; i >= 0; i--) {
        if (i == 0) {
          ans[make_pair(sol.first, sol.second[0])] = sol.first;
        } else {
          ans[make_pair(sol.first, sol.second[i])] = sol.second[i - 1] + 1;
        }
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << end[i].first << " " << end[i].second << " " << ans[end[i]] << endl;
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
