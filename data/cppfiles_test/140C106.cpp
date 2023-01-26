#include <bits/stdc++.h>
using namespace std;
long long int chk(long long int n) {
  long long int s = sqrt(n);
  if (s * s == n)
    return 1;
  else
    return 0;
}
int main() {
  int t;
  cin >> t;
  vector<long long int> vec;
  long long int i, j;
  for (i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    vec.push_back(n);
  }
  for (i = 0; i < t; i++) {
    long long int n = vec[i];
    long long int c = 0;
    c = sqrt(n);
    for (j = 2; j <= c; j++) {
      if (j * j * j <= n) {
        long long int q = chk(j * j * j);
        if (q == 0) c++;
      }
    }
    cout << c << endl;
  }
}
