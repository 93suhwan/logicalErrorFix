#include <bits/stdc++.h>
using namespace std;
double log_base2(double d) { return log2(d); }
double log_base2(double d);
double findl(int k) { return log_base2(k); }
double findl(int k);
long long int find(int num, int kay) {
  long long int x;
  double y;
  int z;
  y = floor((findl(kay)));
  if (kay == 1) {
    x = 1;
  } else if (y == (findl(kay))) {
    x = pow(num, y);
    if (x > 1000000007) {
      x = x % 1000000007;
    }
  } else {
    z = pow(2, y);
    long long int b;
    b = pow(num, y);
    if (b > 1000000007) {
      b = b % 1000000007;
    }
    long long int d;
    d = find(num, kay - z);
    if (d > 1000000007) {
      d = d % 1000000007;
    }
    x = b + d;
    if (x > 1000000007) {
      x = x % 1000000007;
    }
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    long long int ans;
    ans = find(n, k);
    cout << ans << endl;
  }
}
