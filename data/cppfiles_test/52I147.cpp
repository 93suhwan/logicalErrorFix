#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
double a[100005];
double mymax;
double sum;
int main() {
  cin >> t;
  while (t--) {
    mymax = -0x7f7f7f7f;
    sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mymax = max(mymax, a[i]);
      sum = sum + a[i];
    }
    cout << mymax + (sum - mymax) / (n - 1) << endl;
  }
  return 0;
}
