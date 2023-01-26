#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string str;
int cnt = 0, cnt2 = 0;
vector<string> X;
vector<string> _;
int ans = 0;
void dfs1(int u, string s) {
  if (u == 2) return;
  if (!s.empty()) X.push_back(s);
  for (char c = '0'; c <= '9'; c++) {
    dfs1(u + 1, s + c);
  }
  return;
}
void dfs2(int u, string s) {
  if (u == cnt) {
    if (!s.empty()) _.push_back(s);
    return;
  }
  for (char c = '0'; c <= '9'; c++) {
    dfs2(u + 1, s + c);
  }
  return;
}
string get(string prop, string _, const string X) {
  string res;
  for (int i = 0, k = 0; i < prop.size(); i++) {
    if (prop[i] >= '0' && prop[i] <= '9')
      res += prop[i];
    else if (prop[i] == '_')
      res += _[k++];
    else if (prop[i] == 'X')
      res += X;
  }
  return res;
}
int main(void) {
  cin >> str;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == '_') cnt++;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == 'X') cnt2++;
  if (cnt == 0 && cnt2 == 0) {
    if ((str.front() == '0' && str.size() > 1) || str.empty())
      printf("0\n");
    else
      printf("1\n");
    return 0;
  }
  dfs1(0, "");
  dfs2(0, "");
  if (cnt == 0 && cnt2 != 0) {
    for (int i = 0; i < X.size(); i++) {
      string s;
      for (int j = 0; j < str.size(); j++)
        if (str[j] >= '0' && str[j] <= '9')
          s += str[j];
        else if (str[j] == 'X')
          s += X[i];
      if ((s.front() == '0' && s.size() > 1) || s.empty()) continue;
      long long t = stoll(s);
      if (t % 25 == 0) {
        ans++;
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  if (cnt != 0 && cnt2 == 0) {
    for (int i = 0; i < _.size(); i++) {
      string s;
      for (int j = 0, k = 0; j < str.size(); j++)
        if (str[j] >= '0' && str[j] <= '9')
          s += str[j];
        else
          s += _[i][k++];
      if ((s.front() == '0' && s.size() > 1) || s.empty()) continue;
      long long t = stoll(s);
      if (t % 25 == 0) {
        ans++;
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  if (cnt != 0 && cnt2 != 0) {
    for (int i = 0; i < _.size(); i++) {
      for (int j = 0; j < X.size(); j++) {
        string s = get(str, _[i], X[j]);
        if ((s.front() == '0' && s.size() > 1) || s.empty()) continue;
        long long t = stoll(s);
        if (t % 25 == 0) {
          ans++;
        }
      }
    }
    printf("%d\n", ans);
    return 0;
  }
  return 0;
}
