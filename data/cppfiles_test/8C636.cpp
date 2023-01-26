#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else if (n % 3 == 1)
      cout << (n / 3 + 1) << " " << n / 3 << endl;
    else
      cout << (n / 3) << " " << (n / 3 + 1) << endl;
  }
  return 0;
}
