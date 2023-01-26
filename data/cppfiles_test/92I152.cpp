#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
long long a[M], cont, c[M], l[M], b[M];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cont = 0;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        cnt1++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        cnt2++;
    }
    if (cnt1 == cnt2)
      cout << s << endl;
    else if (cnt1 > cnt2) {
      string t1, t2;
      t1 = s;
      int tmp1 = 0, tmp2 = 0;
      for (int i = s.length() - 1; i >= 0; i--) {
        if (t1[i] == 'a') break;
        t1[i] = 'a';
        tmp1++;
      }
      t2 = s;
      for (int i = 0; i < s.length(); i++) {
        if (t2[i] == 'b') break;
        t2[i] = 'b';
        tmp2++;
      }
      if (tmp1 < tmp2 && tmp1 != 0)
        cout << t1 << endl;
      else
        cout << t2 << endl;
    } else {
      string t1, t2;
      t1 = s;
      int tmp1 = 0, tmp2 = 0;
      for (int i = s.length() - 1; i >= 0; i--) {
        if (t1[i] == 'b') break;
        t1[i] = 'b';
        tmp1++;
      }
      t2 = s;
      for (int i = 0; i < s.length(); i++) {
        if (t2[i] == 'a') break;
        t2[i] = 'a';
        tmp2++;
      }
      if (tmp1 < tmp2 && tmp1 != 0)
        cout << t1 << endl;
      else
        cout << t2 << endl;
    }
  }
}
