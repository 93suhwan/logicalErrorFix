#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000009 + 7;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (a * res) % m;
    }
    b = b / 2;
    a = (a * a) % m;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
