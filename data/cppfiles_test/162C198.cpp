#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int n;
long long h[200005];
long long hm[200005];
bool works(long long x) {
  long long d;
  long long req;
  for (int i = n - 1; i >= 2; i--) {
    d = max(0ll, (hm[i] - x) / 3);
    d = min(d, h[i] / 3);
    hm[i] -= 3 * d;
    hm[i - 1] += d;
    hm[i - 2] += 2 * d;
  }
  return *min_element(hm, hm + n) >= x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    long long bmin = 0;
    long long bmax = INT_MAX;
    while (bmin < bmax) {
      copy(h, h + n, hm);
      long long bmid = (bmin + bmax + 1) / 2;
      if (works(bmid)) {
        bmin = bmid;
      } else {
        bmax = bmid - 1;
      }
    }
    cout << bmax << "\n";
  }
}
