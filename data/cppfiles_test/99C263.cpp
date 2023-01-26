#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n, m, k;
char ans[52][52];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = (i == j ? 'X' : ' ');
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        for (int j = 0; j < n; ++j) {
          if (i != j) {
            ans[i][j] = '=';
            ans[j][i] = '=';
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '2') {
        int j;
        for (j = 0; j < n; ++j) {
          if (ans[i][j] == ' ') {
            break;
          }
        }
        if (j >= n) {
          ok = false;
          break;
        }
        ans[i][j] = '+';
        ans[j][i] = '-';
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (ans[i][j] == ' ') {
          ans[i][j] = '=';
        }
        printf("%c", ans[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}
