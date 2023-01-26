#include <bits/stdc++.h>
using namespace std;
int lst[15000000];
int vis[40];
bool cmp(int x, int y) { return x % 2 < y % 2; };
void solve() {
  int n;
  vector<int> v;
  set<int> st;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
    v.push_back(x);
  }
  sort(v.begin(), v.end(), cmp);
  vector<int> ans;
  if (st.size() < n) {
    while (ans.size() < v.size() - st.size()) ans.push_back(0);
    cout << "YES" << endl;
    for (auto &cv : st) ans.push_back(cv);
    for (auto &cv : ans) cout << cv << ' ';
    return;
  } else if (n == 2) {
    cout << "NO" << endl;
    return;
  } else if ((v[2] % 2 == 0) || (v[0] % 2 == 0 && (v[1] % 2 || v.size() > 3))) {
    if (v[2] & 1 && v.size() > 3) {
      swap(v[1], v[3]);
    }
    ans.push_back((v[0] + v[1] - v[2]) / 2);
    ans.push_back(v[0] - ans.back());
    ans.push_back(v[2] - ans.back());
    for (int i = 3; i < v.size(); i++) ans.push_back(v[i] - ans[0]);
    cout << "YES" << endl;
    for (auto &cv : ans) cout << cv << ' ';
    return;
  } else {
    int m = min(13, n / 2) * 2;
    int s1 = -1, s2;
    for (int mask = 0; mask < (1 << m); mask++) {
      if (__builtin_popcount(mask) == m / 2) {
        int sum = 0;
        for (int j = 0; j < m; j++)
          if (mask & (1 << j)) sum += v[j];
        if (lst[sum]) {
          s1 = lst[sum];
          s2 = mask;
          break;
        }
        lst[sum] = mask;
      }
    }
    if (~s1) {
      vector<int> a, b;
      int tmp = s1 & s2;
      s1 ^= tmp;
      s2 ^= tmp;
      for (int i = 0; i < m; i++) {
        if (s1 & (1 << i))
          a.push_back(v[i]), vis[i] = 1;
        else if (s2 & (1 << i))
          b.push_back(v[i]), vis[i] = 1;
      }
      vector<int> ans;
      ans.push_back(0);
      while (a.size() + b.size() > 1) {
        if (b.size() > a.size()) {
          ans.push_back(b.back() - ans.back());
          b.pop_back();
        } else {
          ans.push_back(a.back() - ans.back());
          a.pop_back();
        }
      }
      for (int i = 0; i < n; i++)
        if (vis[i])
          continue;
        else
          ans.push_back(v[i] - ans[0]);
      cout << "YES" << endl;
      for (auto &cv : ans) cout << cv << ' ';
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
