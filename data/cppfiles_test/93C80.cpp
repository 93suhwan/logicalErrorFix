#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k == 1) {
      cout << n - 1 << "\n";
      continue;
    }
    long long comp = 1, remain = n - 1;
    long long ans = 0;
    while (comp < k && remain > comp) {
      remain -= comp;
      comp = 2 * comp;
      ans++;
    }
    if (remain % k == 0) {
      ans += (remain / k);
    } else {
      ans += (remain / k);
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
