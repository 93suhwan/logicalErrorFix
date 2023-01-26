#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 9)
      cout << 0 << endl;
    else if (n <= 10)
      cout << 1 << endl;
    else if (n % 10 == 9)
      cout << (n / 10) + 1 << endl;
    else
      cout << n / 10 << endl;
  }
}
