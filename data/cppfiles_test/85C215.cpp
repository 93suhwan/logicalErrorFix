#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int M = 2e5 + 7;
int main() {
  int t = read();
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (!cnt && s[i] == '0')
        cnt++;
      else if (i && s[i] == '0' && s[i - 1] == '1')
        cnt++;
    }
    cout << min(cnt, 2) << endl;
  }
  return 0;
}
