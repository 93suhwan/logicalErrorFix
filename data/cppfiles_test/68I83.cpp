#include <bits/stdc++.h>
using namespace std;
void logic() {
  long long n;
  cin >> n;
  int x = ceil((double)sqrt(n));
  if (n == 2) {
    cout << "1 2\n";
    return;
  }
  if (x * x - n <= x) {
    cout << x << " " << x * x - n + 1 << "\n";
  } else if (x * x - n == 0) {
    cout << "1 " << n << "\n";
    return;
  } else if (n + 1 - (x - 1) * (x - 1) <= x) {
    cout << n - (x - 1) * (x - 1) << " " << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    logic();
  }
}
