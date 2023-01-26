#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int t, count;
  cin >> t;
  int a[1000][1];
  int b[1000][1];
  int c[1000][1];
  string* str = new string[t];
  for (int i = 0; i < t; i++) {
    cin >> str[i];
    count = str[i].length();
    a[i][0] = 0;
    b[i][0] = 0;
    c[i][0] = 0;
    for (int p = 0; p < count; p++) {
      if (str[i][p] == 'A') {
        a[i][0] += 1;
        continue;
      }
      if (str[i][p] == 'B') {
        b[i][0] += 1;
        continue;
      }
      if (str[i][p] == 'C') {
        c[i][0] += 1;
        continue;
      }
    }
  }
  for (int i = 0; i < t; i++) {
    int l = b[i][0] - a[i][0];
    int y = b[i][0] - c[i][0];
    if ((a[i][0] == b[i][0]) && (c[i][0] == 0)) {
      cout << "Yes" << endl;
      continue;
    }
    if ((c[i][0] == b[i][0]) && (a[i][0] == 0)) {
      cout << "Yes" << endl;
      continue;
    }
    if (l == c[i][0]) {
      cout << "Yes" << endl;
      continue;
    }
    if (y == a[i][0]) {
      cout << "Yes" << endl;
      continue;
    }
    cout << "No" << endl;
  }
  return 0;
}
