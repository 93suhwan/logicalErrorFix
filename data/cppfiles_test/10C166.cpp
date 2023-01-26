#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> a(n);
  map<long long, long long> cnt;
  unordered_map<long long, stack<long long>> ind;
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    cnt[a[i].first]++;
    ind[a[i].first].push(i);
  }
  vector<pair<long long, long long>> b;
  unordered_map<long long, long long> cnt_color;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    if (it->second >= k) {
      for (long long j = 0; j < k; j++) {
        b.push_back({it->first, ind[(it->first)].top()});
        ind[it->first].pop();
      }
    } else {
      for (long long j = 0; j < it->second; j++) {
        b.push_back({it->first, ind[(it->first)].top()});
        ind[it->first].pop();
      }
    }
  }
  vector<long long> ans(n, 0);
  long long col = 1;
  for (long long i = 0; i < (long long)b.size(); i++) {
    cnt_color[col]++;
    ans[b[i].second] = col;
    col++;
    if (col == k + 1) {
      col = 1;
    }
  }
  long long min_color = INT_MAX;
  for (auto it = cnt_color.begin(); it != cnt_color.end(); it++) {
    min_color = min(min_color, it->second);
  }
  unordered_map<long long, bool> exceed;
  for (auto it = cnt_color.begin(); it != cnt_color.end(); it++) {
    if (it->second > min_color) {
      exceed[it->first] = true;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (exceed[ans[i]] == true) {
      cnt_color[ans[i]]--;
      if (cnt_color[ans[i]] <= min_color) {
        exceed[ans[i]] = false;
      }
      ans[i] = 0;
    }
  }
  for (auto &el : ans) {
    cout << el << " ";
  }
  cout << "\n";
  return;
}
int32_t main() {
  io();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
