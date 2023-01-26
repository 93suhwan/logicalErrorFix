#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;
    int ca = 0;
    int cb = 0;
    int cc = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'A') {
        ca++;
      }
      if (str[i] == 'B') {
        cb++;
      }
      if (str[i] == 'C') {
        cc++;
      }
    }
    if (cb == cc + ca) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
