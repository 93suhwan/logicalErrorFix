#include <bits/stdc++.h>
using namespace std;
string s;
int cnt = 0;
vector<int> places;
bool flag = 0;
bool div(string &str) {
  int n = str.length();
  if (n == 1) {
    if (str[0] == '0') return true;
    return false;
  }
  return ((str[n - 1] - '0' == 0 && str[n - 2] - '0' == 0) ||
          ((str[n - 2] - '0') * 10 + (str[n - 1] - '0')) % 25 == 0);
}
void dfs(string &s, int i) {
  if (count(s.begin(), s.end(), '_') == 0) {
    if (flag) {
      for (char k = '0'; k <= '9'; k++) {
        if (k == '0' and places[0] == 0 and s.size() != 1) continue;
        for (auto a : places) s[a] = k;
        if (div(s)) {
          cnt++;
        }
      }
    } else if (div(s)) {
      cnt++;
    }
    return;
  }
  if (s[i] == '_') {
    char temp = s[i];
    for (char k = '0'; k <= '9'; k++) {
      if (i == 0 and k == '0' and s.size() != 1) continue;
      s[i] = k;
      dfs(s, i + 1);
      s[i] = temp;
    }
  } else
    dfs(s, i + 1);
}
signed main() {
  cin >> s;
  for (int j = 0; j < s.size(); j++)
    if (s[j] == 'X') places.push_back(j), flag = 1;
  dfs(s, 0);
  cout << (s[0] == '0' ? (s.size() == 1 ? 1 : 0) : cnt) << endl;
}
