#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 50;
long long n, m, k, a[maxn], t[maxn], ans[maxn];
vector<long long> cnt[maxn];
string second;
void solve() {
  n = second.size();
  k = 2;
  long long tot = 0;
  for (long long i = 1; i <= n; i++) {
    cnt[second[i - 1] - 'a' + 1].push_back(i - 1);
    tot++;
    if (cnt[second[i] - 'a' + 1].size() > 2) cnt[a[i]].pop_back(), tot--;
  }
  cout << tot / k << '\n';
}
void input() {
  cin >> second;
  for (long long i = 1; i <= 26; i++) cnt[i].clear();
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    input();
    solve();
  }
}
