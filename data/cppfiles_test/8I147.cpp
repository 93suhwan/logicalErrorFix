#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int t = n / 2;
    n = n / 2;
    if (t % 2 == 0)
      cout << n << " " << t / 2 << endl;
    else
      cout << n - 1 << " " << t / 2 + 1 << endl;
  }
  return 0;
}
