#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, k, c;
  long long mini;
  while (t--) {
    cin >> n >> k;
    vector<int> v;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      cin >> c;
      s += c;
      v.push_back(c);
    }
    mini = s - k;
    sort(v.begin(), v.end());
    if (s <= k) {
      cout << 0 << endl;
      continue;
    }
    if (n == 1) {
      cout << s - k << endl;
      continue;
    }
    int len = v.size(), pocet;
    for (int i = 1; i < n; i++) {
      s -= v[len - i] - v[0];
      if (s <= k) {
        pocet = 0;
      } else {
        pocet = (s - k) / (i + 1);
        if ((s - k) % (i + 1) != 0) {
          pocet++;
        }
      }
      if (pocet + i < mini) {
        mini = pocet + i;
      }
    }
    cout << mini << endl;
  }
  return 0;
}
