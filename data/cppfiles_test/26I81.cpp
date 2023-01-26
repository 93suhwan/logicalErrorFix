#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
long long int factorial(long long int n) {
  if (n == 1) return 1;
  return (n * (factorial(n - 1) % m));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << "fact: " << factorial((n * 2)) << endl;
    long long int res = (factorial((n * 2)) / 2) % m;
    cout << res << endl;
  }
  return 0;
}
