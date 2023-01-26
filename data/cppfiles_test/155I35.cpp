#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    vector<long long int> vec;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      vec.push_back(arr[i]);
    }
    string str;
    cin >> str;
    long long int next = 1;
    bool flag = 0;
    for (long long int i = 0; i < n; i++) {
      if (str[i] == '0') {
        vec[i] = next;
        next++;
        flag = 1;
      }
    }
    if (!flag) {
      for (long long int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else {
      for (long long int i = 0; i < n; i++) {
        if (str[i] == '1') {
          vec[i] = next;
          next++;
        }
      }
      for (long long int i = 0; i < n; i++) {
        cout << vec[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
