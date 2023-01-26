#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct cmp {
  bool operator()(const T &p1, const T &p2) {}
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n][5];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    for (int j = 0; j < 5; j++) {
      map<long long, long long> mp;
      for (int i = 0; i < n; i++) mp[a[i][j]];
      long long st = 1;
      for (auto &it : mp) it.second = st++;
      for (int i = 0; i < n; i++) a[i][j] = mp[a[i][j]];
    }
    vector<long long> ans;
    for (int i = 0; i < n; i++) {
      long long c1 = 0;
      for (int j = 0; j < 5; j++)
        if (a[i][j] == 1) c1++;
      if (c1 >= 2) ans.push_back(i);
    }
    if (((long long)(ans.size())) == 0) {
      cout << "-1" << endl;
      continue;
    }
    long long z = 1;
    for (auto it : ans) {
      long long val = it;
      for (int i = 0; i < n; i++) {
        long long c2 = 0;
        if (i == it) continue;
        for (int j = 0; j < n; j++)
          if (a[val][j] < a[i][j]) c2++;
        if (c2 < 3) z = 0;
      }
      if (z) {
        cout << val + 1 << endl;
        break;
      }
    }
    if (z == 0) {
      cout << "-1" << endl;
    }
  }
  return 0;
}
