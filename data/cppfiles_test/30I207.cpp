#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long md = LLONG_MAX;
long long pow(long long val, long long pw) {
  if (pw == 0) return 1;
  if (pw % 2 == 0) {
    long long tmp = pow(val, pw / 2) % md;
    return (tmp * tmp) % md;
  } else
    return (val * pow(val, pw - 1)) % md;
}
long long ar[100005], br[100005];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> ar[i];
  for (long long i = 2; i <= n; i += 2) {
    br[i] = ar[i - 1];
    br[i - 1] = -ar[i];
  }
  if (n % 2 == 1) {
    br[n] = ar[n - 1];
    br[n - 1] += -ar[n];
  }
  if (br[n - 1] == 0) {
    br[n] += ar[n - 1];
    br[n - 1] += -ar[n];
  }
  for (long long i = 1; i <= n; i++) cout << br[i] << " ";
  cout << endl;
}
int main() {
  init();
  long long t, cs = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
