#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int r, t;
  cin >> r;
  while (r--) {
    long long int q, n, c = INT_MAX, d = 0, i, j = 0, p = 0;
    string s;
    cin >> n >> d;
    c = d / 2;
    q = c + 1;
    if (q > n) {
      j = d % q;
      cout << j << endl;
    } else {
      j = d % n;
      cout << j << endl;
    }
  }
  return 0;
}
