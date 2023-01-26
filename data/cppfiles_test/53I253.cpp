#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long int N = 10e5 + 10;
const long long int M = 32767;
long long int a[100050] = {0};
long long int b[100050] = {0};
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n, k;
    int segment = 0;
    map<int, int> m;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n - 1; i++) {
      m[b[i]] = b[i + 1];
      cout << b[i] << " " << m[b[i]] << endl;
    }
    for (int i = 0; i < n - 1; i++) {
      cout << a[i + 1] << " " << m[a[i]] << endl;
      if ((a[i + 1] != m[a[i]]) || (a[i] == b[n - 1])) {
        segment++;
      }
    }
    if (segment < k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    memset(a, 0, n * sizeof(a[0]));
    memset(b, 0, n * sizeof(a[0]));
  }
  return 0;
}
