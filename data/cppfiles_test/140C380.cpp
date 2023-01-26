#include <bits/stdc++.h>
using namespace std;
void dfunc() {
  long long in;
  cin >> in;
  long long sroot = sqrt(in);
  long long croot = cbrt(in);
  long long extra = 0;
  for (long long i = 1; i <= croot; i++) {
    if (floor(sqrt(i * i * i)) == ceil(sqrt(i * i * i))) {
      extra++;
    }
  }
  cout << sroot + croot - extra << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    dfunc();
  }
  return 0;
}
