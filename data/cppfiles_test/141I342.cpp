#include <bits/stdc++.h>
using namespace std;
string b;
int getNumber(char ch) { return (int)(ch - '0'); }
void add(int x) { b.push_back('0' + x); }
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    string s, a;
    cin >> a >> s;
    b = "";
    bool solution = true;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    int is = 0, ia = 0;
    while (ia < a.size() && is < s.size()) {
      long long int na = getNumber(a[ia]);
      long long int ns = getNumber(s[is]);
      ia++;
      is++;
      if (ns < na) {
        if (is == s.size()) {
          solution = false;
          break;
        }
        ns = ns + getNumber(s[is]) * 10;
        is++;
      }
      if (ns - na > 9) {
        solution = false;
        break;
      }
      add(ns - na);
    }
    if (solution == false || ia != a.size()) {
      cout << -1 << endl;
      continue;
    }
    for (int i = is; i < s.size(); i++) b.push_back(s[i]);
    if (!b.empty()) reverse(b.begin(), b.end());
    long long int x = 0;
    for (int i = 0; i < b.size(); i++) {
      if (x == 0 && b[i] == '0')
        continue;
      else {
        cout << b[i];
        x = 1;
      }
    }
    cout << endl;
  }
  return 0;
}
