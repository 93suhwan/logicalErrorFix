#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
long long ask(long long i, long long j) {
  cout << "? " << i << " " << j << endl;
  long long n;
  cin >> n;
  return n;
}
signed main() {
  long long lo = 1;
  long long hi = N;
  long long left = ask(1, lo);
  long long right = ask(1, hi);
  long long mnx = 0;
  while (hi - lo > 1) {
    long long m = (lo + hi) / 2;
    long long mid = ask(1, m);
    if (left == mid && right == mid) {
      mnx = mid;
      break;
    } else if (left > right) {
      lo = m;
      left = mid;
    } else {
      hi = m;
      right = mid;
    }
  }
  if (!mnx) mnx = min(left, right);
  mnx++;
  long long mny = ask(1, 1) - (mnx - 1) + 1;
  long long mxy = N - (ask(1, N) - (mnx - 1));
  long long mxx = N - (ask(N, 1) - (mny - 1));
  cout << "! " << mnx << " " << mny << " " << mxx << " " << mxy << endl;
}
