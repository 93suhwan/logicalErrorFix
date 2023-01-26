#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = s[i];
    }
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != arr[i]) {
        count++;
      }
    }
    cout << count << endl;
  }
}
