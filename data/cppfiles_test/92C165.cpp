#include <bits/stdc++.h>
using namespace std;
int T;
char s[110];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> s + 1;
    int len = strlen(s + 1);
    s[1] = s[len];
    cout << s + 1 << endl;
  }
  return 0;
}
