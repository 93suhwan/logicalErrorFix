#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt += 2;
      if (i * i == n) {
        cnt--;
      }
    }
  }
  if (cnt == 2)
    return true;
  else
    return false;
}
int XOR(int n) {
  int ans;
  if (n % 4 == 0) {
    ans = 0;
  } else if (n % 2 == 0) {
    ans = 1;
  } else {
    if (abs(n - 1) % 4 == 0) {
      ans = n - 1;
    } else {
      ans = n;
    }
  }
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
  }
  vector<int> v1(v);
  sort(v1.begin(), v1.end());
  auto it = unique(v1.begin(), v1.end());
  v1.resize(it - v1.begin());
  vector<pair<int, int>> ans((int)v1.size());
  for (int i = 0; i < (int)v1.size(); i++) {
    ans[i].first = v1[i];
    ans[i].second = 0;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (int)v1.size(); j++) {
      if (v[i] == ans[j].first) {
        ans[j].second = 1;
        break;
      } else if (ans[j].second == 1) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
