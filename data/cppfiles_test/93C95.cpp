#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238;
const int M = 1e9 + 7, OO = 0x3f3f3f3f;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<long long> v1, v2;
  long long x = 0;
  v1.push_back(x);
  x++;
  v1.push_back(x);
  while (x <= 1e18) {
    x *= 2;
    v1.push_back(x);
  }
  x = 1;
  v2.push_back(x);
  while (x <= 1e18) {
    x *= 2;
    v2.push_back(x);
  }
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    int pt1, pt2;
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] > k) {
        pt1 = i - 1;
        break;
      }
    }
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i] >= n) {
        pt2 = i;
        break;
      }
    }
    if (pt1 >= pt2)
      cout << pt2 << '\n';
    else {
      long long sum = pt1;
      n -= v2[pt1];
      sum += n / k;
      if (n % k) sum++;
      cout << sum << '\n';
    }
  }
  return 0;
}
