#include <bits/stdc++.h>
using namespace std;
void swagWaalaFunction() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    if (n % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n % 2 == 0 and m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n % 2 == 0 and m % 2) {
    long long int x = (n * m / 2 - k);
    if (x >= n / 2 and (x - n / 2) % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (n % 2 and m % 2 == 0) {
    if (k >= m / 2 and (k - m / 2) % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc = 1;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    swagWaalaFunction();
  }
  return 0;
}
