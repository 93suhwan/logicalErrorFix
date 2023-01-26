#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int t = n / 2;
    if (n % 2 == 0)
      n = n / 2;
    else
      n = n / 2 + 1;
    if (t % 2 == 0)
      cout << n << " " << t / 2 << endl;
    else
      cout << n - 1 << " " << t / 2 + 1 << endl;
  }
  return 0;
}
