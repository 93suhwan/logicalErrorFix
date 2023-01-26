#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void leftRotate(long long int arr[], int d, int n) {
  d = d % n;
  int g_c_d = gcd(d, n);
  for (int i = 0; i < g_c_d; i++) {
    int temp = arr[i];
    int j = i;
    while (1) {
      int k = j + d;
      if (k >= n) k = k - n;
      if (k == i) break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}
int find(long long int l, long long int r, long long int k, int n) {
  long long int m = l + (r - l) / 2;
  if (k < m)
    return find(l, m - 1, k, n - 1);
  else if (k > m)
    return find(m + 1, r, k, n - 1);
  else
    return n;
}
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int i, j = 0, flag = 1, k = 0, n, p = 0, u = 0;
    cin >> n;
    long long int a[n];
    long long int b[n], c[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      long long int mini = INT_MAX;
      for (j = i; j < n; j++) {
        if (a[j] <= mini) {
          mini = a[j], p = j;
        }
      }
      if (i != p) {
        b[k] = i;
        c[k] = p;
        k++;
        long long int d[p - i + 1];
        long long int temp = a[p];
        u = 0;
        for (long long int q = i; q <= p; q++) {
          d[u] = a[q];
          u++;
        }
        for (long long int m = i + 1; m <= p; m++) {
          a[m] = d[m - i - 1];
        }
        a[0] = temp;
      }
    }
    cout << k << endl;
    for (i = 0; i < k; i++) {
      cout << b[i] + 1 << " " << c[i] + 1 << " " << c[i] - b[i] << endl;
    }
  }
}
