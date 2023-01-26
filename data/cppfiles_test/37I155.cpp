#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    memset(a, 1, sizeof(a));
    while (m--) {
      int v, s, temp;
      cin >> v >> s >> temp;
      a[temp] = 0;
    }
    long long svm = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i]) {
        svm = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != svm) cout << i << " " << svm << endl;
    }
  }
}
