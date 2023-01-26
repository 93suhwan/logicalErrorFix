#include <bits/stdc++.h>
using namespace std;
void func(long long n) {
  int c2 = n / 3;
  if (n % 3 == 2) {
    c2 += 1;
  }
  int c1 = n - (2 * c2);
  cout << c1 << " " << c2 << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  long long n;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    func(n);
  }
  return 0;
}
