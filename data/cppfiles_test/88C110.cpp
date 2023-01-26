#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    if (n % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    int isok = 0;
    for (int i = 1; i < n; i++) {
      if (v[i] <= v[i - 1]) {
        isok = 1;
      }
    }
    if (isok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
