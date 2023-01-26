#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      long long b;
      cin >> b;
      a.push_back(b);
    }
    sort(a.begin(), a.end());
    long long min = a[0], b[n];
    for (int i = 1; i < n; i++) {
      b[i] = abs(a[i] - a[i - 1]);
      if (b[i] > min) {
        min = b[i];
      }
    }
    cout << min << endl;
  }
}
