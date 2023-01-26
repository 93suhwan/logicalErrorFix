#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int s[n];
  map<int, int> mp;
  map<int, vector<int>> p;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    mp[s[i]]++;
    p[s[i]].push_back(i);
    s[i] = 0;
  }
  int c = 1, r = n / k, cr = 0;
  r = k * r;
  for (auto x : mp) {
    if (x.second >= k) {
      int y = k;
      while (y > 0 && cr < r) {
        cr++;
        if (c == k + 1) c = 1;
        s[p[x.first].back()] = c;
        c++;
        p[x.first].pop_back();
        y--;
      }
    } else {
      int y = x.second;
      while (y > 0 && cr < r) {
        cr++;
        if (c == k + 1) c = 1;
        s[p[x.first].back()] = c;
        c++;
        p[x.first].pop_back();
        y--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
