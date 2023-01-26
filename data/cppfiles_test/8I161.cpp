#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << n / 3 << " ";
    cout << n - ((n / 3) * 2) << endl;
  }
}
