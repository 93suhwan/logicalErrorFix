#include <bits/stdc++.h>
using namespace std;
const int NF = 0x3f3f3f3f;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
const long long int MOD = 1e9 + 7;
const long double PI = 3.14159265358979323846264338327950288;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<bool> v(n + 1, true);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      v[b] = false;
    }
    int rt;
    for (int i = 1; i <= n; i++) {
      if (v[i]) {
        rt = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == rt) continue;
      cout << i << ' ' << rt << '\n';
    }
  }
  return 0;
}
