#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int p[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int ct = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '1') ct++;
    if (ct == n) {
      for (auto i : p) cout << i << ' ';
      cout << endl;
      continue;
    }
    sort(p, p + n);
    int j = n - 1;
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        cout << p[k++] << ' ';
      else
        cout << p[j--] << ' ';
    }
    cout << endl;
  }
  return 0;
}
