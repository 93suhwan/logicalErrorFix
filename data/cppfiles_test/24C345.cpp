#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int x = n % 10;
    cout << ((n == 9) ? 1 : (x == 9) ? n / 10 + 1 : n / 10) << endl;
  }
}
