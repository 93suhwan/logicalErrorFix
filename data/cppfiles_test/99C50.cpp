#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, i, j, ii, jj, zx, xc, tes, t, p[59], pi;
string s;
char ch[59][59];
void print() {
  cout << "YES" << endl;
  for (i = 1; i <= a; i++) {
    for (j = 1; j <= a; j++) {
      cout << ch[i][j];
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> tes;
  for (t = 1; t <= tes; t++) {
    cin >> a;
    cin >> s;
    s.insert(0, "0");
    pi = 0;
    for (i = 1; i <= a; i++) {
      if (s[i] == '2') {
        pi++;
        p[pi] = i;
      }
    }
    if (pi != 0 && pi <= 2) {
      cout << "NO" << endl;
      continue;
    }
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= a; j++) {
        if (i == j)
          ch[i][j] = 'X';
        else
          ch[i][j] = '=';
      }
    }
    for (i = 1; i <= pi; i++) {
      j = i + 1;
      if (j > pi) j = 1;
      ch[p[i]][p[j]] = '+';
      ch[p[j]][p[i]] = '-';
    }
    print();
  }
  return 0;
}
