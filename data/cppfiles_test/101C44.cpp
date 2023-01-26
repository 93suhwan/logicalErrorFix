#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    string s;
    cin >> s;
    vector<int> red, blue;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        red.push_back(v[i]);
      else
        blue.push_back(v[i]);
    }
    bool flag = true;
    sort(red.begin(), red.end());
    while (!red.empty()) {
      if (red.back() <= n)
        break;
      else {
        flag = false;
        break;
      }
      red.pop_back();
    }
    if (flag) {
      int cur = n;
      for (int i = (int)red.size() - 1; i >= 0; i--) {
        if (red[i] > cur) {
          flag = false;
          break;
        }
        cur--;
      }
    }
    if (flag) {
      sort(blue.begin(), blue.end());
      for (int i = 0; i < (int)blue.size(); i++) {
        if (blue[i] < i + 1) {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
