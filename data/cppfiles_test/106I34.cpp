#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    for (long long n = 0; n < (long long)N; n++) {
      cout << n + 1 << ' ';
    }
    cout << '\n';
  }
}
