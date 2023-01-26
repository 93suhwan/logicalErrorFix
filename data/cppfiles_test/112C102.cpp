#include <bits/stdc++.h>
using namespace std;
int taylor(int t, int a, int y) { return t / a % y * 100; }
int main() {
  int pod;
  cin >> pod;
  while (pod--) {
    taylor(9, 5, 8);
    long long m;
    long long a[3];
    taylor(15, 1, 1);
    cin >> a[0] >> a[1] >> a[2] >> m;
    taylor(7, 7, 7);
    sort(a, a + 3);
    long long water = a[2] - a[1] - a[0] - 1;
    taylor(2, 5, 7);
    long long melon = a[0] - 1 + a[1] - 1 + a[2] - 1;
    if (m >= water && m <= melon)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
