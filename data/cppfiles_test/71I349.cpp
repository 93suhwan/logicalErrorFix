#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  int t, k;
  string n;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k == 1) {
      string ans = "";
      char mxc = '0';
      int sz = n.length();
      for (char c : n) {
        mxc = max(mxc, c);
      }
      for (int i = 0; i < sz; i++) {
        ans += mxc;
      }
      cout << ans << endl;
    } else if (k == 2) {
      long long ans1 = INT_MAX;
      char a1 = n[0];
      bool flag;
      for (char a2 = '0'; a2 <= '9'; a2++) {
        string temp = "";
        flag = true;
        char mn = min(a1, a2);
        char mx = max(a1, a2);
        bool f1 = false;
        for (int i = 0; i < n.length(); i++) {
          if (mn >= n[i] or f1) {
            if (mn > n[i]) {
              f1 = true;
            }
            temp += mn;
          } else if (mx >= n[i] or f1) {
            if (mx > n[i]) {
              f1 = true;
            }
            temp += mx;
          } else {
            flag = false;
            break;
          }
        }
        if (flag) {
          ans1 = min(ans1, (long long)stoi(temp));
        }
      }
      cout << ans1 << endl;
    }
  }
}
