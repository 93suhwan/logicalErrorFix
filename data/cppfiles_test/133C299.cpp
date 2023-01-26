#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n;
    string ans, e, ant;
    bool ok = 0;
    for (int i = 0; i < (int)n - 2; i++) {
      cin >> e;
      if (!i)
        ans += e[0];
      else if (e[0] == ant[1])
        ans += e[0];
      else
        ans += ant[1], ans += e[0], ok = 1;
      ant = e;
    }
    ans += ant[1];
    if (!ok) ans += "b";
    cout << ans << '\n';
  }
}
