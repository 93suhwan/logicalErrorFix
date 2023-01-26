#include <bits/stdc++.h>
using namespace std;
int cnt(int n) {
  return (int)sqrt(n) + (int)cbrt(n) - (int)pow(n, (double)1 / 6);
}
int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n;
    cin >> n;
    cout << cnt(n) << "\n";
  }
}
