#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e18 + 123;
const long double EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 1e5 + 123;
const int M = 1e6 + 1;
const int K = 8192;
const int Q = 5001;
const double pi = 3.14159265359;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool skip[Q], was[Q][Q];
int mn[K];
void solve() {
  int n;
  cin >> n;
  fill(mn, mn + K, inf);
  mn[0] = 0;
  skip[0] = 1;
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    if (skip[a]) continue;
    skip[a] = 1;
    bool fl = 0;
    for (int first = 0; first < K; first++) {
      if (mn[first] < a && mn[first ^ a] > a) {
        mn[first ^ a] = a;
        fl = 1;
      }
    }
    if (fl) {
      for (int second = a + 1; second < Q; second++) {
        if (!was[a][second]) {
          was[a][second] = 1;
          skip[second] = 0;
        }
      }
    }
  }
  vector<int> v;
  for (int first = 0; first < K; first++) {
    if (mn[first] != inf) {
      v.push_back(first);
    }
  }
  cout << (int)v.size() << '\n';
  for (int first : v) cout << first << " ";
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
