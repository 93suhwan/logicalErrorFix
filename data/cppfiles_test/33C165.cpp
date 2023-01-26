#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long maxi = -1;
    long long a, b;
    cin >> a;
    for (int i = 1; i < n; i++) {
      cin >> b;
      if (a * b > maxi) maxi = a * b;
      a = b;
    }
    cout << maxi << endl;
  }
}
