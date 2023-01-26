#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int count = 0, current = n - 1;
    long long int maxn = *max_element(a, a + n);
    while (a[current] != maxn) {
      int i = current - 1;
      while (a[i] <= a[current]) {
        i--;
      }
      current = i;
      count++;
    }
    cout << count << endl;
  }
}
