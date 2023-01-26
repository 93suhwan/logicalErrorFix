#include <bits/stdc++.h>
using namespace std;
int sum(int n);
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 10 == 9) {
      cout << ((n - 9) / 10) + 1 << endl;
    } else
      cout << (n / 10) << endl;
  }
}
