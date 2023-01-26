#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
long long a[MAX_N];
bool seen[MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      seen[a[i]] = 1;
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int b = a[n - 1] % a[i];
      if (seen[b] == 0) {
        cout << a[n - 1] << " " << a[i] << '\n';
        ans++;
      }
      if (ans == n / 2) break;
    }
    fill(seen, seen + n, 0);
  }
}
