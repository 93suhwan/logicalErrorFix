#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  char s[42];
  char u[42];
  do {
    int n;
    cin >> n;
    cin >> s;
    copy(s, s + n, u);
    sort(u, u + n);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += s[i] == u[i];
    ans = n - ans;
    cout << ans << '\n';
  } while (--t);
}
