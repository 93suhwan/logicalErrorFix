#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  int P, i;
} node;
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % 1000000007;
    m = (m * m) % 1000000007;
    b /= 2;
  }
  return c;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
double roundd(double x, int k) {
  x = (int)(x * pow(10, k) + 0.5);
  x = (double)(x / pow(10, k));
  return x;
}
void solve() {
  int n, m, k = 1;
  cin >> n >> m;
  vector<int> V(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    V[b] = 1;
    int j = k;
    while (V[j] == 1) j++;
    k = j;
  }
  for (int i = 1; i <= n; i++) {
    if (i == k) continue;
    cout << i << " " << k << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
