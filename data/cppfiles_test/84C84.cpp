#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    double n1 = n;
    long long i = ceil(n1 / 2);
    cout << s / (n - i + 1) << "\n";
  }
}
