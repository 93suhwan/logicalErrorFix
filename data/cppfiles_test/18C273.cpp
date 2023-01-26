#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long MOD1 = 998244353;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, a, b;
    cin >> n >> k;
    set<long long> S;
    set<pair<long long, long long>> S1;
    long long A[2 * n + 1];
    for (long long i = 1; i < 2 * n + 1; i++) {
      S.insert(i);
      A[i] = -1;
    }
    for (long long i = 0; i < k; i++) {
      cin >> a >> b;
      S1.insert({min(a, b), max(a, b)});
      S.erase(a);
      S.erase(b);
      A[a] = b;
      A[b] = a;
    }
    for (long long v : S) {
      if (A[v] == -1) {
        long long c = 0;
        for (long long i = 1; i < 2 * n; i++) {
          if (A[(v + i) % (2 * n + 1)] == -1) {
            c++;
          }
          if (c == (n - k)) {
            A[v] = (v + i) % (2 * n + 1);
            A[(v + i) % (2 * n + 1)] = v;
            S1.insert(
                {min(v, (v + i) % (2 * n + 1)), max(v, (v + i) % (2 * n + 1))});
            k++;
            break;
          }
        }
      }
    }
    long long sum = 0;
    for (auto v : S1) {
      for (long long i = v.first + 1; i <= v.second - 1; i++) {
        if (A[i] > v.second) {
          sum++;
        }
      }
    }
    cout << sum << "\n";
  }
}
