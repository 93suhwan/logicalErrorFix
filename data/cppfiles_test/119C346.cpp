#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long double num;
    cin >> num;
    long double sum = 0;
    for (int i = 0; i < num; i++) {
      long double temp;
      cin >> temp;
      sum += temp;
    }
    long long min = sum / num;
    long double max = ceil(double(sum) / num);
    cout << max - min << endl;
  }
  return 0;
}
