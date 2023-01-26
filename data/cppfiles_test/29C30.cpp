#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    vector<long long> arr;
    int x = 0, m = 0;
    for (int j = 0; j < l; j++) {
      int tmp;
      cin >> tmp;
      arr.push_back(tmp);
      if (tmp == 1) {
        x++;
      }
      if (tmp == 0) {
        m++;
      }
    }
    long long k = pow(2, m);
    long long p = x * k;
    cout << p << endl;
  }
}
