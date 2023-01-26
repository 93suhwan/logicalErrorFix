#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n = 0;
  cin >> n;
  string s;
  vector<vector<int> > v(5, vector<int>(0));
  for (int i = 0; i < n; i++) {
    cin >> s;
    vector<int> cnt(5, 0);
    int sum = 0;
    for (int j = 0; j < s.size(); j++) {
      cnt[s[j] - 'a']++;
      sum++;
    }
    for (int j = 0; j < 5; j++) {
      v[j].push_back(cnt[j] - (sum - cnt[j]));
    }
  }
  long long ans = -1;
  for (int i = 0; i < 5; i++) {
    sort(v[i].rbegin(), v[i].rend());
    long long sum = 0;
    long long cnt = 0;
    for (int j = 0; j < v[i].size(); j++) {
      sum += v[i][j];
      if (sum > 0) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
