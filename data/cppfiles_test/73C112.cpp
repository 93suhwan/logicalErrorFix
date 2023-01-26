#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long h = 0;
    while (!is_sorted(v.begin(), v.end())) {
      for (long long i = h % 2; i + 1 < n; i = i + 2) {
        if (v[i] > v[i + 1]) {
          long long temp = v[i];
          v[i] = v[i + 1];
          v[i + 1] = temp;
        }
      }
      h++;
    }
    cout << h << endl;
  }
  return 0;
}
