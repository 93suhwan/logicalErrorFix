#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      if (s[i] != s1[i])
        a[i] = 2;
      else if (s[i] == '1')
        a[i] = 0;
      else
        a[i] = 1;
    }
    vector<int> res;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x = 0, y = 0;
      if (a[i] == 2) {
        res.push_back(2);
        cnt += 2;
        continue;
      }
      if (a[i] == 0) {
        if (i + 1 < n) {
          if (a[i + 1] == 1) {
            res.push_back(2);
            cnt += 2;
            i++;
            continue;
          }
        }
      }
      if (a[i] == 1) {
        if (i + 1 < n) {
          if (a[i + 1] == 0) {
            res.push_back(2);
            cnt += 2;
            i++;
            continue;
          } else {
            res.push_back(1);
            cnt += 1;
          }
        } else {
          res.push_back(1);
          cnt += 1;
        }
      }
    }
    cout << cnt << '\n';
  }
}
