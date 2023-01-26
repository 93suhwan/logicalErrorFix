#include <bits/stdc++.h>
const int Mod = 1000000007, N = 1e5 + 100;
using namespace std;
using namespace std;
const long long INF = 0x3f3f3f3f;
double pi = 3.1415926;
const long long dx[] = {-1, +1, +0, +0};
const long long dy[] = {+0, +0, -1, +1};
pair<long long, long long> upper[N], lower[N];
vector<long long> Graph[N];
bool ans[N];
void dfs(long long node) {
  ans[node] = true;
  for (long long ch : Graph[node]) {
    if (!ans[ch]) {
      dfs(ch);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n; ++i) {
      Graph[i].clear();
      ans[i] = false;
    }
    for (long long i = 1; i <= n; ++i) {
      cin >> upper[i].first;
      upper[i].second = i;
    }
    for (long long i = 1; i <= n; ++i) {
      cin >> lower[i].first;
      lower[i].second = i;
    }
    sort(upper + 1, upper + 1 + n);
    sort(lower + 1, lower + 1 + n);
    for (long long i = 1; i < n; ++i) {
      Graph[upper[i].second].emplace_back(upper[i + 1].second);
      Graph[lower[i].second].emplace_back(lower[i + 1].second);
    }
    dfs(upper[n].second);
    dfs(lower[n].second);
    for (long long i = 1; i <= n; ++i) {
      cout << ans[i];
    }
    cout << endl;
  }
}
