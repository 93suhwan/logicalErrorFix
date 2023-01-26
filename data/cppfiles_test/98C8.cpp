#include <bits/stdc++.h>
using namespace std;
string a, s;
int main() {
  int t;
  cin >> t;
  cin >> a;
  vector<int> out;
  map<char, int> sym{{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0},
                     {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0},
                     {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0},
                     {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0},
                     {'y', 0}, {'z', 0}};
  while (t--) {
    getline(cin, a);
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      sym[a[i]] = i;
    }
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ans += abs(sym[s[i]] - sym[s[i - 1]]);
      }
    }
    out.push_back(ans);
  }
  for (int el : out) {
    cout << el << endl;
  }
  return 0;
}
