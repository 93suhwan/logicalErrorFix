#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    long long count = 0;
    for (long long i = 0; i < n; i += 2) {
      long long cur = 0;
      long long diff = 0;
      for (long long j = i + 1; j < n; j++) {
        if ((j - i) % 2 == 0) {
          cur += v[j];
          continue;
        }
        long long p1, p2;
        p1 = max(-diff, 1ll);
        p2 = v[i];
        if (p1 > p2) break;
        long long aa = p1 + cur, bb = p2 + cur;
        if (max(1ll, aa) <= min(v[j], bb)) {
          count += min(v[j], bb) - max(1ll, aa) + 1;
        }
        cur -= v[j];
        diff = min(diff, cur);
      }
    }
    cout << count << "\n";
  }
}
