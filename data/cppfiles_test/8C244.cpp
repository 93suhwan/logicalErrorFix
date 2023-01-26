#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    double n, a, b;
    cin >> n;
    a = ceil(n / 3);
    b = n - a;
    if ((int)b % 2 == 1) {
      b++;
      a--;
    }
    cout << (int)a << " " << (int)b / 2 << endl;
  }
}
