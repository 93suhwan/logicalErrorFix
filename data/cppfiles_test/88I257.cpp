#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ls(n), la(n, 1);
    for (int &x : ls) cin >> x;
    if (n & 1) {
      for (int u = 1; u < n; u++) {
        if (ls[u - 1] < ls[u] && la[u - 1] == 1) la[u] = 2;
      }
      map<int, int> mp;
      int f = 0;
      for (int x : la) mp[x]++;
      for (auto x : mp)
        if (x.first % 2 == 0 && x.second > 1) f = 1;
      cout << (f ? "YES" : "NO");
    } else
      cout << "YES";
    cout << "\n";
  }
}
