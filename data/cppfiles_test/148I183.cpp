#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int k;
    cin >> k;
    vector<int> top(k);
    for (auto &i : top) cin >> i;
    cin >> k;
    vector<int> bottom(k);
    for (auto &i : bottom) cin >> i;
    cin >> k;
    vector<int> left(k);
    for (auto &i : left) cin >> i;
    cin >> k;
    vector<int> right(k);
    for (auto &i : right) cin >> i;
    int mx = max(
        max(abs(top[0] - top.back()) * h, abs(bottom[0] - bottom.back()) * h),
        max(abs(left[0] - left.back()) * w, abs(right[0] - right.back()) * w));
    cout << mx << endl;
  }
  return 0;
}
