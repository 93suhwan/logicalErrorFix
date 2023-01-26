#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long val = 1e6;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int check_palin(string s) {
  int i = 0, j = s.length() - 1;
  for (; i < j; i++, j--) {
    if (s[i] != s[j] || s[i] == '?' || s[j] == '?') return 0;
  }
  return 1;
}
void solve(int tc) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> v;
  vector<pair<int, pair<int, int>>> ans;
  for (int i = 0; i < n; i++) cin >> a[i], v.push_back({a[i], i});
  sort(v.begin(), v.end());
  if (v[v.size() - 1].first == 0) {
    cout << 0 << "\n";
    return;
  }
  int k = v.size() - 1;
  int cnt = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (i >= k) break;
    while (v[k].first <= 0) k--;
    if (k == i) k--;
    if (v[i].first != 0) {
      if (k >= 0) {
        ans.push_back(
            {min(v[i].first, v[k].first), {v[i].second + 1, v[k].second + 1}});
        int f = min(v[i].first, v[k].first);
        cnt += f;
        v[i].first -= f;
        v[k].first -= f;
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0 && v[v.size() - 1].first > 0; i--) {
    if (i - 1 >= 0 && v[i].first != 0) {
      ans.push_back({min(v[i].first, v[i - 1].first),
                     {v[i].second + 1, v[i - 1].second + 1}});
      int f = min(v[i].first, v[k].first);
      cnt += f;
      v[i].first -= f;
      v[i - 1].first -= f;
    }
  }
  cout << cnt << "\n";
  for (auto x : ans) {
    int g = x.first;
    while (g--) cout << x.second.first << " " << x.second.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
