#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    printf("%lld %lld\n", -(n - 1), n);
  }
  return 0;
}
