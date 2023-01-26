#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;
int main() {
  ll z;
  cin >> z;
  while (z--) {
    ll n, a, b;
    cin >> n;
    if (n % 2) {
      n--;
    }
    a = n / 2;
    if (a != 2)
      b = n / a;
    else
      b = n;
    cout << min(a, b) << " " << max(a, b) << endl;
  }
}
