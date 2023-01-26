#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int n;
long long h[200005];
long long hm[200005];
long long canGive[200005];
bool works(long long x) {
  copy(h, h + n, hm);
  long long d;
  long long req;
  for (int i = n - 1; i >= 0; i--) {
    d = max(0ll, (hm[i] - x) / 3);
    d = min(d, h[i] / 3);
    canGive[i] = d;
    hm[i] -= 3 * d;
    if (i - 1 >= 0) {
      hm[i - 1] += d;
    }
    if (i - 2 >= 0) {
      hm[i - 2] += 2 * d;
    }
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
      hm[i] = h[i];
    }
    long long bmin = 1;
    long long bmax = h[n - 1];
    while (bmin < bmax) {
      long long bmid = (bmin + bmax + 1) / 2;
      if (works(bmid)) {
        bmin = bmid;
      } else {
        bmax = bmid - 1;
      }
    }
    cout << bmin << "\n";
  }
}
