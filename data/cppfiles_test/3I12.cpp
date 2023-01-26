#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
long long cnt, ans;
string str;
void solve(long long now, long long num) {
  if (now == str.size()) {
    if (num % 25 == 0) ans += cnt;
    return;
  }
  num *= 10;
  if (str[now] == '_' || str[now] == 'X') {
    long long first;
    if ((str.size() == 2 && now == 0) || (str[now] == 'X' && str[0] == 'X'))
      first = 1;
    else
      first = 0;
    for (long long i = (first); i <= (9); i++) {
      solve(now + 1, num + i);
    }
  } else
    solve(now + 1, num + (str[now] - '0'));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> str;
  if (str.size() < 2) {
    if (str[0] == 'X' || str[0] == '_' || str[0] == '0')
      cout << "1\n";
    else
      cout << "0\n";
    return 0;
  }
  if (str[0] == '0') {
    cout << "0\n";
    return 0;
  }
  cnt = 1;
  for (long long i = (0); i < (str.length() - 2); i++) {
    if (str[i] == '_' && i != 0)
      cnt *= 10;
    else if (str[i] == '_' && i == 0)
      cnt *= 9;
  }
  bool flag = 1;
  for (long long i = (str.length() - 2); i < (str.length()); i++) {
    if (str[i] == 'X') flag = 0;
  }
  if (flag) {
    if (str[0] == 'X')
      cnt *= 9;
    else {
      flag = 0;
      for (long long i = (1); i < (str.length() - 2); i++) {
        if (str[i] == 'X') flag = 1;
      }
      if (flag) ans *= 10;
    }
  }
  if (str[str.size() - 1] == 'X' && str[str.size() - 2] == 'X')
    ans = cnt;
  else
    solve(str.size() - 2, 0);
  cout << ans << "\n";
  return 0;
}
