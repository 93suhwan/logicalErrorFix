#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 2;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long one, two;
    one = two = n / 3;
    if (n % 3 == 1) one++;
    if (n % 3 == 2) two++;
    cout << one << " " << two << "\n";
  }
}
