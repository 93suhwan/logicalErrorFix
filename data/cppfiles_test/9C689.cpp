#include <bits/stdc++.h>
using namespace std;
int t, n, fr[30];
char s[51];
int main() {
  cin >> t;
  for (int q3 = 1; q3 <= t; q3++) {
    cin >> s;
    for (int i = 0; i <= 27; i++) fr[i] = 0;
    int sz = strlen(s), cont = 0, aux = 0;
    for (int i = 0; i < sz; i++) {
      fr[s[i] - 'a']++;
    }
    for (int i = 0; i < sz; i++) {
      if (fr[s[i] - 'a'] == 1) aux++;
      if (fr[s[i] - 'a'] > 1) cont++, fr[s[i] - 'a'] = 0;
    }
    cout << cont + aux / 2 << endl;
  }
  return 0;
}
