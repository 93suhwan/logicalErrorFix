#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, rez[t];
  for (int i = 0; i < t; i++) {
    cin >> n;
    long long sum = 0;
    int aj;
    for (int j = 0; j < n; j++) {
      cin >> aj;
      sum += aj;
    }
    rez[i] = sum % n;
  }
  for (int i = 0; i < t; i++) {
    int outd;
    if (rez[i] != 0)
      outd = 1;
    else
      outd = 0;
    cout << outd << endl;
  }
  return 0;
}
