#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x;
    long long k = a - 1;
    if (k % 4 == 0)
      x = k;
    else if (k % 4 == 1)
      x = 1;
    else if (k % 4 == 2)
      x = k + 1;
    else
      x = 0;
    if (x == b)
      cout << a << endl;
    else if ((x ^ a) == b)
      cout << a + 2 << endl;
    else
      cout << a + 1 << endl;
  }
  return 0;
}
