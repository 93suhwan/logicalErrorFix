#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
inline int readint() {
  int ans = 0;
  bool sign = true;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') sign = false;
  while (isdigit(c)) {
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
    c = getchar();
  }
  return ans * (sign ? 1 : -1);
}
inline void readint(int &x) { x = readint(); }
template <typename... Ts>
inline void readint(int &x, Ts &...y) {
  x = readint();
  readint(y...);
}
const int INF = 0x3f3f3f3f;
const long long LLINF = ((long long)INF << 32) | INF;
const int mod = 1e9 + 7;
int main() {
  ;
  set<int> pow10;
  for (int i = 1; i <= 1e9; i *= 10) pow10.insert(i);
  int ___;
  cin >> ___;
  for (int tc = 1; tc <= ___; ++tc) {
    int s, n;
    readint(s, n);
    vector<int> ans;
    ans.push_back(s);
    while (ans.size() < n) {
      int no10 = -1;
      for (int i = 0; i < ans.size(); ++i) {
        if (!pow10.count(ans[i])) {
          no10 = i;
          break;
        }
      }
      if (no10 != -1) {
        int t = 1e9;
        while (ans[no10] <= t) {
          t /= 10;
        }
        ans.push_back(t);
        ans[no10] -= t;
      } else {
        sort(begin(ans), end(ans));
        int mx = -1;
        for (int i = 0; i < ans.size(); ++i) {
          if (ans[i] != 1) {
            mx = i;
            break;
          }
        }
        int t = 1e9;
        while (ans[mx] <= t) {
          t /= 10;
        }
        ans.push_back(t);
        ans[mx] -= t;
      }
    }
    for (int i : ans) printf("%d ", i);
    puts("");
  }
  return 0;
}
