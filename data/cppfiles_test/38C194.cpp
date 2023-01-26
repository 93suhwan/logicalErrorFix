#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << max(6LL, n + 1) / 2 * 5 << std::endl;
  }
}
