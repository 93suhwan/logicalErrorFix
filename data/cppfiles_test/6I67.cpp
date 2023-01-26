#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
const int md = 1e9 + 7;
int add(const int &a, const int &b) { return a + b >= md ? a + b - md : a + b; }
int sub(const int &a, const int &b) { return a - b < 0 ? a - b + md : a - b; }
int mul(const int &a, const int &b) { return (1ll * a * b) % md; }
const int maxN = 1e5 + 5;
vi divs[maxN];
int sumg[maxN];
int cnt[maxN];
vi have[maxN];
ll too[maxN];
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    have[x].push_back(i);
    ans = add(ans, mul(x, i));
  }
  for (int i = maxN - 1; i >= 1; i--) {
    for (int j = i; j < maxN; j += i) {
      divs[j].push_back(i);
    }
  }
  for (int g = maxN - 1; g >= 1; --g) {
    int cur = 0;
    for (int d = g; d < maxN; d += g) {
      for (auto &val : have[d]) {
        for (auto &div : divs[val]) {
          too[div] += cnt[div];
          cur = add(cur, mul(too[div] % md, div));
          for (auto &div2 : divs[div]) {
            if (div2 == div) continue;
            too[div2] -= too[div];
          }
          too[div] = 0;
          cnt[div]++;
        }
        cur = sub(cur, sumg[d]);
      }
    }
    for (int d = g; d < maxN; d += g) {
      for (auto &val : have[d]) {
        for (auto &div : divs[val]) {
          cnt[div]--;
        }
      }
    }
    sumg[g] = cur;
    ans = add(ans, mul(2, mul(cur, g)));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
