#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
const int N = 1e6 + 6, INF = 1e9;
int a[N];
int best[N];
int n, d;
bool mark[N];
int compute(int i) {
  if (best[i] != INF) return best[i];
  if (mark[i]) return INF;
  const int j = (i - d + n) % n;
  mark[i] = true;
  return best[i] = 1 + compute(j);
}
void solve() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    best[i] = a[i] == 0 ? 0 : INF;
    mark[i] = false;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (compute(i) >= INF) {
      cout << -1 << '\n';
      return;
    }
    ans = max(ans, best[i]);
  }
  cout << ans << '\n';
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
