#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200005;
const long long mod = 1e9 + 7;
const long long MULTI_TESTS = 1;
void unstoppable() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0, ThxDem = n; i < ThxDem; i++) cin >> a[i];
  long long ans = a[0];
  for (int i = 1, ThxDem = n; i < ThxDem; i++) {
    ans &= a[i];
  }
  cout << ans << endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (MULTI_TESTS) {
    long long Q;
    cin >> Q;
    while (Q--) {
      unstoppable();
    }
  } else {
    unstoppable();
  }
  return 0;
}
