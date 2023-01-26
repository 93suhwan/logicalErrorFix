#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  long long int n = 1ULL, a, b, mid, res;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    mid = a / 2;
    mid++;
    cout << b / mid << endl;
  }
  return 0;
}
