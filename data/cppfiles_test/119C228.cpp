#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    long long int n;
    cin >> n;
    long long int a[n], i, sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    cout << (ceil((double)sum / n)) - sum / n << endl;
    t--;
  }
}
