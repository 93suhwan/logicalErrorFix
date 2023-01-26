#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
const long long int MAXN = 2e5 + 5;
const long long int mod = 1000000007;
const long long int N = 200005;
void solve() {
  int n;
  cin >> n;
  vector<long long int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  vector<long long int> ans(5, 0ll);
  for (auto x : vec) {
    if (x % 3ll) {
      ans[0] = 1e18;
      break;
    } else {
      ans[0] = max(ans[0], x / 3ll);
    }
  }
  for (auto x : vec) {
    if (x % 3ll != 2ll) {
      ans[1] = max(ans[1], x / 3ll);
    } else {
      ans[1] = 1e18;
      break;
    }
  }
  ans[1] += 1ll;
  for (auto x : vec) {
    if (x % 3ll != 1ll) {
      ans[2] = max(ans[2], x / 3ll);
    } else {
      ans[2] = 1e18;
      break;
    }
  }
  ans[2] += 1ll;
  for (auto x : vec) {
    if (x % 3ll) {
      ans[3] = max(ans[3], x / 3ll);
    } else {
      ans[3] = max(ans[3], x / 3ll - 1ll);
    }
  }
  ans[3] += 2ll;
  for (auto x : vec) {
    if (x == 1ll) {
      ans[4] = 1e18;
      break;
    }
    if (x % 3ll == 1ll)
      ans[4] = max(ans[4], (x - 4ll) / 3ll);
    else {
      ans[4] = max(ans[4], x / 3ll);
    }
  }
  ans[4] += 2ll;
  sort(ans.begin(), ans.end());
  cout << ans[0] << "\n";
  return;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
