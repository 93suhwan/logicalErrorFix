#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
int dp[500050];
pair<int, int> a[500050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  for (int i = 1, op; i <= q; ++i) {
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      a[i] = {x, -1};
    } else {
      int x, y;
      cin >> x >> y;
      a[i] = {x, y};
    }
  }
  vector<int> ans;
  for (int i = q; i >= 1; --i) {
    if (a[i].second == -1) {
      if (dp[a[i].first] == 0)
        ans.push_back(a[i].first), dp[a[i].first] = a[i].first;
      else
        ans.push_back(dp[a[i].first]);
    } else {
      int x = a[i].first, y = a[i].second;
      if (dp[y] == 0) dp[y] = y;
      dp[x] = dp[y];
    }
  }
  reverse(ans.begin(), ans.end());
  print(ans);
}
