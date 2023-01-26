#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 2;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    map<char, int> m;
    string temp = "";
    bool ans = true;
    for (int i = second.size() - 1; i >= 0; i--) {
      if (m.find(second[i]) == m.end()) {
        temp = second[i] + temp;
      }
      m[second[i]]++;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
      if (m[temp[i]] % (i + 1) != 0) ans = false;
      m[temp[i]] /= i + 1;
    }
    map<char, int> m2;
    if (ans) {
      string y = "";
      for (int i = 0; i < second.size(); i++) {
        m2[second[i]]++;
        if (m2[second[i]] > m[second[i]])
          break;
        else {
          y += second[i];
        }
      }
      string fin = y;
      string cur = "";
      for (int i = 0; i < temp.size(); i++) {
        cur += y;
        y.erase(remove(y.begin(), y.end(), temp[i]), y.end());
      }
      if (cur != second) {
        cout << -1 << endl;
      } else {
        cout << fin << " " << temp << endl;
      }
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
