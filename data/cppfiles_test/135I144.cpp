#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long sum = 0;
    map<long long, long long> m;
    for (long long i = 0; i < n - 2 * k; i++) sum += a[i];
    for (long long i = n - 2 * k; i < n; i++) m[a[i]]++;
    vector<long long> p;
    for (auto &i : m) p.push_back(i.second);
    sort(p.begin(), p.end(), greater<long long>());
    long long sz = p.size();
    if (sz > 1) {
      for (long long i = 0; i < sz; i++) {
        long long j = i + 1;
        while (p[i] > 0) {
          p[i]--;
          p[j]--;
          if (p[j] == 0) j++;
          if (j >= sz) break;
        }
      }
    }
    long long u = 0;
    for (long long i = 0; i < sz; i++) u += p[i];
    u /= 2;
    cout << sum + u << "\n";
  }
}
