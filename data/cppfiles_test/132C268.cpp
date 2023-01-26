#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long long int arr[7];
    long long int arr2[3];
    unordered_map<long long int, long long int> m;
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    m[arr[0]]++;
    arr2[0] = arr[0];
    int k = 1;
    arr2[1] = arr[1];
    arr2[2] = arr[6] - arr2[0] - arr2[1];
    cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << endl;
  }
  return 0;
}
