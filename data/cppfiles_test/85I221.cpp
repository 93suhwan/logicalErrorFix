#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long cost1 = 0, cost2 = 0, zero = 0, one = 0, two = 0;
    for (auto &it : s) {
      if (it == '0')
        zero++, cost1++;
      else if (it == '1')
        one++;
      else
        two++;
    }
    if (!two) cost2 = 2;
    if (!one) cost2 = 1;
    if (!zero) cost2 = 0;
    cout << min(cost1, cost2) << '\n';
  }
  return 0;
}
