#include <bits/stdc++.h>
using namespace std;
int main() {
  int test, n, dx, yx;
  cin >> test;
  for (int i = 0; i < test; i++) {
    cin >> n;
    dx = n % 3;
    yx = n / 3;
    cout << yx << " " << yx + dx << endl;
  }
}
