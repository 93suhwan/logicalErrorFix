#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  while (tc-- > 0) {
    long long int n;
    cin >> n;
    if (n % 2 == 0) {
      long long int a = 2;
      long long int b = n / 2;
      cout << a << " " << b << "\n";
    } else {
      cout << 2 << " " << n - 1 << "\n";
    }
  }
  return 0;
}
