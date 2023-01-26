#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200000;
int a[1 + NMAX];
unordered_map<int, int> hm;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  a[0] = INT_MIN;
  while (t--) {
    int n;
    cin >> n;
    hm.clear();
    long long suma = 0ll;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      suma += a[i];
    }
    if (suma % n) {
      cout << 0 << '\n';
      continue;
    }
    int medie = suma / n;
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (hm.find(2 * medie - a[i]) != hm.end()) {
        sol += hm[2 * medie - a[i]];
      }
      hm[a[i]]++;
    }
    cout << sol << '\n';
  }
  return 0;
}
