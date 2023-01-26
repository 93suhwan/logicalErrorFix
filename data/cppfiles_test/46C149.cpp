#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const long long INF = 1e18;
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, max = 0;
    cin >> n;
    long long a[n];
    for (int i = (int)0; i < (int)n; ++i) {
      cin >> a[i];
      if (a[i] > max) max = a[i];
    }
    long long tam = n - 1, kq = 0;
    while (a[tam] != max) {
      long long i = tam - 1;
      while (a[i] <= a[tam]) i--;
      tam = i;
      kq++;
    }
    cout << kq << endl;
  }
}
