#include <bits/stdc++.h>
using namespace std;
int n;
double p;
int main() {
  cin >> n >> p;
  long long fm = n * (n - 1) * (n - 2) / 6;
  p *= 10000;
  for (int x = 0; x <= n; x++) {
    long long fz = x * (n - x) * (n - x - 1) / 2 + x * (x - 1) * (n - x) +
                   x * (x - 1) * (x - 2) / 3;
    if (fz * 5000 >= fm * p) {
      cout << x << endl;
      break;
    }
  }
  return 0;
}
