#include <bits/stdc++.h>
using namespace std;
long long int asdf[2];
bool cmp(pair<pair<long long int, long long int>, long long int>& a,
         pair<pair<long long int, long long int>, long long int>& b) {
  for (int x = 0; x < 2; x++) {
    asdf[x] = x;
  }
  return a.second < b.second;
}
int main() {
  long long int t;
  cin >> t;
  for (int x = 0; x < 2; x++) {
    asdf[x] = x;
  }
  while (t--) {
    long long int n, m, src1, src2, dst1, dst2;
    for (int x = 0; x < 2; x++) {
      asdf[x] = x;
    }
    cin >> n >> m >> src1 >> src2 >> dst1 >> dst2;
    for (int x = 0; x < 2; x++) {
      asdf[x] = x;
    }
    long long int ans = 0;
    long long int l = 1, r = 1;
    for (int x = 0; x < 2; x++) {
      asdf[x] = x;
    }
    while (src1 != dst1 && src2 != dst2) {
      ans += 1;
      if (src1 + l > n || src1 + l < 1) {
        for (int x = 0; x < 2; x++) {
          asdf[x] = x;
        }
        l = -l;
      }
      if (src2 + r > m || src2 + r < 1) {
        for (int x = 0; x < 2; x++) {
          asdf[x] = x;
        }
        r = -r;
      }
      src1 += l;
      src2 += r;
    }
    for (int x = 0; x < 2; x++) {
      asdf[x] = x;
    }
    cout << ans << endl;
  }
}
