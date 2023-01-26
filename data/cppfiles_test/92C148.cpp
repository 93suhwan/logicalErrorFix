#include <bits/stdc++.h>
using namespace std;
inline int gin() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = (s << 3) + (s << 1) + (c ^ 48);
    c = getchar();
  }
  return s * f;
}
signed main() {
  int T = gin();
  while (T--) {
    string s;
    cin >> s;
    int AB = 0, BA = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        AB++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        BA++;
    }
    if (AB != BA)
      if (s[0] == 'a')
        s[0] = 'b';
      else
        s[0] = 'a';
    printf("%s\n", s.c_str());
  }
  return 0;
}
