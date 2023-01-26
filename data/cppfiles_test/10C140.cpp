#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ans(n);
  map<int, vector<int>> m;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m[x].push_back(i);
  }
  int extra = 0;
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i->second.size() > k) {
      extra += i->second.size() - k;
    }
  }
  int total = (n - extra) % k + extra;
  int idx = (n - total);
  int temp = 0;
  for (auto i = m.begin(); i != m.end(); i++) {
    for (int j = 0; j < i->second.size() && j < k; j++) {
      ans[i->second[j]] = temp % k + 1;
      ++temp;
      if (temp == idx) break;
    }
    if (temp == idx) break;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
