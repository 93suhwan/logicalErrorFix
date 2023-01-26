#include <bits/stdc++.h>
using namespace std;
long long t, n, ind[2000005], v[1000005];
pair<int, int> check(int val, pair<int, int> x, pair<int, int> y, int pos) {
  int precx = (pos - 2) / 2 * 2, precy = (pos - 2) / 2 * 2 + 1;
  int best = INT_MAX, bestind = -1;
  if (x.first < val && x.second < best) {
    best = x.second;
    bestind = precx;
  }
  if (x.second < val && x.first < best) {
    best = x.first;
    bestind = precx;
  }
  if (y.first < val && y.second < best) {
    best = y.second;
    bestind = precy;
  }
  if (y.second < val && y.first < best) {
    best = y.first;
    bestind = precy;
  }
  if (best == INT_MAX) {
    ind[pos] = -1;
    return {INT_MAX, INT_MAX};
  }
  if (pos > 1) ind[pos] = bestind;
  return {val, best};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 2 * n + 4; i++) ind[i] = -1;
    pair<int, int> x = {INT_MIN, INT_MIN}, y = {INT_MIN, INT_MIN};
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      pair<int, int> succx = check(v[i], x, y, i * 2);
      pair<int, int> succy = check(-v[i], x, y, i * 2 + 1);
      x = succx;
      y = succy;
    }
    int st = -1;
    if (ind[2 * (n - 1) + 1] != -1) st = 2 * (n - 1) + 1;
    if (ind[2 * (n - 1)] != -1) st = 2 * (n - 1);
    if (st == -1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      vector<int> ans;
      while (st >= 0) {
        if (st % 2)
          ans.push_back(v[st / 2] * (-1));
        else
          ans.push_back(v[st / 2]);
        st = ind[st];
      }
      reverse(ans.begin(), ans.end());
      for (auto i : ans) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
