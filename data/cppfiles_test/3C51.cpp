#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 0x3f3f3f3f;
long long cnt, ans;
string str;
void solve(long long X, long long now, long long num) {
  if (now == str.size()) {
    if (num % 25 == 0) ans += cnt;
    return;
  }
  num *= 10;
  if (str[now] == '_') {
    long long first;
    if ((str.size() == 2 && now == 0) || (str[now] == 'X' && str[0] == 'X'))
      first = 1;
    else
      first = 0;
    for (long long i = (first); i <= (9); i++) {
      solve(X, now + 1, num + i);
    }
  } else if (str[now] == 'X')
    solve(X, now + 1, num + X);
  else
    solve(X, now + 1, num + (str[now] - '0'));
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
  bool flag = 0;
  for (long long i = (0); i < (9); i++)
    if (str[i] == 'X') flag = 1;
  if (flag) {
    int first = 0;
    if (str[0] == 'X') first++;
    for (long long i = (first); i <= (9); i++) solve(i, str.size() - 2, 0);
  } else
    solve(-1, str.size() - 2, 0);
  cout << ans << "\n";
  return 0;
}
