#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> xIdx;
ll ans = 0;
void go(int idx, string str) {
  if (idx == str.size()) {
    set<int> st;
    for (int i = 0; i <= 9; i++) {
      if (xIdx.size() > 0 && xIdx[0] == 0 && i == 0) continue;
      for (int j = 0; j < xIdx.size(); j++) {
        str[xIdx[j]] = ('0' + i);
      }
      st.insert(stoi(str));
    }
    for (auto x : st) {
      if (x % 25 == 0) {
        cout << x << " ";
        ans += 1;
      }
    }
  } else {
    if (str[idx] == '_') {
      for (int i = 0; i <= 9; i++) {
        str[idx] = ('0' + i);
        if (idx == 0 && i == 0) continue;
        go(idx + 1, str);
      }
    } else {
      go(idx + 1, str);
    }
  }
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
  go(0, str);
  cout << ans << "\n";
  return 0;
}
