#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template <typename T>
void vecprint(vector<T>& v1) {
  for (auto it : v1) cout << it << " ";
  cout << endl;
}
void solve() {
  int n, x, y, i, j, r, l;
  cin >> n;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    mp[{x, y}] = -1;
  }
  for (auto it : mp) {
    i = l = it.first.first;
    j = r = it.first.second;
    if (i == j)
      mp[{i, j}] = i;
    else
      while (i <= j) {
        if (i == l || i == r) {
          if (mp.find({l, i - 1}) != mp.end() ||
              mp.find({i + 1, r}) != mp.end()) {
            {
              mp[{l, r}] = i;
              break;
            }
          }
        } else if (mp.find({l, i - 1}) != mp.end() &&
                   mp.find({i + 1, r}) != mp.end()) {
          {
            mp[{l, r}] = i;
            break;
          }
        }
        i++;
      }
  }
  for (auto it : mp) {
    i = l = it.first.first;
    j = r = it.first.second;
    cout << i << " " << j << " " << mp[{i, j}] << endl;
  }
}
int main() {
  int x;
  cin >> x;
  while (x--) solve();
}
