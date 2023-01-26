#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  vector<int> a;
  int k = 1000;
  int tmp = 1;
  while (k > 0) {
    if (!(tmp % 10 == 3 || tmp % 3 == 0)) {
      k--;
      a.push_back(tmp);
    }
    tmp++;
  }
  while (t--) {
    int k;
    cin >> k;
    cout << a[k - 1] << endl;
  }
}
