#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    vector<long long int> v;
    for (int i = 0; i < x; i++) {
      long long int q;
      cin >> q;
      v.push_back(q);
    }
    long long int e = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i] < v[i + 1]) {
        e++;
        for (int j = i + 1; j < v.size() - 1; j++) {
          if (v[j] > v[j + 1]) {
            i = j;
            j = v.size();
            break;
          }
          if (j == v.size() - 2) {
            i = v.size();
          }
        }
      }
    }
    if (e % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
