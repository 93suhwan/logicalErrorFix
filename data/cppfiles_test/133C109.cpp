#include <bits/stdc++.h>
using namespace std;
char s[110][2];
bool is(char ch) { return (ch != ' ') && (ch != '\n'); }
char nc() {
  char ch;
  while (!is(ch = getchar()))
    ;
  return ch;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
      s[i][0] = nc();
      s[i][1] = nc();
    }
    cout << s[0][0] << s[0][1];
    bool bk = false;
    for (int i = 1; i < n - 2; i++) {
      if (s[i - 1][1] != s[i][0]) {
        cout << s[i][0];
        bk = true;
      }
      cout << s[i][1];
    }
    if (!bk) cout << "a";
    cout << endl;
  }
  return 0;
}
