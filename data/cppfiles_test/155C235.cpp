#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a, ans(n), like, not_like;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(make_pair(x, i));
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') like.push_back(make_pair(a[i].first, a[i].second));
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') not_like.push_back(make_pair(a[i].first, a[i].second));
  sort(like.rbegin(), like.rend());
  sort(not_like.rbegin(), not_like.rend());
  long long t = n;
  for (auto i : like) {
    ans[i.second].first = t;
    --t;
  }
  for (auto i : not_like) {
    ans[i.second].first = t;
    --t;
  }
  for (auto i : ans) cout << i.first << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
