#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, s, t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    vector<int> a;
    vector<int> v1;
    vector<int> v;
    int h;
    for (int i = 0; i < n; i++) {
      cin >> h;
      v.push_back(h);
      v1.push_back(h);
      a.push_back(0);
    }
    int c = 0, j, k;
    sort(v.begin(), v.end());
    for (int i = 0; i < v1.size(); i++) {
      for (j = v.size(); v[j] != v1[i]; j--)
        ;
      for (k = 0; k != j; k++) {
        if (a[k] > 0) c++;
      }
      a[k] = v1[i];
    }
    cout << c << endl;
  }
  return 0;
}
