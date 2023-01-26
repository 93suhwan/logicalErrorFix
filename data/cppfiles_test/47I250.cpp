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
    for (long long i = k; i < a.size(); i += k) {
      v += 2 * a[i];
    }
    for (long long i = k; i < b.size(); i += k) {
      v += 2 * b[i];
    }
    long long g;
    if (b.size() == 0) {
      v += a[0];
      g = v;
    } else if (a.size() == 0) {
      v += b[0];
      g = v;
    } else {
      g = v + (2 * b[0]) + a[0];
      v += (2 * a[0]) + b[0];
    }
    cout << min(v, g) << endl;
    a.clear();
    b.clear();
  }
}
