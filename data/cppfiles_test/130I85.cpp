#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
long long ask(long long a, long long b, long long c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl;
  long long p;
  cin >> p;
  return p;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long last = ask(1, 2, 3), bad = 0, good = 0, l = 2, r = -1;
    for (long long i = 2; i <= n; i++) {
      long long a = i, b = i + 1, c = i + 2;
      if (b > n) b -= n;
      if (c > n) c -= n;
      long long val = ask(a, b, c);
      if (val != last) {
        if (last == 0) {
          bad = i - 1, good = c;
        } else {
          good = i - 1, bad = c;
        }
        break;
      }
      r = i - 1;
    }
    long long val = -1;
    for (long long j = l; j <= r; j++) {
      if (j == bad || j == good) continue;
      val = ask(j, bad, good);
      break;
    }
    vector<long long> arr{bad};
    if (val == 0) {
      for (long long j = l; j <= r; j++) {
        arr.emplace_back(j);
      }
    }
    for (long long i = 1; i <= n; i++) {
      if (bad == i || good == i || (l <= i && i <= r)) continue;
      if (ask(bad, good, i) == 0) {
        arr.emplace_back(i);
      }
    }
    cout << "! " << arr.size() << ' ';
    for (auto to : arr) {
      cout << to << ' ';
    }
    cout << endl;
  }
  return 0;
}
