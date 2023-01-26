#include <bits/stdc++.h>
using namespace std;
long long int ans = 0;
void f(long long int n) {
  if (n % 6 == 0) {
    ans += (n * 5) / 2;
    return;
  }
  if (n % 8 == 0) {
    ans += (n * 5) / 2;
    return;
  }
  if (n % 10 == 0) {
    ans += (n * 5) / 2;
    return;
  }
  if (n <= 6) {
    ans += 15;
    return;
  }
  if (n <= 8) {
    ans += 20;
    return;
  }
  if (n <= 10) {
    ans += 25;
    return;
  }
  ans += (n / 10) * 25;
  f(n % 10);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int test = 1;
  cin >> test;
  while (test--) {
    long long int n;
    cin >> n;
    ans = 0;
    f(n);
    cout << ans;
    cout << "\n";
  }
  return 0;
}
