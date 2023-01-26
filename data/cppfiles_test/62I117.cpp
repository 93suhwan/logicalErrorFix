#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (long long int i = 1; i < n + 1; i++) cin >> v[i];
    if (v[1] != 0) {
      cout << n + 1 << " ";
      for (long long int i = 1; i < n + 1; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    if (v[n] == 0) {
      for (long long int i = 1; i < n + 2; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    int smallest = -1, largest = -1;
    for (long long int i = 1; i < n + 1; i++) {
      if (v[i] != 0 && smallest == -1) {
        smallest = i;
      } else if (v[i] == 0) {
        largest = i;
      }
    }
    if (smallest == -1 || largest == -1 || (smallest > largest + 1)) {
      cout << -1 << '\n';
      continue;
    }
    if (smallest == largest + 1) {
      for (long long int i = 1; i < largest + 1; i++) cout << i << " ";
      cout << n + 1 << " ";
      for (long long int i = smallest; i < n + 1; i++) cout << i << " ";
      cout << '\n';
      continue;
    }
    for (long long int i = 1; i < largest + 1; i++) cout << i << " ";
    cout << n + 1 << " ";
    for (long long int i = smallest; i < n + 1; i++) cout << i << " ";
    cout << '\n';
  }
  return 0;
}
