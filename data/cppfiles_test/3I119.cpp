#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> xIdx;
ll ans = 0;
void go(int idx, string str) {
  if (idx == str.size()) {
    if (xIdx.size()) {
      for (int i = 0; i <= 9; i++) {
        if (xIdx.size() > 0 && xIdx[0] == 0 && i == 0) continue;
        for (int j = 0; j < xIdx.size(); j++) {
          str[xIdx[j]] = ('0' + i);
        }
        ans += (stoi(str)) % 25 == 0;
      }
    } else
      ans += stoi(str) % 25 == 0;
  } else {
    if (str[idx] == '_') {
      for (int i = 0; i <= 9; i++) {
        if (idx == 0 && i == 0) continue;
        if (idx == str.size() - 1 && i != 0) continue;
        str[idx] = ('0' + i);
        go(idx + 1, str);
      }
    } else {
      go(idx + 1, str);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  string str;
  cin >> str;
  for (int j = 0; j < str.size(); j++) {
    if (str[j] == 'X') {
      xIdx.push_back(j);
    }
  }
  if (str.size() == 1) {
    if (str[0] == '_' || str[0] == 'X' || str[0] == '0') {
      cout << 1;
    } else
      cout << 0;
    return 0;
  }
  go(0, str);
  if (str[str.size() - 1] == '_') ans *= 2;
  cout << ans << "\n";
  return 0;
}
