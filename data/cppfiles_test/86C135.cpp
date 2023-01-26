#include <bits/stdc++.h>
using namespace std;
constexpr int MaxN = 1000000 + 5;
char s[MaxN], t[MaxN];
int a[MaxN], b[MaxN];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  int n;
  while (T--) {
    cin >> n >> (s + 1) >> (t + 1);
    for (register int i = (1); i <= (n); ++i)
      if (s[i] != t[i]) s[i] = '*';
    int l0 = 0, l1 = 0;
    for (register int i = (1); i <= (n); ++i) {
      if (s[i] == '*') {
        a[i] = (a[i - 1] + 2);
        l0 = l1 = i;
      } else if (s[i] == '0') {
        a[i] = (a[i - 1] + 1);
        if (l1) a[i] = max(a[i], a[l1 - 1] + 2);
        l0 = i;
      } else if (s[i] == '1') {
        a[i] = a[i - 1];
        if (l0) a[i] = max(a[i], a[l0 - 1] + 2);
        l1 = i;
      }
    }
    cout << a[n] << endl;
  }
  return 0;
}
