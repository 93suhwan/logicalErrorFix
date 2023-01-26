#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int test;
  cin >> test;
  while (test--) {
    long long x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 0)
        cout << x << "\n";
      else if (n % 4 == 1)
        cout << x - n << "\n";
      else if (n % 4 == 2)
        cout << x + 1 << "\n";
      else if (n % 4 == 3)
        cout << x + (n + 1) << "\n";
    } else if (x % 2 == 1 || x % 2 == -1) {
      if (n % 4 == 0)
        cout << x << "\n";
      else if (n % 4 == 1)
        cout << x + n << "\n";
      else if (n % 4 == 2)
        cout << x - 1 << "\n";
      else if (n % 4 == 3)
        cout << x - (n + 1) << "\n";
    }
  }
  return 0;
}
