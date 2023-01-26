#include <bits/stdc++.h>
using namespace std;
void SMF() {
  long long a, b;
  cin >> a >> b;
  if (a > b) {
    cout << a + b << "\n";
    return;
  }
  if (a == b) {
    cout << a << "\n";
    return;
  }
  if (!(b % a)) {
    cout << a << "\n";
    return;
  }
}
int main() {
  long long CT = 1;
  cin >> CT;
  while (CT--) SMF();
  return 0;
}
