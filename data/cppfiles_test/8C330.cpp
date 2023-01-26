#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    int t = n % 3;
    if (t == 0)
      cout << (n / 3) << " " << (n / 3) << endl;
    else if (t == 1)
      cout << (n / 3 + t) << " " << (n / 3) << endl;
    else
      cout << (n / 3) << " " << (n / 3 + 1) << endl;
  }
}
