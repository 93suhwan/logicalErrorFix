#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long int n;
    cin >> n;
    int t = n % 3;
    cout << (n / 3 + t) << " " << (n - n / 3 - t) / 2 << endl;
  }
}
