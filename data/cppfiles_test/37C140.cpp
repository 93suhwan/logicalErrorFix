#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void TestCase() {
  int n, m;
  cin >> n >> m;
  vector<bool> take(n + 1, false);
  for (int i = 0, a, b, c; i < m; i++) {
    cin >> a >> b >> c;
    take[b] = true;
  }
  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (!take[i]) root = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i == root)
      continue;
    else
      cout << root << " " << i << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}
