#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void maximize(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
void minimize(T1 &a, T2 b) {
  if (b < a) a = b;
}
template <class T>
void read(T &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
template <class T, class... Ts>
void read(T &a, Ts &...args) {
  read(a);
  read(args...);
}
int n;
char s[1000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = (1); _ <= (t); _++) {
    cin >> n;
    cin >> s + 1;
    int ptr = 0;
    for (int i = (1); i <= (n); i++)
      if (isalnum(s[i])) {
        if (ptr == 0) continue;
        int diff = (s[i] == 'R') ? 'B' : 'R';
        bool cur = true;
        for (int pos = (i - 1); pos >= (ptr); pos--)
          s[pos] = cur ? diff : s[i], cur = !cur;
        ptr = 0;
      } else if (!ptr)
        ptr = i;
    if (ptr) {
      if (ptr == 1)
        for (int i = (1); i <= (n); i++) s[i] = (i & 1) ? 'R' : 'B';
      else {
        int diff = (s[ptr - 1] == 'R') ? 'B' : 'R';
        bool cur = true;
        for (int i = (ptr); i <= (n); i++)
          s[i] = cur ? diff : s[ptr - 1], cur = !cur;
      }
    }
    for (int i = (1); i <= (n); i++) cout << s[i];
    cout << '\n';
  }
}
