#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
int T;
int n;
char str[MAXN], st[MAXN];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    scanf("%s", str);
    int ans = 0;
    for (int i = 0; i < n; i++) st[i] = str[i];
    st[n] = '\0';
    sort(st, st + n);
    for (int i = 0; i < n; i++) {
      if (st[i] != str[i]) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
