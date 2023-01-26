#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "no-stack-protector", "unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
using namespace std;
struct st {
  long long A, B, C;
};
bool ok(st arr, long long N) {
  for (long long i = 0; i <= arr.A; i++) {
    for (long long j = 0; j <= arr.B; j++) {
      if (i * 1 + j * 2 <= N && (N - (i * 1 + j * 2)) % 3 == 0 &&
          (N - (i * 1 + j * 2)) / 3 <= arr.C) {
        return true;
      }
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<st> arr;
  for (long long i = 0; i <= 6; i++) {
    for (long long j = 0; j <= 6; j++) {
      for (long long k = 0; k <= 6; k++) {
        if (i + j + k <= 6) arr.push_back({i, j, k});
      }
    }
  }
  long long T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    vector<long long> vect;
    long long tot = 0;
    for (long long i = 0; i < N; i++) {
      long long n;
      cin >> n;
      vect.push_back(n);
      tot = max(tot, n / 3);
    }
    tot = max(0ll, tot - 4);
    long long res = 1e18;
    for (auto x : arr) {
      x.C += tot;
      long long cont = 0;
      for (long long i = 0; i < N; i++) {
        if (ok(x, vect[i])) cont++;
      }
      if (cont == N) {
        res = min(res, x.A + x.B + x.C);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
