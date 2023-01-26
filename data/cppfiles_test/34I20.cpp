#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 1e6 + 100, K = 5001, INF = 2e18, MOD = 1e9 + 7;
long long n, a[N];
bool ok[K][2 * K], ans[2 * K];
vector<long long> v[K];
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < K; i++) {
    ok[i][0] = true;
    v[i].push_back(0);
  }
  for (long long i = 0; i < n; i++) {
    for (long long x : v[a[i]]) {
      long long e = (x ^ a[i]);
      for (long long h = a[i] + 1; h < K; h++) {
        if (ok[h][e]) break;
        if (!ok[h][e]) {
          ok[h][e] = true;
          v[h].push_back(e);
        }
      }
    }
    v[a[i]].clear();
  }
  for (long long i = 0; i < K; i++) {
    for (long long j = 0; j < 2 * K; j++) {
      ans[j] |= ok[i][j];
    }
  }
  long long cnt = 0;
  for (long long i = 0; i < 2 * K; i++) {
    cnt += ans[i];
  }
  cout << cnt << '\n';
  for (long long i = 0; i < 2 * K; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
}
