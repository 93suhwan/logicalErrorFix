#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
string str;
void go(int idx, ll mod, int k, int n) {
  if (idx == n) {
    ans += mod == 0;
  } else {
    if (str[idx] == '_') {
      for (int i = 0; i <= 9; i++) {
        if (idx == 0 && i == 0) continue;
        go(idx + 1, (mod * 10 + i) % 25, k, n);
      }
    } else if (str[idx] == 'X') {
      if (k != -1) {
        go(idx + 1, (mod * 10 + k) % 25, k, n);
      } else {
        for (int i = 0; i <= 9; i++) {
          if (idx == 0 && i == 0) continue;
          go(idx + 1, (mod * 10 + i) % 25, i, n);
        }
      }
    } else {
      go(idx + 1, (mod * 10 + (str[idx] - '0')) % 25, k, n);
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> str;
  if (str.size() == 1) {
    if (str[0] == '_' || str[0] == 'X' || str[0] == '0') {
      cout << 1;
    } else
      cout << 0;
    return 0;
  }
  if (str[0] == '0') {
    cout << "0";
    return 0;
  }
  go(0, 0, -1, str.size());
  cout << ans << "\n";
  return 0;
}
