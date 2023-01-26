#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (auto &itr : arr) {
      cin >> itr;
    }
    vector<long long> temp;
    for (long long i = 0; i < n - 1; i++) {
      long long x;
      x = arr[i] * arr[i + 1];
      temp.push_back(x);
    }
    sort(temp.begin(), temp.end());
    cout << temp[n - 2] << endl;
  }
  return 0;
}
