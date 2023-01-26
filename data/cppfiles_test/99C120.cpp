#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solution() {
  long long int x, n;
  cin >> x >> n;
  if (x % 2 == 0) {
    if (n % 4 == 0) {
      cout << x << endl;
    }
    if (n % 4 == 1) {
      cout << x - n << endl;
    }
    if (n % 4 == 2) {
      cout << x + 1 << endl;
    }
    if (n % 4 == 3) {
      cout << x + 1 + n << endl;
    }
  } else {
    if (n % 4 == 0) {
      cout << x << endl;
    }
    if (n % 4 == 1) {
      cout << x + n << endl;
    }
    if (n % 4 == 2) {
      cout << x - 1 << endl;
    }
    if (n % 4 == 3) {
      cout << x - 1 - n << endl;
    }
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test = 1;
  cin >> test;
  while (test--) {
    solution();
  }
  return 0;
}
