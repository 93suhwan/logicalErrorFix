#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long a[maxn], sum[maxn];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long maxx = a[1];
    long long sum = a[1];
    for (int i = 2; i <= n; i++) {
      a[i] -= sum;
      maxx = max(maxx, a[i]);
      sum += a[i];
    }
    cout << maxx << '\n';
  }
  return 0;
}
