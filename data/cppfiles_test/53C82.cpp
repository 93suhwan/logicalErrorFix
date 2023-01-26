#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    map<int, int> m;
    vector<long long int> v;
    for (int i = 0; i < n; i++) {
      long long int num;
      cin >> num;
      v.push_back(num);
    }
    vector<long long int> dup;
    for (int i = 0; i < n; i++) {
      dup.push_back(v[i]);
    }
    int idx = 0;
    sort(dup.begin(), dup.end());
    for (int i = 0; i < n; i++) {
      m[dup[i]] = idx;
      idx++;
    }
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
      if (v[i] > v[i + 1]) {
        c++;
      } else {
        if (m[v[i + 1]] != m[v[i]] + 1) {
          c++;
        }
      }
    }
    c++;
    if (c <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
