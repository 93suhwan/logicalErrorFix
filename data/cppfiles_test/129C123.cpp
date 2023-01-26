#include <bits/stdc++.h>
using namespace std;
long long int pc;
void PrintCase() { printf("Case #%lli: ", ++pc); }
long long int bigmod(long long int n, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return (n + 1000000007) % 1000000007;
  if (p % 2)
    return (bigmod(n, p - 1) * n + 1000000007) % 1000000007;
  else {
    long long int x = bigmod(n, p / 2);
    return (x * x + 1000000007) % 1000000007;
  }
}
long long int power(long long int n, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  if (p % 2)
    return power(n, p - 1) * n;
  else {
    long long int x = power(n, p / 2);
    return x * x;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, k;
    cin >> n;
    long long int a[n + 5], vis[n + 5];
    memset(vis, 0, sizeof(vis));
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] <= n and vis[a[i]] == 0) {
        vis[a[i]] = 1;
      } else
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    long long int ok = 0;
    for (i = 1, j = 0; i <= n and j < v.size(); i++) {
      if (vis[i]) continue;
      long long int x = v[j];
      if (x % (x - i) == i) {
        vis[i] = 1;
        ok++;
      } else {
        ok = -1;
        break;
      }
      j++;
    }
    cout << ok << endl;
  }
}
