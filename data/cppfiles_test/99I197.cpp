#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  for (long long i = 0; i < t; i++) {
    long long x, n;
    std::cin >> x;
    std::cin >> n;
    long long movs = n % 4;
    long long base = n - movs;
    if (movs == 3) {
      if (x % 2 == 0) {
        x += base;
      } else {
        x -= base;
      }
      movs--;
      base++;
    }
    if (movs == 2) {
      if (x % 2 == 0) {
        x += base;
      } else {
        x -= base;
      }
      movs--;
      base++;
    }
    if (movs == 1) {
      if (x % 2 == 0) {
        x += base;
      } else {
        x -= base;
      }
      movs--;
      base++;
    }
    if (movs == 0) {
      if (x % 2 == 0) {
        x += base;
      } else {
        x -= base;
      }
    }
    std::cout << x << '\n';
  }
  return 0;
}
