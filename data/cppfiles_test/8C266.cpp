#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265;
void mysolution() {
  int n;
  cin >> n;
  if (n % 3 == 0)
    cout << n / 3 << " " << n / 3 << '\n';
  else if (n % 3 == 1)
    cout << (n / 3) + 1 << " " << n / 3 << '\n';
  else
    cout << n / 3 << " " << (n / 3) + 1 << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15);
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    mysolution();
  }
}
