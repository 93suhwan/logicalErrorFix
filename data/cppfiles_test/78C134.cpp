#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> b >> a;
    long long int val = a / 2;
    val++;
    if (val > b)
      cout << a % val << endl;
    else
      cout << a % b << endl;
  }
}
