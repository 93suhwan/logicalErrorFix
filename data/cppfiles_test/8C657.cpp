#include <bits/stdc++.h>
using namespace std;
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(NULL));
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n;
    long long ans = n / 3;
    long long p = ans, q = ans;
    if (n % 3 == 1)
      p++;
    else if (n % 3 == 2)
      q++;
    cout << p << " " << q << endl;
  }
}
