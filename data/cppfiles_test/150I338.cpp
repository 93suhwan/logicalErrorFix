#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vct;
    int tmp;
    int highest = 0, zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      highest = max(tmp, highest);
      if (!(tmp % 3))
        zero++;
      else if (tmp % 3 == 1)
        one++;
      else
        two++;
      vct.push_back(tmp);
    }
    if (!(highest % 3)) {
      if (one or two)
        cout << int(highest / 3) + 1 << endl;
      else
        cout << int(highest / 3) << endl;
    } else if (highest % 3 == 1) {
      if (zero == 0 or two == 0)
        cout << int(highest / 3) + 1 << endl;
      else
        cout << int(highest / 3) + 2 << endl;
    } else {
      if (one)
        cout << int(highest / 3) + 2 << endl;
      else
        cout << int(highest / 3) + 1 << endl;
    }
  }
}
