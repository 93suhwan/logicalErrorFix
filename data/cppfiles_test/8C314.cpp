#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    int one, two, n;
    cin >> n;
    one = n / 3;
    two = one;
    if (n % 3 == 1)
      one++;
    else if (n % 3 == 2)
      two++;
    cout << one << " " << two << endl;
  }
}
