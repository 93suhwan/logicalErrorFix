#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, e, d, m, i, j, k, t, T, r, l;
  long long int x;
  cin >> T;
  for (t = 1; t <= T; t++) {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    l = s1.length();
    char ch[l];
    for (i = 0; i < l; i++) {
      ch[i] = s1[i];
    }
    sort(ch, ch + l);
    bool bl = false;
    for (i = 0; i < l; i++) {
      if (ch[i] == s2[0] && ch[i + 1] == s2[1]) {
        if (i + 2 <= l - 1) {
          j = i + 2;
          while (ch[i + 1] == ch[j]) {
            if (j == l - 1) {
              bl = true;
              break;
            }
            j++;
          }
          if (bl == false) {
            swap(ch[i + 1], ch[j]);
          } else {
            swap(ch[i], ch[i + 1]);
          }
        } else {
          swap(ch[i], ch[i + 1]);
        }
      }
    }
    for (i = 0; i < l; i++) {
      cout << ch[i];
    }
    cout << endl;
  }
  return 0;
}
