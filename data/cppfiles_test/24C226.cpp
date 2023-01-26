#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = floor(n / 10);
    if (n % 10 == 9) x++;
    cout << x << endl;
  }
}
