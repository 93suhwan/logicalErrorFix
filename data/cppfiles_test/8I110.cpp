#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int oneB = ceil(n / 3.0);
    if (n % 3 == 0)
      cout << oneB << " " << oneB << endl;
    else
      cout << oneB << " " << oneB - 1 << endl;
  }
  return 0;
}
