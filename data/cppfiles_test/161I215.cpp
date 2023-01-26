#include <bits/stdc++.h>
using namespace std;
long long setbit(long long num, long long nth) { return num |= (1LL << nth); }
long long clearbit(long long num, long long nth) {
  return num &= ~(1LL << nth);
}
long long toggle(long long num, long long nth) { return num ^= (1LL << nth); }
long long check(long long num, long long nth) { return (num >> nth) & 1LL; }
long long change(long long num, long long nth, long long val) {
  return num ^= (-val ^ num) & (1LL << nth);
}
int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int fy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long dx[4] = {+1, -1, +0, -0};
long long dy[4] = {+0, -0, +1, -1};
long long n, k, y, x;
string str, s;
long long a[5000003];
void solve() {
  cin >> n;
  set<pair<long long, long long> > s;
  vector<pair<long long, long long> > v;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    s.insert({l, r});
    v.push_back({l, r});
  }
  vector<pair<int, pair<long long, long long> > > ans;
  for (int i = 1; i <= n; i++) {
    int l = v[i - 1].first;
    int r = v[i - 1].second;
    if (l == r) {
      ans.push_back({l, {l, r}});
      continue;
    }
    for (int j = l; j <= r; j++) {
      int x = j - 1;
      int y = j + 1;
      if (y > r) {
        if (s.find({l, x}) != s.end()) {
          ans.push_back({j, {l, r}});
          break;
        }
      } else if (x < l) {
        if (s.find({y, r}) != s.end()) {
          ans.push_back({j, {l, r}});
          break;
        }
      } else if (s.find({l, x}) != s.end() || s.find({y, r}) != s.end()) {
        ans.push_back({j, {l, r}});
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << i.second.first << " " << i.second.second << " " << i.first << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1, cas = 0;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
