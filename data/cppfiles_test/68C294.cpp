#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << "\n";
    return;
  }
  long long i = 0;
  for (; i * i < n; i++)
    ;
  --i;
  n -= i * i;
  if (n < 1 + i)
    cout << n << " " << i + 1 << "\n";
  else
    cout << i + 1 << " " << i + 2 - (n - i) << "\n";
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
