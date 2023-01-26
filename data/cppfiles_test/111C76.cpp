#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> s[51];
  s[1].push_back("()");
  for (int i = 2; i <= 50; i++) {
    for (int j = 0; j < s[i - 1].size(); j++) {
      string t = s[i - 1][j] + "()";
      string r = "(" + s[i - 1][j] + ")";
      if (s[i].size() <= i) {
        s[i].push_back(t);
        s[i].push_back(r);
      } else
        break;
    }
  }
  while (n--) {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
      cout << s[x][i] << endl;
    }
  }
}
