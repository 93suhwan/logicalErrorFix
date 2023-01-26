#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long division = n / 3;
    long long modulo = n % 3;
    long long a = division;
    long long b = division;
    if (modulo == 1) {
      a++;
    } else if (modulo == 2) {
      b++;
    }
    cout << a << " " << b << endl;
  }
}
int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
