/**
 *  In The Name Of GOD
 *  author : Behrad
 *  Lets Be Nutella :D
**/
#include "bits/stdc++.h"

#define sz(x) ((int) (x).size())

using namespace std;

void doo() {
  int n;
  cin >> n;
  //lanat be in soalaton
  if (n % 2 == 0) {
    cout << 2 << " " << n - 3 << " " << 1 << '\n';
    return;
  }

  if (__gcd(3, n - 4) == 1) {
    cout << 3 << " " << n - 4 << " " << 1 << '\n';
    return;
  }

  if (__gcd(5, n - 6) == 1) {
    cout << 5 << " " << n - 6 << " " << 1 << '\n';
    return;
  }

  if (__gcd(7, n - 8) == 1) {
    cout << 7 << " " << n - 8 << " " << 1 << '\n';
    return;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    doo();
  }
  return 0;
}


