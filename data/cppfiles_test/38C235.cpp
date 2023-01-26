#include <bits/stdc++.h>
using namespace std;
long long int t, n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    if (n < 6) n = 6;
    while (n % 2) n++;
    cout << (n / 2) * 5 << endl;
  }
  return 0;
}
