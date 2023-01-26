#include <bits/stdc++.h>
using namespace std;
template <typename _Tp>
bool minimize(_Tp &__a, const _Tp &__b) {
  if (__a > __b) {
    __a = __b;
    return true;
  }
  return false;
}
template <typename _Tp>
bool maximize(_Tp &__a, const _Tp &__b) {
  if (__a < __b) {
    __a = __b;
    return true;
  }
  return false;
}
const int siz = 1e5 + 2;
const int SIZ = 5e5 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const long long MAXX = 1e18;
const string file = "1";
int val[SIZ];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<vector<int> > queries;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      queries.push_back({1, x});
    } else {
      int x, y;
      cin >> x >> y;
      queries.push_back({2, x, y});
    }
  }
  reverse((queries).begin(), (queries).end());
  for (int i = (int)(1); i <= (int)(SIZ - 1); i++) {
    val[i] = i;
  }
  vector<int> ans;
  for (auto qr : queries) {
    int t = qr[0];
    if (t == 1) {
      int x = qr[1];
      ans.push_back(val[x]);
    } else {
      int x = qr[1], y = qr[2];
      val[x] = val[y];
    }
  }
  reverse((ans).begin(), (ans).end());
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
