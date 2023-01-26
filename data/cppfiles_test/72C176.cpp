#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
int T, K;
string n;
bool use[10];
bool smaller(const string &s, const string &t) {
  if (t.empty()) return 1;
  for (int i = (0); i <= (((int)(s).size()) - 1); ++i)
    if (s[i] < t[i])
      return 1;
    else if (t[i] < s[i])
      return 0;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n >> K;
    for (int i = (0); i <= (9); ++i) use[i] = 0;
    int num = 0;
    string ans = "", cur = "";
    for (int i = (0); i <= (((int)(n).size()) - 1); ++i) {
      int mn = n[i] - '0' + 1;
      if (num == K) {
        mn = 10;
        for (int j = (n[i] - '0' + 1); j <= (9); ++j)
          if (use[j]) {
            mn = j;
            break;
          }
      }
      if (mn <= 9) {
        int add = !use[mn];
        if (num + add < K) {
          string tem = cur;
          tem += (mn + '0');
          while (((int)(tem).size()) < ((int)(n).size())) tem += '0';
          if (smaller(tem, ans)) ans = tem;
        } else {
          int mn1 = mn;
          for (int j = (0); j <= (mn - 1); ++j)
            if (use[j]) {
              mn1 = j;
              break;
            }
          string tem = cur;
          tem += (mn + '0');
          while (((int)(tem).size()) < ((int)(n).size()))
            tem += (char)(mn1 + '0');
          if (smaller(tem, ans)) ans = tem;
        }
      }
      if (!use[n[i] - '0']) num++, use[n[i] - '0'] = 1;
      if (num > K) break;
      cur += n[i];
    }
    if (num <= K) ans = cur;
    cout << ans << '\n';
  }
  return 0;
}
