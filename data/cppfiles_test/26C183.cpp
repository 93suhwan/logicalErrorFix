#include <bits/stdc++.h>
using namespace std;
unsigned long long factorial(int n) {
  const unsigned int M = 1000000007;
  unsigned long long f = 1;
  for (int i = 3; i <= n; i++) f = (f * i) % M;
  return f;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    long n;
    cin >> n;
    cout << factorial(n * 2) << endl;
  }
}
