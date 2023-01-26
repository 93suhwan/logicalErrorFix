#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    string str;
    cin >> str;
    long long int zeros = 0;
    for (long long int i = 0; i < n; i++) {
      if (str[i] == '0') {
        zeros++;
      }
    }
    if (zeros == 0) {
      for (long long int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    } else {
      map<pair<long long int, char>, long long int> mp;
      long long int index, val;
      for (long long int i = 0; i < n; i++) {
        mp.insert({{arr[i], str[i]}, 0});
      }
      long long int nz = 1, no = 1;
      for (auto it : mp) {
        val = it.first.first;
        if (it.first.second == '0') {
          mp[{val, '0'}] = nz;
          nz++;
        } else {
          mp[{val, '1'}] = no + zeros;
          no++;
        }
      }
      for (long long int i = 0; i < n; i++) {
        val = arr[i];
        char ch = str[i];
        cout << mp[{val, ch}] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
