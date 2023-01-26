#include <bits/stdc++.h>
using namespace std;
float A;
float P;
float fonc(float k) {
  return (k * (k - 1) * (A - k) + (k * (k - 1) * (k - 2)) / 3 +
          (k * (A - k) * (A - k - 1)) / 2) /
         ((A * (A - 1) * (A - 2)) / 3);
}
int main() {
  cin >> A >> P;
  for (float i = 0; i <= A; i++) {
    if (fonc(i) >= P) {
      cout << i;
      return 0;
    }
  }
}
