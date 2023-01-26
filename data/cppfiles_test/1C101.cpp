#include <bits/stdc++.h>
using namespace std;
long long cnt[4][4];
long long getPar(long long i1, long long j1, long long i2, long long j2) {
  if (i1 == i2 && j1 == j2) {
    return 0;
  }
  return 2;
}
void getVal(long long &i, long long &j, char c) {
  if (c == '0') {
    i = 0, j = 0;
  }
  if (c == '1') {
    i = 0, j = 2;
  }
  if (c == '2') {
    i = 2, j = 0;
  }
  if (c == '3') {
    i = 2, j = 2;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    cnt[x % 4][y % 4]++;
  }
  set<string> ops;
  for (long long i1 = 0; i1 < 4; i1 += 2) {
    for (long long j1 = 0; j1 < 4; j1 += 2) {
      for (long long i2 = 0; i2 < 4; i2 += 2) {
        for (long long j2 = 0; j2 < 4; j2 += 2) {
          for (long long i3 = 0; i3 < 4; i3 += 2) {
            for (long long j3 = 0; j3 < 4; j3 += 2) {
              string s = to_string(i1 + j1 / 2) + to_string(i2 + j2 / 2) +
                         to_string(i3 + j3 / 2);
              sort(s.begin(), s.end());
              if (ops.find(s) != ops.end()) continue;
              long long b = getPar(i1, j1, i2, j2) + getPar(i2, j2, i3, j3) +
                            getPar(i3, j3, i1, j1);
              b %= 4;
              if (b == 0) {
                ops.insert(s);
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (auto op : ops) {
    long long i[3], j[3];
    for (long long k = 0; k < 3; k++) {
      getVal(i[k], j[k], op[k]);
    }
    long long temp = 1;
    for (long long k = 0; k < 3; k++) {
      temp *= cnt[i[k]][j[k]]--;
      if (k == 1 && op[k] == op[k - 1]) {
        temp /= 2;
      }
      if (k == 2) {
        if (op[k] == op[k - 2])
          temp /= 3;
        else if (op[k] == op[k - 1]) {
          temp /= 2;
        }
      }
    }
    ans += temp;
    for (long long k = 0; k < 3; k++) {
      cnt[i[k]][j[k]]++;
    }
  }
  cout << ans << '\n';
}
