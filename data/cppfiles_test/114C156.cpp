#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &cur : a) {
      cin >> cur;
    }
    sort(a.begin(), a.end());
    int smallest = a[0];
    for (int i = 0; i < n / 2; i++) {
      int cur = a[i + 1];
      cout << cur << " " << smallest << "\n";
    }
    cout << endl;
  }
  return 0;
}
