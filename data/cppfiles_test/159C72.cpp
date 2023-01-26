#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
const int MAXN = 1e6 + 1;
int prime[MAXN];
long long int h[MAXN], g[MAXN];
vector<int> p;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  prime[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!prime[i]) {
      prime[i] = i;
      p.push_back(i);
    }
    for (int x : p) {
      if (x * i > n) break;
      prime[x * i] = x;
      if (x == prime[i]) break;
    }
  }
  for (int x : p)
    h[x] = uniform_int_distribution<long long int>(0, 9223372036854775807)(rng);
  long long int ans = 0, cur = 0;
  map<long long int, int> gg;
  for (int i = 2; i <= n; i++) {
    int j = i;
    while (j != 1) {
      int cnt = 0;
      int pp = prime[j];
      while (j % pp == 0) {
        j /= pp;
        cnt++;
      }
      if (cnt % 2) cur = cur ^ h[pp];
    }
    g[i] = cur;
    ans = ans ^ g[i];
    gg[cur] = i;
  }
  if (!ans) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << i << " ";
  } else {
    for (int i = 1; i <= n; i++) {
      if ((g[i] ^ ans) == 0) {
        cout << n - 1 << '\n';
        for (int j = 1; j <= n; j++) {
          if (i == j) continue;
          cout << j << " ";
        }
        return 0;
      }
    }
    for (int i = 2; i <= n; i++) {
      if (gg[ans ^ g[i]]) {
        cout << n - 2 << '\n';
        int x = gg[ans ^ g[i]];
        for (int j = 1; j <= n; j++) {
          if (j == i || j == x) continue;
          cout << j << " ";
        }
        return 0;
      }
    }
    cout << n - 3 << '\n';
    for (int i = 1; i < n; i++) {
      if (i == 2 || i == n / 2) continue;
      cout << i << " ";
    }
  }
}
