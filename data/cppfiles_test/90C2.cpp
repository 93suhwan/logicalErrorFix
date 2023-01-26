#include <bits/stdc++.h>
using namespace std;
bool F(long long a, long long b) {
  long long c = (a + b) / 2;
  return (c % a) == (b % c);
}
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
  cout << b - (((a + b) / 2) % a) << "\n";
}
int main() {
  long long CT = 1;
  cin >> CT;
  while (CT--) SMF();
  return 0;
}
