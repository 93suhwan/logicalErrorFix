#include <bits/stdc++.h>
using namespace std;
string s;
int cnt = 0;
vector<int> places;
void dfs(string s, int i) {
  if (count(s.begin(), s.end(), '_') == 0) {
    if (count(s.begin(), s.end(), 'X') != 0) {
      if (s[0] == 'X' and s.size() != 1) return;
      for (char k = '0'; k <= '9'; k++) {
        for (auto a : places) s[a] = k;
        if (stoi(s) % 25 == 0) {
          cnt++;
        }
      }
    } else if (stoi(s) % 25 == 0) {
      cnt++;
    }
    return;
  }
  for (int j = i; j < s.size(); j++) {
    if (s[j] == '_') {
      char temp = s[j];
      for (char k = '0'; k <= '9'; k++) {
        if (i == 0 and k == '0' and s.size() != 1) continue;
        s[j] = k;
        dfs(s, j + 1);
        s[j] = temp;
      }
    }
  }
}
signed main() {
  cin >> s;
  for (int j = 0; j < s.size(); j++)
    if (s[j] == 'X') places.push_back(j);
  dfs(s, 0);
  cout << (s[0] == '0' ? (s.size() == 1 ? 1 : 0) : cnt) << endl;
}
