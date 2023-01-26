#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    long long int answer;
    answer = sqrt(n) + cbrt(n);
    double b = cbrt(n);
    long long int c = sqrt(b);
    answer = answer - c;
    cout << answer << endl;
  }
  return 0;
}
