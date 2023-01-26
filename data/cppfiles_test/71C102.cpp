#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
string s;
int k;
int cc[128], tt;
bool valid(string s, int x) {
  tt++;
  for (int i = 0; i < (((int)(s).size())); ++i) {
    if (cc[s[i]] != tt) {
      cc[s[i]] = tt;
      x--;
      if (x < 0) return 0;
    }
  }
  return 1;
}
void solve() {
  if (valid(s, k)) {
    W(s);
    return;
  }
  for (int i = ((int)(s).size()) - 1; i >= 0; i--) {
    for (int j = s[i] + 1; j <= '9'; j++) {
      string tmp = s;
      tmp[i] = j;
      for (int kk = ('0'); kk <= ('9'); ++kk) {
        for (int r = (i + 1); r < (((int)(s).size())); ++r) {
          tmp[r] = kk;
        }
        if (valid(tmp, k)) {
          W(tmp);
          return;
        }
      }
    }
  }
}
void input() { R(s, k); }
int main() {
  int ___T;
  scanf("%d", &___T);
  for (int cs = 1; cs <= ___T; cs++) {
    input();
    solve();
  }
  return 0;
}
