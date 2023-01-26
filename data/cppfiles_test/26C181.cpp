#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int temp = power(a, n / 2);
  temp = temp * temp % mod;
  if (n % 2) temp = a * temp % mod;
  return temp;
}
long long int inverse(long long int a) { return power(a, mod - 2); }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void dfs(long long int u, vector<long long int> v[], bool vis[]) {
  vis[u] = true;
  for (long long int x : v[u]) {
    if (vis[x] == false) dfs(x, v, vis);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long int t = 1, i;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long int c1 = 0, c2 = 0, o1 = 0, o2 = 0;
    for (i = 1; i <= 10; i++) {
      if (i % 2 && str[i - 1] == '?') c1++;
      if (i % 2 == 0 && str[i - 1] == '?') c2++;
      if (i % 2 && str[i - 1] == '1') o1++;
      if (i % 2 == 0 && str[i - 1] == '1') o2++;
      if (i % 2) {
        if (o1 + (10 - i) / 2 < o2 + c2) break;
        if (o2 + (11 - i) / 2 < o1 + c1) break;
      } else {
        if (o2 + (10 - i) / 2 < o1 + c1) break;
        if (o1 + (11 - i) / 2 < o2 + c2) break;
      }
    }
    if (i <= 10)
      cout << i << "\n";
    else
      cout << 10 << "\n";
  }
  return 0;
}
