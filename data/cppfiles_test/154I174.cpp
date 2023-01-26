#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
bool compare(int &a, int &b) { return ((a % 2) < (b % 2)); }
bool squarenum(int x) {
  int a = sqrt(x);
  return (a * a == x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    if ((v[0] + v[1] + v[2]) % 2 == 1) {
      cout << "NO" << endl;
    } else if (v[2] - v[0] == v[1]) {
      cout << "YES" << endl;
    } else if (v[1] == v[2] && v[0] % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
