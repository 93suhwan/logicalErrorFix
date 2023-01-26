#include <bits/stdc++.h>
using namespace std;
int main() {
  long long z;
  cin >> z;
  while (z--) {
    int x;
    cin >> x;
    string s = "";
    vector<string> v(x - 2);
    for (int i = 0; i < x - 2; i++) cin >> v[i];
    if (x == 3) {
      cout << v[0] << 'b' << endl;
    } else {
      s.push_back(v[0][0]);
      for (int i = 1; i < x - 2; i++) {
        if (v[i][0] == v[i - 1][1]) {
          s.push_back(v[i][0]);
        } else {
          s.push_back(v[i - 1][1]);
          s.push_back(v[i][0]);
        }
        if (i == x - 3) {
          s.push_back(v[i][1]);
        }
      }
      if (s.length() != x) {
        s.push_back('a');
      }
      cout << s << endl;
    }
  }
}
