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
bool was[K][Q], ok[K];
vector<int> v[N];
void solve() {
  int n;
  cin >> n;
  ok[0] = 1;
  for (int second = 1; second < Q; second++) {
    v[second].push_back(0);
    was[0][second] = 1;
  }
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    for (int first : v[a]) {
      ok[first ^ a] = 1;
      for (int second = a + 1; second < Q && !was[first ^ a][second];
           second++) {
        was[first ^ a][second] = 1;
        v[second].push_back(first ^ a);
      }
    }
    v[a].clear();
  }
  vector<int> v;
  for (int first = 0; first < K; first++) {
    if (ok[first]) {
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
