#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> m;
vector<long long int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int x = a + 2 * b + 3 * c;
    if (x % 2 == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
