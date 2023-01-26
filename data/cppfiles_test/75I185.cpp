#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
vector<long long> l, r;
bool winner(bool cur, long long i, long long j) {
  if (a[i] <= a[j] && r[j - 1] % 2 == 1) {
    return cur;
  } else if (a[i] >= a[j] && l[i + 1] % 2 == 1) {
    return cur;
  } else {
    return winner(!cur, i + (a[i] < a[j]), j + (a[i] >= a[j]));
  }
}
int32_t main() {
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  l.resize(n);
  r.resize(n);
  long long lc = 0, prev = LONG_LONG_MAX / 2;
  for (long long i = 0; i < n; i++) {
    if (prev > a[i]) {
      lc++;
    } else {
      lc = 1;
    }
    r[i] = lc;
    prev = a[i];
  }
  lc = 0;
  prev = LONG_LONG_MAX / 2;
  for (long long i = n - 1; i >= 0; i--) {
    if (prev > a[i]) {
      lc++;
    } else {
      lc = 1;
    }
    l[i] = lc;
    prev = a[i];
  }
  if (winner(0, 0, n - 1))
    cout << "Alice";
  else
    cout << "Bob";
}
