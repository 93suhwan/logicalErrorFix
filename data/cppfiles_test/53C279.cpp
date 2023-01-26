#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int k;
int a[100005];
int b[100005];
map<int, int> rak;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      rak[b[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
      if (rak[a[i]] + 1 != rak[a[i + 1]]) {
        cnt++;
      }
    }
    if (cnt > k) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}
