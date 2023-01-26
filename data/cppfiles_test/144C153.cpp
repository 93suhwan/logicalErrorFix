#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> persons(n);
    for (int i = 0; i < n; i++) persons[i] = i + 1;
    while (k--) {
      int counter = 0;
      for (int i = 0; i < m; i++) {
        int group = n / m;
        if (i < n % m) group++;
        cout << group << " ";
        for (int j = 0; j < group; j++) {
          cout << persons[counter] << " ";
          counter++;
        }
        cout << '\n';
      }
      rotate(persons.begin(), persons.begin() + (n % m) * ((n + m - 1) / m),
             persons.end());
    }
  }
  return 0;
}
