#include <bits/stdc++.h>
using namespace std;
bool is(long long int a) { return (a % 10 == 3 ? true : false); }
int main() {
  long long int tt;
  cin >> tt;
  while (tt--) {
    long long int k;
    cin >> k;
    long long int i = 0;
    long long int prev = 0;
    while (i < k) {
      if (!((prev + 1) % 3 == 0 || is(prev + 1))) {
        prev = prev + 1;
        i++;
      } else
        prev = prev + 1;
    }
    cout << prev << endl;
  }
}
