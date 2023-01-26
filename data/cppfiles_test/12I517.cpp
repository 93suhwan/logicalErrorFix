#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, ver, nra, nrb;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (; t--;) {
    cin >> n >> m >> k;
    ver = (n * m) / 2 - k;
    if (n % 2 == 0 && m % 2 == 0) {
      cout << "YES" << '\n';
    } else if (n % 2 == 1) {
      nra = n / 2 + 1;
      nra = nra * m;
      nrb = n / 2;
      nrb = nrb * m;
      nra = nra - ver;
      nrb = nrb - ver;
      if (nra >= 0 && nrb >= 0 && nra % 2 == 0 && nrb % 2 == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      nra = n / 2;
      nra = nra * m;
      nrb = n / 2;
      nrb = nrb * m;
      nra = nra - ver;
      nrb = nrb - ver;
      if (nra >= 0 && nrb >= 0 && nra % 2 == 0 && nrb % 2 == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
