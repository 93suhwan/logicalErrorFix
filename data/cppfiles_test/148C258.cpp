#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long k;
    cin >> k;
    vector<long long> top(k);
    for (auto &i : top) cin >> i;
    cin >> k;
    vector<long long> bottom(k);
    for (auto &i : bottom) cin >> i;
    cin >> k;
    vector<long long> left(k);
    for (auto &i : left) cin >> i;
    cin >> k;
    vector<long long> right(k);
    for (auto &i : right) cin >> i;
    long long mx = max(
        max(abs(top[0] - top.back()) * h, abs(bottom[0] - bottom.back()) * h),
        max(abs(left[0] - left.back()) * w, abs(right[0] - right.back()) * w));
    cout << mx << endl;
  }
  return 0;
}
