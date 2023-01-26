#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    for (auto n = (long long)2; n != (long long)N + 2; n++) {
      cout << n << ' ';
    }
    cout << '\n';
  }
}
