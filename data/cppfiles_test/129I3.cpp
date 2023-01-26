#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
void maximize(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
void minimize(T1 &a, T2 b) {
  if (b < a) a = b;
}
template <class T>
void read(T &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  while (c != '-' && !isalnum(c)) c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
template <class T, class... Ts>
void read(T &a, Ts &...args) {
  read(a);
  read(args...);
}
int n;
int a[1000001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int _ = (1); _ <= (t); _++) {
    cin >> n;
    for (int i = (1); i <= (n); i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = (1); i <= (n); i++) {
      if (i == a[i]) continue;
      ans++;
      int val = a[i] / 2 - (a[i] % 2 == 0);
      if (val < i) {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
}
