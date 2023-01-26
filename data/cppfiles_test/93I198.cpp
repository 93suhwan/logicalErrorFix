#include <bits/stdc++.h>
using namespace std;
void solved() {
  long long int n, m;
  cin >> n >> m;
  long long int b = m - 1, c = 0;
  while (b > 0) b /= 2, c++;
  n = n - pow(2, c);
  n = max(n, 0ll);
  c = c + n / m;
  if (n % m) c++;
  cout << c << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) solved();
  return 0;
}
