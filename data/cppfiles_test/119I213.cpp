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
  for (int i = 0; i < t; i++) cout << rez[i] << endl;
  return 0;
}
