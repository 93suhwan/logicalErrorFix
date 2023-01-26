#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int one, two, three;
    cin >> one >> two >> three;
    cout << (one + two * 2 + three * 3) % 2 << endl;
  }
}
