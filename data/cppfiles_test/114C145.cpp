#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 1e6 + 7;
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
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n / 2 + 1; i++) {
      cout << a[i] << " " << a[0] << '\n';
    }
  }
}
