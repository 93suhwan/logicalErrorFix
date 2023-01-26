#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const long long N = 2e5 + 5, NN = (1LL << 10) + 5, mod = 998244353;
bool isprime(long long n) {
  for (int i = 2; i <= n / i; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> v;
    int a, b, c;
    vector<int> vis(n + 2, 0);
    for (int(i) = 0; i < (k); i++) {
      cin >> a >> b >> c;
      vis[b] = 1;
    }
    int idx = -1;
    for (int(i) = 1; i <= (n); i++)
      if (!vis[i]) {
        idx = i;
        break;
      }
    for (int(i) = 0; i < (n); i++) {
      if (i + 1 == idx) continue;
      cout << idx << " " << i + 1 << "\n";
    }
  }
}
