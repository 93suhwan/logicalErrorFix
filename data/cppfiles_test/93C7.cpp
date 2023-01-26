#include <bits/stdc++.h>
using namespace std;
const double EPS = (double)1e-9;
const double pi = acos(-1);
const int mod = 1000000007;
const int N = (int)1e5;
int arr[N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int test;
  cin >> test;
  for (int t = 1; t < test + 1; t++) {
    long long n, k, h = 0;
    cin >> n >> k;
    if (n == 1) {
      cout << h << "\n";
    } else if (k == 1) {
      cout << n - 1 << "\n";
    } else {
      n--;
      long long x = 1;
      while (n > 0 && x <= k) {
        n -= x;
        x *= 2;
        h++;
      }
      if (n > 0) {
        long long temp = n / k;
        if (n % k) {
          temp++;
        }
        h += temp;
      }
      cout << h << "\n";
    }
  }
}
