#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5;
long long arr[N];
vector<long long> g[N];
long long used[N];
long long sz[N];
long long isCycle = 0;
void dfs(long long a) {
  used[a] = 1;
  sz[a] = 1;
  for (auto c : g[a]) {
    if (!used[c]) {
      dfs(c);
      sz[a] = max(sz[a], sz[c] + 1);
    } else if (used[c] == 1) {
      isCycle = 1;
    }
  }
  used[a] = 2;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = (long long)0; i < (long long)n + 1; i++) {
    used[i] = 0;
    g[i].clear();
    sz[i] = 0;
  }
  isCycle = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    cin >> arr[i];
  }
  for (long long i = (long long)0; i < (long long)n; i++) {
    long long prev = (i - k + n) % n;
    if (arr[i] && arr[prev]) {
      g[i].push_back(prev);
    }
  }
  for (long long i = (long long)0; i < (long long)n; i++) {
    if (!used[i] && arr[i]) {
      dfs(i);
    }
  }
  long long ans = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    ans = max(ans, sz[i]);
  }
  if (isCycle) {
    cout << -1;
  } else {
    cout << ans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  for (long long i = (long long)0; i < (long long)tests; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
