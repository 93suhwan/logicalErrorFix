#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
using namespace std;
int t;
long double n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long num1 = ceil(n / 3.0);
    long long num2 = floor(n / 3.0);
    if (num1 + 2 * num2 == n) {
      cout << num1 << " " << num2 << endl;
    } else if (n - num1 + 2 * num2 == 0) {
      cout << num1 << " " << num2 << endl;
    } else {
      cout << num2 << " " << num1 << endl;
    }
  }
}
