#include <bits/stdc++.h>
using namespace std;
void s() {
  float A, B;
  cin >> A >> B;
  if (A == 0 && B == 0) {
    cout << 0 << "\n";
    return;
  }
  if (A == B) {
    cout << 1;
  } else {
    float temp = abs(A + B) / 2;
    if (temp == (long long)temp) {
      cout << 2;
    } else if ((long long)(A - B) % 2 == 1) {
      cout << -1;
    } else {
      cout << -1;
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests;
  cin >> tests;
  while (tests--) {
    s();
  }
}
