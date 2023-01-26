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
  unordered_map<int, vector<int>> mp;
  vector<int> res(n, -1);
  int color = 1;
  for (int i = 0; i < n; i++) {
    mp[v[i]].push_back(i);
  }
  int xtra = 0;
  unordered_map<int, int> mp2;
  for (auto elm : mp) {
    vector<int> temp = elm.second;
    for (int i = 0; i < k && i < temp.size(); i++) {
      if (color > k) {
        color = 1;
      }
      res[temp[i]] = color;
      if (mp2[color] == 0) {
        mp2[color] = temp[i];
      }
      color++;
      xtra++;
    }
    if (temp.size() > k) {
      for (int i = k; i < temp.size(); i++) {
        res[temp[i]] = 0;
      }
    }
  }
  if (xtra % k != 0) {
    int rem = xtra % k;
    for (auto elm : mp2) {
      if (rem == 0) break;
      res[elm.second] = 0;
      rem--;
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
