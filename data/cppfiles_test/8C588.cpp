#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    int k = a / 3;
    cout << k + (a % 3 == 1) << " " << k + (a % 3 == 2) << endl;
  }
}
