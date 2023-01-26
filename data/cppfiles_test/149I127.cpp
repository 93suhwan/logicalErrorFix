#include <bits/stdc++.h>
using namespace std;
long long t, n, k, x, cb[2005], j, tot;
string s;
int main() {
  cin >> t;
  while (t--) {
    s = "";
    j = 0, tot = 1;
    cb[1] = 1;
    cin >> n >> k >> x >> s;
    cout << "???" << endl;
    for (int i = n - 1; i >= 0;) {
      while (i >= 0 && s[i--] == '*') {
        j++;
      }
      if (j != 0)
        if (x / cb[tot] >= (j * k + 1))
          cb[++tot] = cb[tot - 1] * (j * k + 1);
        else
          cb[++tot] = x + 1;
      j = 0;
    }
    tot--;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        cout << 'a';
      else {
        for (int j = 1; j <= (x - 1) / cb[tot]; j++) cout << 'b';
        x -= (x - 1) / cb[tot] * cb[tot--];
        while (s[i + 1] == '*') i++;
      }
    }
    cout << endl;
  }
  return 0;
}
