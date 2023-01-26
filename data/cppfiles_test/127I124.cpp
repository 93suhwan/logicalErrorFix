#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t;
    cin >> t;
    sort(s.begin(), s.end());
    set<int> s1;
    for (int i = 0; i < s1.size(); i++) {
      s1.insert(s[i]);
    }
    string str = "";
    for (auto itr = s1.begin(); itr != s1.end(); itr++) {
      str += *itr;
    }
    if (str == t) {
      cout << s << endl;
    } else {
      while (next_permutation(s.begin(), s.end())) {
        set<int> s1;
        for (int i = 0; i < s1.size(); i++) {
          s1.insert(s[i]);
        }
        string str = "";
        for (auto itr = s1.begin(); itr != s1.end(); itr++) {
          str += *itr;
        }
        if (str == t) {
          cout << s << endl;
          break;
        }
      }
    }
  }
  return 0;
}
