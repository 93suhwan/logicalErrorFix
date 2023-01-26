#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9 + 7;
const long long int MAX = 1e18;
const long long int N = 200005;
void WetPitch() {
  long long int n;
  cin >> n;
  vector<string> v(n);
  map<long long int, vector<long long int>> mp;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long int i = 0; i < n; i++) {
    long long int cnt[5] = {0};
    for (auto x : v[i]) {
      cnt[x - 'a']++;
    }
    long long int a = cnt[0] - cnt[1] - cnt[2] - cnt[3] - cnt[4];
    long long int b = cnt[1] - cnt[0] - cnt[2] - cnt[3] - cnt[4];
    long long int c = cnt[2] - cnt[1] - cnt[0] - cnt[3] - cnt[4];
    long long int d = cnt[3] - cnt[1] - cnt[0] - cnt[2] - cnt[4];
    long long int e = cnt[4] - cnt[1] - cnt[0] - cnt[2] - cnt[3];
    mp[0].push_back(a);
    mp[1].push_back(b);
    mp[2].push_back(c);
    mp[3].push_back(d);
    mp[4].push_back(e);
  }
  long long int ans = -1e9;
  for (long long int i = 0; i < 5; i++) {
    sort(mp[i].begin(), mp[i].end(), greater<long long int>());
  }
  for (long long int i = 0; i < 5; i++) {
    long long int s = 0;
    long long int size1 = mp[i].size();
    if (size1 == 0) continue;
    long long int j = 1;
    s = mp[i][0];
    while (s > 0 && j < size1) {
      if (s + mp[i][j] > 0) {
        s += mp[i][j];
        j++;
      } else {
        break;
      }
    }
    if (s > 0) {
      ans = max(ans, j);
    }
  }
  if (ans == -1e9) {
    ans = 0;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tst;
  tst = 1;
  cin >> tst;
  long long int p = 1;
  while (tst--) {
    WetPitch();
  }
  return 0;
}
