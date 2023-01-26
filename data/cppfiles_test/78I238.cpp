#include <bits/stdc++.h>
using namespace std;
void Pagla() {
  int i, j;
  long long int a, b;
  cin >> a >> b;
  if (b - a == 1) {
    cout << 1 << "\n";
    return;
  }
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  long long int mk = b / 2;
  mk++;
  if (a <= mk) {
    cout << b % mk << "\n";
  } else {
    cout << b % a << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    Pagla();
  }
  return 0;
}
