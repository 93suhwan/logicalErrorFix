#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    vector<long long int> v1, v2;
    long long int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        v1.push_back(a[i]);
      } else {
        v2.push_back(a[i]);
      }
    }
    long long int x = 1, y = v1.size() + 1;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    map<long long int, long long int> m;
    for (int i = 0; i < v2.size(); i++) {
      m[v2[i]] = y;
      y++;
    }
    for (int i = 0; i < v1.size(); i++) {
      m[v1[i]] = x;
      x++;
    }
    for (int i = 0; i < n; i++) {
      cout << m[a[i]] << " ";
    }
    cout << endl;
  }
}
