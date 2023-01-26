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
    set<char> ass;
    for (int i = 0; i < s.size(); i++) {
      ass.insert(s[i]);
    }
    string str = " ";
    for (auto itr = ass.begin(); itr != ass.end(); itr++) {
      str += '*itr';
    }
    if (str != t) {
      cout << s << endl;
    } else {
      while (next_permutation(s.begin(), s.end())) {
        set<char> ass;
        for (int i = 0; i < s.size(); i++) {
          ass.insert(s[i]);
        }
        string str = " ";
        for (auto itr = ass.begin(); itr != ass.end(); itr++) {
          str += '*itr';
        }
        if (str != t) {
          cout << s << endl;
          break;
        }
      }
    }
  }
  return 0;
}
