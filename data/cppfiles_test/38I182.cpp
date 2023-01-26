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
void f1(long long int n) {
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
  ans += (n / 8) * 20;
  f(n % 8);
}
void f3(long long int n) {
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
  ans += (n / 6) * 15;
  f(n % 6);
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
    long long int x = ans;
    ans = 0;
    f1(n);
    x = min(ans, x);
    ans = 0;
    f3(n);
    x = min(ans, x);
    cout << x;
    cout << "\n";
  }
  return 0;
}
