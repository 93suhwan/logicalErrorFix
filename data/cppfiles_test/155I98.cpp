#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> init(n);
  for (int i = 0; i < n; i++) cin >> init[i];
  string likes;
  cin >> likes;
  vector<int> mp(n, -1);
  vector<int> like, dislike;
  for (int i = 0; i < likes.size(); i++) {
    if (likes[i] == '1') {
      like.push_back(init[i]);
    } else {
      dislike.push_back(init[i]);
    }
  }
  sort(like.begin(), like.end());
  int startLike = n - like.size() + 1;
  for (int i = 0; i < like.size(); i++) {
    mp[like[i]] = startLike++;
  }
  for (int i = 0; i < dislike.size(); i++) {
    mp[dislike[i]] = i + 1;
  }
  for (int i : init) {
    cout << mp[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcase;
  cin >> testcase;
  while (testcase--) solve();
  return 0;
}
