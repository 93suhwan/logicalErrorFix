#include <bits/stdc++.h>
using namespace std;
long long int solve(int k) {
  vector<long long int> arr;
  int i = 1;
  while (arr.size() != k) {
    if (i % 3 != 0 && i % 10 != 3) {
      arr.push_back(i);
    }
    i++;
  }
  arr.shrink_to_fit();
  return arr[arr.size() - 1];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << solve(k) << "\n";
  }
  return 0;
}
