#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, i;
    cin >> n;
    i = n / 10;
    if (n % 10 == 9) i++;
    cout << i << endl;
  }
  return 0;
}
