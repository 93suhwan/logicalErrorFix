#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, s, t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    vector<long long int> v1;
    long long int h;
    for (int i = 0; i < n; i++) {
      cin >> h;
      v1.push_back(h);
    }
    long long int c = 0, j, k;
    for (int i = 0; i < v1.size(); i++) {
      for (j = 0; j < i; j++)
        if (v1[j] < v1[i]) c++;
    }
    cout << c << endl;
  }
  return 0;
}
