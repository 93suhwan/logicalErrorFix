#include <bits/stdc++.h>
using namespace std;
long long max2(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long max4(long long a, long long b, long long c, long long d) {
  return max2(max2(a, b), max2(d, c));
}
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long w, h;
    cin >> w >> h;
    vector<long long> a(4, 0);
    for (int j = 0; j < 4; j++) {
      long long n;
      cin >> n;
      long long x1, x2;
      cin >> x1;
      for (int k = 1; k < n; k++) {
        cin >> x2;
      }
      a[j] = x2 - x1;
    }
    a[0] *= h;
    a[1] *= h;
    a[2] *= w;
    a[3] *= w;
    cout << max4(a[0], a[1], a[2], a[3]) << endl;
  }
  return 0;
}
