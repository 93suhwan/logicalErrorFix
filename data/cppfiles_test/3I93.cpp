#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0;
vector<int> xIdx;
string str;
void go(int idx, int mod, int n) {
  if (idx == n) {
    if (xIdx.size()) {
      for (int i = 0; i <= 9; i++) {
        if (xIdx[0] == 0 && i == 0) continue;
        for (int j = 0; j < xIdx.size(); j++) {
          mod = ((mod * xIdx[i]) + i) % 25;
        }
        ans += mod == 0;
      }
    } else
      ans += mod == 0;
  } else {
    if (str[idx] == '_') {
      for (int i = 0; i <= 9; i++) {
        if (idx == 0 && str[idx] == '_' && i == 0) continue;
        go(idx + 1, (mod * 10 + i) % 25, n);
      }
    } else {
      go(idx + 1, (mod * 10 + (str[idx] - '0')) % 25, n);
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'X') xIdx.push_back(10 * i);
  }
  if (str.size() == 1) {
    if (str[0] == '_' || str[0] == 'X' || str[0] == '0') {
      cout << 1;
    } else
      cout << 0;
    return 0;
  }
  go(0, 0, str.size());
  cout << ans << "\n";
  return 0;
}
