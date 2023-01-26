#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 1e6;
const long long MOD = 1e9 + 7;
const long long base = 257;
const long double eps = 1e-7;
long long a[MAX], b[MAX], n;
string s;
vector<long long> v;
void bubbleSort() {
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        cout << j + 1 << " " << j + 2 << " " << 1 << endl;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      b[i] = a[i];
    }
    long long dem = 0;
    for (long long i = 0; i < n - 1; i++) {
      for (long long j = 0; j < n - i - 1; j++) {
        if (b[j] > b[j + 1]) {
          dem++;
          swap(b[j], b[j + 1]);
        }
      }
    }
    cout << dem << endl;
    if (dem != 0) bubbleSort();
  }
}
