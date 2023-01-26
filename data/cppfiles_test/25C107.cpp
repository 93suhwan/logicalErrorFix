#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool fun(int64_t id) {
  int64_t n = s2.size();
  for (int64_t i = 0; i < n; i++) {
    string t = "";
    int64_t c = 1;
    for (int64_t j = id; j < s1.size(); j++) {
      if (c > i) break;
      c++;
      t += s1[j];
    }
    int64_t x = t.size();
    if (x != i) continue;
    for (int64_t j = id + i; j >= 0; j--) {
      if (t.size() == s2.size()) break;
      t += s1[j];
    }
    if (t == s2) {
      return true;
    }
  }
  return false;
}
void SOLVE__MAIN() {
  cin >> s1 >> s2;
  char st = s2[0];
  int64_t n = s1.size();
  for (int64_t i = 0; i < n; i++) {
    if (s1[i] == st) {
      if (fun(i) == true) {
        cout << "Yes"
             << "\n";
        return;
      }
    }
  }
  cout << "No"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(5);
  int64_t __TESTCASES = 1;
  cin >> __TESTCASES;
  while (__TESTCASES--) {
    SOLVE__MAIN();
  }
}
