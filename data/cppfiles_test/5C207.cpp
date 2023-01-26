#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T x, int pos) {
  return (x >> (pos - 1)) & 1;
}
template <class T>
void turn_on(T &x, int pos) {
  x = x | ((T)1 << (pos - 1));
}
template <class T>
void turn_off(T &x, int pos) {
  x = x & ~((T)1 << (pos - 1));
}
int read_int() {
  char r;
  bool start = false, neg = false;
  int ret = 0;
  while (true) {
    r = getchar();
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) continue;
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) break;
    if (start) ret *= 10;
    start = true;
    if (r == '-')
      neg = true;
    else
      ret += r - '0';
  }
  if (!neg)
    return ret;
  else
    return -ret;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long oo = 1e18 + 7;
const int MOD = 1e9 + 7;
int main() {
  srand(time(NULL));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = "0" + s + "0";
    t = "0" + t + "0";
    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (t[i] == '0') continue;
      if (s[i] == '0') {
        res++;
        continue;
      }
      if (s[i - 1] == '1') {
        res++;
        s[i - 1] = '0';
        continue;
      }
      if (s[i + 1] == '1') {
        res++;
        s[i + 1] = '0';
        continue;
      }
    }
    cout << res << endl;
  }
}
