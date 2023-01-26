#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 2e18 + 5;
const long long mod = 1e9 + 7;
const long long hashmod = 100003;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    char a[55];
    cin >> a + 1;
    int n = strlen(a + 1);
    int c[2] = {0, 0};
    for (int i = 1; i <= n; i++) {
      if (a[i] == 'B')
        c[1]++;
      else
        c[0]++;
    }
    if (c[0] == c[1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
