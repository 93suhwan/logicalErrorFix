#include <bits/stdc++.h>
using namespace std;
int a[200000], ans[200000];
string s;
int n;
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> s;
  vector<array<int, 2>> like, dislike;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      dislike.push_back({a[i], i});
    } else {
      like.push_back({a[i], i});
    }
  }
  sort(dislike.begin(), dislike.end());
  sort(like.begin(), like.end());
  for (int i = 0; i < dislike.size(); ++i) {
    ans[dislike[i][1]] = i + 1;
  }
  for (int i = 0; i < like.size(); ++i) {
    ans[like[i][1]] = i + dislike.size() + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
