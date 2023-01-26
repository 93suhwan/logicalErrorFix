#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) b[i] = a[i];
    string s;
    cin >> s;
    sort(a, a + n);
    vector<long long> v1, v2;
    long long o = 0, e = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        e++;
      } else {
        o++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i < o)
        v1.push_back(a[i]);
      else
        v2.push_back(a[i]);
    }
    if (e == n || o == n) {
      for (int i = 0; i < n; i++) cout << b[i] << " ";
      cout << endl;
    } else {
      for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (s[i] == '1') {
          cout << v2[j] << " ";
          j++;
        } else {
          cout << v1[k] << " ";
          k++;
        }
      }
      cout << endl;
    }
  }
}
