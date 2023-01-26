#include <bits/stdc++.h>
using namespace std;
int main() {
  int long long t;
  cin >> t;
  while (t--) {
    int long long a, b, c;
    cin >> a >> b >> c;
    int long long sum = a + b + c;
    if (sum % 2 == 0) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
