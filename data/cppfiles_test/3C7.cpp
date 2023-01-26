#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string str;
int cnt = 0, cnt2 = 0;
long long ans = 0;
void dfs(string str, int u, string s, char c) {
  if (u == -1) {
    if ((s.front() == '0' && s.size() > 1) || s.empty()) {
      return;
    }
    long long t = stoll(s);
    if (t % 25 == 0) {
      ans++;
    }
    return;
  }
  if (s.size() && (s.back() != '5' && s.back() != '0')) return;
  if (s.size() >= 4 && stoll(s) % 25) return;
  if (str[u] >= '0' && str[u] <= '9') dfs(str, u - 1, str[u] + s, c);
  if (str[u] == '_') {
    for (char i = '0'; i <= '9'; i++) dfs(str, u - 1, i + s, c);
  }
  if (str[u] == 'X') {
    dfs(str, u - 1, c + s, c);
  }
  return;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin >> str;
  if (str.back() >= '0' && str.back() <= '9') {
    if (str.back() == '5' || str.back() == '0')
      ;
    else {
      printf("0\n");
      return 0;
    }
  }
  for (int i = 0; i < str.size(); i++)
    if (str[i] == '_') cnt++;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == 'X') cnt2++;
  if (cnt == 0 && cnt2 == 0) {
    if ((str.front() == '0' && str.size() > 1) || str.empty())
      printf("0\n");
    else {
      long long t = stoll(str);
      if (t % 25 == 0)
        printf("1\n");
      else
        printf("0\n");
    }
    return 0;
  }
  if (str.back() >= '0' && str.back() <= '9') {
    if (cnt2 == 0) {
      string ss;
      ss += str.back();
      dfs(str, str.size() - 2, ss, ' ');
      printf("%lld\n", ans);
      return 0;
    } else {
      string ss;
      ss += str.back();
      for (char x = '0'; x <= '9'; x++) dfs(str, str.size() - 2, ss, x);
      printf("%lld\n", ans);
    }
    return 0;
  } else {
    if (str.back() == '_') {
      str[str.size() - 1] = '5';
      if (cnt2 == 0) {
        dfs(str, str.size() - 2, "5", ' ');
      } else {
        for (char x = '0'; x <= '9'; x++) dfs(str, str.size() - 2, "5", x);
      }
      str[str.size() - 1] = '0';
      if (cnt2 == 0) {
        dfs(str, str.size() - 2, "0", ' ');
      } else {
        for (char x = '0'; x <= '9'; x++) dfs(str, str.size() - 2, "0", x);
      }
      printf("%lld\n", ans);
    } else if (str.back() == 'X') {
      string ss = str;
      for (int i = 0; i < ss.size(); i++)
        if (ss[i] == 'X') ss[i] = '5';
      dfs(ss, ss.size() - 2, "5", ' ');
      ss = str;
      for (int i = 0; i < ss.size(); i++)
        if (ss[i] == 'X') ss[i] = '0';
      dfs(ss, ss.size() - 2, "0", ' ');
      printf("%lld\n", ans);
      return 0;
    }
  }
  return 0;
}
