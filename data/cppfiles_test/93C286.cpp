#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b = b / 2;
  }
  return ans;
}
void solved() {
  long long int n, m;
  cin >> n >> m;
  long long int b = m - 1, c = 0;
  while (b > 0) b /= 2, c++;
  n = n - power(2, c);
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
