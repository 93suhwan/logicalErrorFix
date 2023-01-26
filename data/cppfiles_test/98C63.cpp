#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string z;
    cin >> z;
    long long int n = z.size();
    long long int arr[300] = {0};
    long long int sum = 0;
    long long int i = 0;
    while (i < 26) {
      arr[s[i] - '0'] = i;
      i++;
    }
    i = 0;
    while (i < n - 1) {
      long long int a = abs(arr[z[i] - '0'] - arr[z[i + 1] - '0']);
      sum += a;
      i++;
    }
    cout << sum << endl;
  }
}
