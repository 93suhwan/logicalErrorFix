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
  } else {
    z = pow(2, y);
    x = pow(num, y) + find(num, kay - z);
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
    long long int c = pow(10, 9) + 7;
    if (ans > c) {
      ans = ans % c;
    }
    cout << ans << endl;
  }
}
