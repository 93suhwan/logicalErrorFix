#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
bool safe(int x, int y, int n, int m, vector<vector<int>> &v) {
  if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] != 1) return true;
  if (x < 0 || y < 0 || x >= n || y >= m) return true;
  return false;
}
int sumof(int n) {
  int ans = 0;
  while (n) {
    int temp = n % 10;
    ans += temp;
    n /= 10;
  }
  return ans;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  unordered_map<int, int> mp;
  vector<int> res(n, -1);
  for (int i = 0; i < n; i++) {
    if (mp[v[i]] == 0) {
      mp[v[i]] = 1;
      res[i] = 1;
    }
  }
  int color = 1;
  for (int i = 0; i < n; i++) {
    if (res[i] == -1) {
      if (mp[v[i]] < k) {
        mp[v[i]]++;
        res[i] = mp[v[i]];
      } else {
        res[i] = 0;
      }
    }
  }
  print(res);
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
