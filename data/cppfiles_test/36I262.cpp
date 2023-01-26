#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18 + 10;
const long long mod = 1e9 + 7;
const long long hashmod = 100003;
const int MAXN = 100000;
const int MAXM = 20000000;
int T;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n <= 26) {
      for (int i = 0; i < n; i++) {
        cout << (char)('a' + i);
      }
      cout << '\n';
      continue;
    }
    int val = (n - 2) / 2;
    for (int i = 1; i <= val; i++) cout << 'a';
    cout << "bc";
    for (int i = val + 3; i <= n; i++) cout << 'a';
    cout << '\n';
  }
}
