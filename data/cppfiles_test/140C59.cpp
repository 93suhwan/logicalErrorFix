#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int num;
  cin >> num;
  int r2 = (int)sqrt(num);
  int r3 = (int)cbrt(num);
  int count = r2 + r3 - (int)cbrt(sqrt(num));
  cout << count << endl;
}
int main() {
  int n = 0;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
