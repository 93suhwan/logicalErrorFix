#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
template <class T>
void _W(const T &x) {
  cout << x << "\n";
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
int main() {
  int t;
  _R(t);
  while (t--) {
    int len;
    _R(len);
    string in;
    _R(in);
    for (int i = 0; i < len; i++) {
      if (in[i] == '?') {
        int l = i;
        int r = i;
        while (r + 1 < len && in[r + 1] == '?') {
          r++;
        }
        if (l != 0) {
          int flag = (in[l - 1] == 'R' ? 1 : 0);
          for (int j = l; j <= r; j++) {
            in[j] = flag == 1 ? 'B' : 'R';
            flag = !flag;
          }
        } else {
          int flag = (in[r + 1] == 'R' ? 1 : 0);
          for (int j = r; j >= l; j--) {
            in[j] = flag == 1 ? 'B' : 'R';
            flag = !flag;
          }
        }
        i = r;
      }
    }
    _W(in);
  }
  return 0;
}
