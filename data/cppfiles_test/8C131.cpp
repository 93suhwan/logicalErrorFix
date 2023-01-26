#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int c1[t], c2[t];
  long long int n;
  for (int i = 0; i < t; i++) {
    cin >> n;
    c2[i] = n / 3;
    if (n % 3 == 0)
      c1[i] = n / 3;
    else
      c1[i] = (n / 3) + 1;
    if (!(c1[i] + 2 * c2[i] == n)) {
      c1[i]--;
      c2[i]++;
    }
  }
  for (int i = 0; i < t; i++) cout << c1[i] << " " << c2[i] << "\n";
  return 0;
}
