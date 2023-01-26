#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long N = 1e5;
long long infi = 1e12;
void init_code() {}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long rem = n % 3;
    long long one = n / 3;
    long long two = n / 3;
    if (rem == 1)
      one++;
    else if (rem == 2)
      two++;
    cout << one << " " << two << "\n";
  }
}
