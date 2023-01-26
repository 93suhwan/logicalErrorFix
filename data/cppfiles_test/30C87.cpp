#include <bits/stdc++.h>
using namespace std;
inline bool read(int& val) { return scanf("%d", &val) != -1; }
inline bool read(double& val) { return scanf("%lf", &val) != -1; }
inline bool read(char* val) { return scanf("%s", val) != -1; }
template <class T1, class T2>
inline bool read(T1& a, T2& b) {
  return read(a) && read(b);
}
template <class T1, class T2, class T3>
inline bool read(T1& a, T2& b, T3& c) {
  return read(a) && read(b) && read(c);
}
template <class T1, class T2, class T3, class T4>
inline bool read(T1& a, T2& b, T3& c, T4& d) {
  return read(a) && read(b) && read(c) && read(d);
}
template <class T1, class T2, class T3, class T4, class T5>
inline bool read(T1& a, T2& b, T3& c, T4& d, T5& e) {
  return read(a) && read(b) && read(c) && read(d) && read(e);
}
const int N = 211111;
double eps = 1e-9;
char str[N];
int main() {
  int ncase;
  read(ncase);
  for (int icase = 0, _ = (ncase); icase < _; ++icase) {
    int n;
    read(n);
    read(str);
    int ans = -1;
    for (int k = 0, _ = (26); k < _; ++k) {
      int cnt = 0;
      char c = 'a' + k;
      int r = n - 1;
      int l = 0;
      while (l < r) {
        if (str[l] == str[r]) {
          l++;
          r--;
        } else if (str[l] == c) {
          cnt++;
          l++;
        } else if (str[r] == c) {
          cnt++;
          r--;
        } else {
          cnt = -1;
          break;
        }
      }
      if (cnt != -1) {
        if (ans == -1 || cnt < ans) {
          ans = cnt;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
