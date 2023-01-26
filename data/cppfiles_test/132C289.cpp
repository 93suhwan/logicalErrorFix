#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, first, second, z;
int a[N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    for (int i = 1; i <= 7; i++) cin >> a[i];
    first = a[1], second = a[2];
    z = a[7] - a[1] - a[2];
    cout << first << ' ' << second << ' ' << z << endl;
  }
  return 0;
}
