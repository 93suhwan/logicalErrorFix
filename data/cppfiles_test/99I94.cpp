#include <bits/stdc++.h>
using namespace std;
long long mod(long long x) {
  return (((x % 1000000007) + 1000000007) % 1000000007);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long one = 0, two = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        one++;
      } else {
        two++;
        v.push_back(i);
      }
    }
    char** arr = new char*[n];
    for (int i = 0; i < n; i++) {
      arr[i] = new char[n];
      for (int j = 0; j < n; j++) {
        arr[i][j] = 'O';
      }
    }
    if (one == 0) {
      cout << "NO\n";
      continue;
    } else if (two == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            arr[i][j] = 'X';
          } else {
            arr[i][j] = '=';
          }
        }
      }
    } else if (two == 2 || two == 1) {
      cout << "NO\n";
      continue;
    } else {
      int cnt = 1;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          continue;
        } else {
          if (i == v[v.size() - 1]) {
            arr[i][v[0]] = '+';
            arr[v[0]][i] = '-';
          } else {
            arr[i][v[cnt]] = '+';
            arr[v[cnt]][i] = '-';
            cnt++;
          }
        }
      }
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (j == k) {
            arr[j][k] = 'X';
          } else {
            if (arr[j][k] == 'O') {
              arr[j][k] = '=';
            }
          }
        }
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << arr[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
