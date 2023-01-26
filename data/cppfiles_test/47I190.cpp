#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> b;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, x = 0;
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      if (x < 0) {
        b.push_back(abs(x));
      }
      if (x > 0) {
        a.push_back(x);
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    long long v = 0;
    long long d = a.size() - k, f = b.size() - k;
    for (long long i = d; i >= 0 && a.size() > k; i -= k) {
      if (i < k) i = k;
      v += 2 * a[i];
      if (i == k) break;
    }
    for (long long i = f; i >= 0 && b.size() > k; i -= k) {
      if (i < k) i = k;
      v += 2 * b[i];
      if (i == k) break;
    }
    long long g;
    d = f = 0;
    if (b.size() == 0) {
      v += a[d];
      g = v;
    } else if (a.size() == 0) {
      v += b[f];
      g = v;
    } else {
      g = v + (2 * b[f]) + a[d];
      v += (2 * a[d]) + b[f];
    }
    cout << min(v, g) << endl;
    a.clear();
    b.clear();
  }
}
