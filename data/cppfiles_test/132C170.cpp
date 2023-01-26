#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    vector<long long> v;
    long long x = arr[6];
    v.push_back(arr[0]);
    v.push_back(arr[1]);
    v.push_back(x - (arr[0] + arr[1]));
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
