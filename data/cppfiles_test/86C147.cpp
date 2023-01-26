#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 5;
int a[N], b[N];
int cpp(int a, int b) { return a > b; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, ans = 0;
    scanf("%d", &n);
    string s, u;
    cin >> s >> u;
    for (int i = 0; i < n; i++) {
      if ((s[i] == '1' && u[i] == '0') || (s[i] == '0' && u[i] == '1'))
        ans += 2;
      else if (s[i] == '0' && u[i] == '0') {
        if (i + 1 < n && s[i + 1] == '1' && u[i + 1] == '1') {
          ans += 2;
          i++;
        } else
          ans++;
      } else {
        if (i + 1 < n && (s[i + 1] == '0' || u[i + 1] == '0')) {
          ans += 2;
          i++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
