#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[1000];
int n;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int k = a[n - 1];
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (k < a[i]) {
        k = a[i];
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}
