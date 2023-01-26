#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, cnt = 0;
  cin >> n;
  map<long long, vector<long long>, greater<long long>> mp;
  map<long long, long long> ans;
  vector<long long> v;
  set<long long> ss;
  for (long long i = 0; i < n; i++) {
    long long in;
    cin >> in;
    mp[in].push_back(i);
    v.push_back(in);
    ss.insert(in);
  }
  string s;
  cin >> s;
  for (long long i = 0; i < (long long)s.size(); i++) {
    if (s[i] == '1') {
      mp[v[i]].push_back(1);
      cnt++;
    }
  }
  long long k1 = n - cnt - 1, k2 = n - 1;
  for (auto it : mp) {
    if (mp[it.first][1] == 1) {
      ans[mp[it.first][0]] = *ss.begin() + k2;
      k2--;
    } else {
      ans[mp[it.first][0]] = *ss.begin() + k1;
      k1--;
    }
  }
  for (auto it : ans) cout << it.second << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
