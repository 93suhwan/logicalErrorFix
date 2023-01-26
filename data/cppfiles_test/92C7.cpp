#include <bits/stdc++.h>
using namespace std;
int solveSimple(string s) {
  int ab = 0, ba = 0;
  int l = s.length();
  for (int i = 0; i < l - 1; i++)
    if (s[i] != s[i + 1])
      if (s[i] == 'a')
        ab++;
      else
        ba++;
  return abs(ab - ba);
}
char flip(char a) {
  if (a == 'a') return 'b';
  return 'a';
}
void solve() {
  string s;
  cin >> s;
  int l = s.length();
  vector<string> helpers;
  helpers.push_back(s);
  string t = s;
  t[0] = flip(t[0]);
  helpers.push_back(t);
  t[0] = flip(t[0]);
  t[l - 1] = flip(t[l - 1]);
  helpers.push_back(t);
  t[0] = flip(t[0]);
  helpers.push_back(t);
  for (unsigned int i = 0; i < helpers.size(); i++) {
    if (solveSimple(helpers[i]) == 0) {
      cout << helpers[i] << endl;
      return;
    }
  }
}
int main() {
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
