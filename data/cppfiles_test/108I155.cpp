#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
long long idx[MAXN];
long long pre[MAXN], suf[MAXN];
void solve(long long n, long long a[], long long b[], bool ans[]) {
  for (long long i = 1; i <= n; i++) idx[i] = i;
  sort(idx + 1, idx + n + 1,
       [&](long long p, long long q) { return a[p] < a[q]; });
  pre[0] = suf[n + 1] = -1e18;
  for (long long i = 1; i <= n; i++) pre[i] = max(pre[i - 1], b[idx[i]]);
  for (long long i = 1; i < n; i++) ans[idx[i]] = pre[i - 1] > b[idx[n]];
  ans[idx[n]] = 1;
}
long long a[MAXN], b[MAXN];
bool ans1[MAXN], ans2[MAXN];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++) cin >> b[i];
    solve(n, a, b, ans1);
    solve(n, b, a, ans2);
    for (long long i = 1; i <= n; i++) cout << (ans1[i] | ans2[i]);
    cout << '\n';
  }
}
