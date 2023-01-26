#include <bits/stdc++.h>
using namespace std;
unsigned long long power(long long y) {
  unsigned long long x = 2;
  unsigned long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = ans * x;
    x = x * x;
    y = y >> 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], x = 0, y = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1)
        x++;
      else if (a[i] == 0)
        y++;
    }
    cout << (x * power(y)) << endl;
  }
  return 0;
}
