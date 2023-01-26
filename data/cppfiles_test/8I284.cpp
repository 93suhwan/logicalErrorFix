#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (ceil((double)n / 3) + (2 * (n / 3)) == n) {
      cout << ceil((double)n / 3) << " " << n / 3 << "\n";
    } else {
      cout << n / 3 << " " << ceil((double)n / 3) << "\n";
    }
  }
  return 0;
}
