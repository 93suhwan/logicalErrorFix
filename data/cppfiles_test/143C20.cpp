#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll arr[200001];
ll cnt[200001];
void solve() {
  memset(cnt, 0, sizeof(cnt));
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  vector<ll> ans(n + 1, -1);
  stack<ll> s;
  ll costsum = 0;
  for (ll i = 0; i <= n; i++) {
    if (i > 0 && cnt[i - 1] == 0) {
      if (s.empty()) {
        break;
      }
      ll j = s.top();
      s.pop();
      costsum += i - j - 1;
    }
    ans[i] = costsum + cnt[i];
    while (i > 0 && cnt[i - 1] > 1) {
      cnt[i - 1]--;
      s.push(i - 1);
    }
  }
  for (ll i = 0; i <= n; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
