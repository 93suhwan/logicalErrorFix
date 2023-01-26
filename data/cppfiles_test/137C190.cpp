#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1024;
long long read() {
  long long x = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return w ? -x : x;
}
int a[100], b[100];
int main() {
  long long x = read(), y = read();
  int cnt_a = 0, cnt_b = 0, ans = (x == y);
  while (x) a[++cnt_a] = x % 2, x /= 2;
  while (y) b[++cnt_b] = y % 2, y /= 2;
  string s1, s2, s;
  for (int i = cnt_a; i >= 1; --i) s1 += 48 + a[i];
  for (int i = cnt_b; i >= 1; --i) s += 48 + b[i];
  s2 = s1;
  reverse(s2.begin(), s2.end());
  string tmp = s1;
  while (tmp[tmp.size() - 1] == '0') tmp.pop_back();
  string t1 = tmp, t2 = tmp;
  reverse(t2.begin(), t2.end());
  int pos = s.find(s1);
  if (pos != -1) {
    int flag = 1;
    for (int i = 0; i < pos; ++i)
      if (s[i] == '0') flag = 0;
    for (int i = pos + s1.length(); i < s.length(); ++i)
      if (s[i] == '0') flag = 0;
    if (pos == s.length() - s1.length()) flag = 0;
    ans = max(ans, flag);
  }
  pos = s.find(s2);
  if (pos != -1) {
    int flag = 1;
    for (int i = 0; i < pos; ++i)
      if (s[i] == '0') flag = 0;
    for (int i = pos + s2.length(); i < s.length(); ++i)
      if (s[i] == '0') flag = 0;
    if (pos == 0) flag = 0;
    ans = max(ans, flag);
  }
  pos = s.find(t1);
  if (pos != -1) {
    int flag = 1;
    for (int i = 0; i < pos; ++i)
      if (s[i] == '0') flag = 0;
    for (int i = pos + t1.length(); i < s.length(); ++i)
      if (s[i] == '0') flag = 0;
    ans = max(ans, flag);
  }
  pos = s.find(t2);
  if (pos != -1) {
    int flag = 1;
    for (int i = 0; i < pos; ++i)
      if (s[i] == '0') flag = 0;
    for (int i = pos + t2.length(); i < s.length(); ++i)
      if (s[i] == '0') flag = 0;
    ans = max(ans, flag);
  }
  if (ans == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
