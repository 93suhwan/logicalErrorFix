#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e18 + 123;
const long double EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 2e5 + 123;
const int M = 1e6 + 12;
const double pi = 3.14159265359;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int a[M];
vector<pair<int, int> > v[M];
bool bp[1000];
void solve() {
  vector<int> pr;
  for (int i = 2; i < 1000; i++) {
    if (bp[i]) continue;
    pr.push_back(i);
    for (int j = i * i; j < 1000; j += i) {
      bp[j] = 1;
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  long long ans = 0;
  set<int> bb = {inf};
  for (int i = n, mn; i >= 1; i--) {
    mn = n + 1;
    if (a[i] > 1 && s[i - 1] == '/') mn = i;
    for (int d : pr) {
      if (a[i] % d) {
        if (!v[d].empty()) {
          mn = min(mn, v[d].back().second);
        }
        continue;
      }
      int cnt = 0;
      while (a[i] % d == 0) {
        a[i] /= d;
        cnt++;
      }
      if (s[i - 1] == '*') {
        while (!v[d].empty()) {
          if (v[d].back().first <= cnt) {
            cnt -= v[d].back().first;
            v[d].pop_back();
          } else {
            mn = min(mn, v[d].back().second);
            (--v[d].end())->first -= cnt;
            break;
          }
        }
      } else {
        v[d].push_back({cnt, i});
      }
    }
    if (a[i] > 1) {
      int d = a[i];
      if (s[i - 1] == '*') {
        if (!v[d].empty()) {
          bb.erase(v[d].back().second);
          v[d].pop_back();
        }
      } else {
        v[d].push_back({1, i});
        bb.insert(i);
      }
    }
    mn = min(mn, *bb.begin());
    ans += mn - i;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
