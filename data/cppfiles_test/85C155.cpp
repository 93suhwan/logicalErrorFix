#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x = x * f;
}
string s;
int T, ans;
signed main() {
  cin >> T;
  while (T) {
    T--;
    ans = 0;
    cin >> s;
    if (s[0] == '0') ans++;
    for (int i = 1; i < s.length(); i++)
      if (s[i] == '0' and s[i - 1] == '1') ans++;
    cout << min(ans, 2) << endl;
  }
  return 0;
}
