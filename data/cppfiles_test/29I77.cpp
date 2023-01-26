#include <bits/stdc++.h>
using namespace std;
void solve_A() {
  long long a, b, c;
  cin >> a >> b >> c;
  (a + b + c) % 2 ? cout << "0\n" : cout << "1\n";
}
void solve_B() {
  long long n, am1 = 0, am2 = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    am1 += (a[i] == 1);
    am2 += (a[i] == 0);
  }
  cout << am1 * pow(2LL, am2) << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve_B();
}
