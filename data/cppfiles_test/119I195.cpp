#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      auto it = max_element(a.begin(), a.end());
      auto it1 = min_element(a.begin(), a.end());
      if (*it == *it1 || *it - *it1 == 1) {
        break;
      } else {
        a[it1 - a.begin()]++;
        a[it - a.begin()]--;
      }
    }
    auto it = max_element(a.begin(), a.end());
    auto it1 = min_element(a.begin(), a.end());
    cout << *it - *it1 << endl;
  }
  return 0;
}
