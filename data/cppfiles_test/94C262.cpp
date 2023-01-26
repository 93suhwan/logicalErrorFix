#include <bits/stdc++.h>
using namespace std;
int codefo;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> codefo;
  while (codefo--) {
    int n;
    cin >> n;
    string t = to_string(n);
    int sz = t.size();
    int ans = 0;
    for (int bit = 0; bit < (1 << sz); bit++) {
      vector<int> temp;
      for (int i = 0; i < sz; i++) {
        temp.push_back(t[i] - '0');
      }
      bool f = true;
      for (int i = 0; i < sz; i++) {
        if (bit & (1 << i)) {
          if (temp[i] == 0 || sz - i <= 2) {
            f = false;
            break;
          } else {
            temp[i] -= 1;
            temp[i + 2] += 10;
          }
        }
      }
      if (!f) continue;
      int te = 1;
      for (int i = 0; i < sz; i++) {
        if (temp[i] >= 10) {
          te *= 19 - temp[i];
        } else
          te *= temp[i] + 1;
      }
      f = false;
      for (int i = 0; i < sz; i++) {
        if (temp[i] >= 10) f = true;
      }
      if (!f && te > 0) te -= 2;
      ans += te;
    }
    cout << ans << endl;
  }
}
