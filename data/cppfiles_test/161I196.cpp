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
string str;
long long a[5000003];
set<pair<long long, long long> > s;
vector<pair<long long, long long> > v;
set<pair<int, pair<long long, long long> > > ans;
int dp[1003][1004], taken[1003][1003];
int lo = 0;
int hi = 0;
int mn = 0;
void cal(int l, int r) {
  if (l == r) {
    ans.insert({l, {l, r}});
    return;
  }
  if (dp[l][r]) return;
  for (int i = l; i <= r; i++) {
    int x = i - 1;
    int y = i + 1;
    if (s.find({l, x}) != s.end() || s.find({y, r}) != s.end()) {
      if (taken[l][r] == 0) {
        ans.insert({i, {l, r}});
        taken[l][r] = 0;
      }
      dp[l][r] = 1;
      cal(l, x);
      cal(y, r);
      break;
    }
  }
  return;
}
void solve() {
  cin >> n;
  lo = 1e7;
  ans.clear();
  s.clear();
  v.clear();
  hi = mn = -12;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    s.insert({l, r});
    int d = r - l;
    if (d > mn) {
      lo = l;
      hi = r;
      mn = d;
    }
    v.push_back({l, r});
  }
  cal(lo, hi);
  for (auto i : ans) {
    cout << i.second.first << " " << i.second.second << " " << i.first << endl;
    dp[i.second.first][i.second.second] = 0;
    taken[i.second.first][i.second.second] = 0;
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
