#include <bits/stdc++.h>
using namespace std;
bool iSp(int x) {
  long long i;
  for (i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return true;
      exit;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, t, i, r, x, j, ans, s, p, pp, q;
  cin >> t;
  while (t--) {
    string a;
    cin >> n >> a;
    s = 1;
    q = 0;
    r = 0;
    vector<long long> v;
    map<long long, long long> A;
    for (i = 0; i < n; i++) {
      A[a[i] - 48]++;
    }
    if (a == "1") {
      cout << 1 << " " << 1 << endl;
      continue;
    }
    for (i = 3; i <= 99; i++) {
      if (i % 11 == 0) {
        if (iSp(i) == true && A[i / 11] > 1) {
          r = i;
          break;
        } else
          continue;
      }
      if (i < 10) {
        if (iSp(i) == true && A[i % 10] != 0) {
          r = i;
          break;
        } else
          continue;
      }
      if (iSp(i) == true && A[i / 10] != 0 && A[i % 10] != 0) {
        r = i;
        break;
      }
    }
    if (r < 10)
      cout << 1 << endl;
    else
      cout << 2 << endl;
    cout << r << endl;
  }
}
