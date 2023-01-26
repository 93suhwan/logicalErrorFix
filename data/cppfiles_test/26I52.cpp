#include <bits/stdc++.h>
using namespace std;
int fact(long long int n) {
  int a = 1;
  for (int i = 3; i <= 2 * n; i++) {
    a = (a * i) % 1000000007;
  }
  return a;
}
void test() {
  long long int n;
  cin >> n;
  cout << fact(n) << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    test();
  }
  return 0;
}
