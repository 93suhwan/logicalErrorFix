#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long temp = b / 2 + 1;
    temp >= a ? cout << b % temp << endl : cout << b % a << endl;
  }
}
