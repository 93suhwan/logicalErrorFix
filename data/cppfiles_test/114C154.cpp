#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long n;
    cin >> n;
    vector<long long> c(n + 1);
    vector<vector<long long>> a(n + 1);
    for (long long i = 1; i <= n; ++i) {
      cin >> c[i];
      a[i].resize(c[i] + 1);
      for (long long j = 1; j <= c[i]; ++j) cin >> a[i][j];
    }
    long long m;
    cin >> m;
    set<vector<long long>> s;
    for (long long i = 0; i < (m); ++i) {
      vector<long long> b(n + 1);
      for (long long j = 1; j <= n; ++j) cin >> b[j];
      s.insert(b);
    }
    auto check = [&](long long x) {
      vector<long long> idx = c;
      vector<long long> rem(n);
      for (idx[1] = c[1]; a[1][c[1]] - a[1][idx[1]] <= x and idx[1] > 0;
           idx[1]--) {
        rem[0] = x - (a[1][c[1]] - a[1][idx[1]]);
        if (n > 1) {
          for (idx[2] = c[2];
               a[2][c[2]] - a[2][idx[2]] <= rem[0] and idx[2] > 0; idx[2]--) {
            rem[1] = rem[0] - (a[2][c[2]] - a[2][idx[2]]);
            if (n > 2) {
              for (idx[3] = c[3];
                   a[3][c[3]] - a[3][idx[3]] <= rem[1] and idx[3] > 0;
                   idx[3]--) {
                rem[2] = rem[1] - (a[3][c[3]] - a[3][idx[3]]);
                ;
                if (n > 3) {
                  for (idx[4] = c[4];
                       a[4][c[4]] - a[4][idx[4]] <= rem[2] and idx[4] > 0;
                       idx[4]--) {
                    rem[3] = rem[2] - (a[4][c[4]] - a[4][idx[4]]);
                    if (n > 4) {
                      for (idx[5] = c[5];
                           a[5][c[5]] - a[5][idx[5]] <= rem[3] and idx[5] > 0;
                           idx[5]--) {
                        rem[4] = rem[3] - (a[5][c[5]] - a[5][idx[5]]);
                        if (n > 5) {
                          for (idx[6] = c[6];
                               a[6][c[6]] - a[6][idx[6]] <= rem[4] and
                               idx[6] > 0;
                               idx[6]--) {
                            rem[5] = rem[4] - (a[6][c[6]] - a[6][idx[6]]);
                            if (n > 6) {
                              for (idx[7] = c[7];
                                   a[7][c[7]] - a[7][idx[7]] <= rem[5] and
                                   idx[7] > 0;
                                   idx[7]--) {
                                rem[6] = rem[5] - (a[7][c[7]] - a[7][idx[7]]);
                                if (n > 7) {
                                  for (idx[8] = c[8];
                                       a[8][c[8]] - a[8][idx[8]] <= rem[6] and
                                       idx[8] > 0;
                                       idx[8]--) {
                                    rem[7] =
                                        rem[6] - (a[8][c[8]] - a[8][idx[8]]);
                                    if (n > 8) {
                                      for (idx[9] = c[9];
                                           a[9][c[9]] - a[9][idx[9]] <=
                                               rem[7] and
                                           idx[9] > 0;
                                           idx[9]--) {
                                        rem[8] = rem[7] -
                                                 (a[9][c[9]] - a[9][idx[9]]);
                                        if (n > 9) {
                                          for (idx[10] = c[10];
                                               a[10][c[10]] - a[10][idx[10]] <=
                                                   rem[8] and
                                               idx[10] > 0;
                                               idx[10]--) {
                                            rem[9] = rem[8] - (a[10][c[10]] -
                                                               a[10][idx[10]]);
                                            if (n > 10) {
                                              ;
                                            } else if (!s.count(idx))
                                              return idx;
                                          }
                                        } else if (!s.count(idx))
                                          return idx;
                                      }
                                    } else if (!s.count(idx))
                                      return idx;
                                  }
                                } else if (!s.count(idx))
                                  return idx;
                              }
                            } else if (!s.count(idx))
                              return idx;
                          }
                        } else if (!s.count(idx))
                          return idx;
                      }
                    } else if (!s.count(idx))
                      return idx;
                  }
                } else if (!s.count(idx))
                  return idx;
              }
            } else if (!s.count(idx))
              return idx;
          }
        } else if (!s.count(idx))
          return idx;
      }
      return vector<long long>();
    };
    long long lo = -1;
    long long hi = 0;
    for (long long i = 1; i <= n; ++i) hi += a[i][c[i]] - a[i][1];
    while (hi - lo > 1) {
      long long mid = hi + lo >> 1;
      if ((long long)check(mid).size() == n + 1)
        hi = mid;
      else
        lo = mid;
    }
    auto res = check(hi);
    for (long long i = 1; i <= n; ++i) cout << res[i] << ' ';
  }
  return 0;
}
