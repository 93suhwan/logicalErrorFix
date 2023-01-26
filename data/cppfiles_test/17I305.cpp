#include <bits/stdc++.h>
using namespace std;
void printvec(vector<int> v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ar[n][5];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> ar[i][j];
      }
    }
    if (n <= 1) {
      cout << n << endl;
      continue;
    }
    vector<long long> s;
    vector<long long> s1;
    for (long long i = 0; i < 5; i++) {
      long long min = INT_MAX;
      long long min2 = min;
      for (long long j = 0; j < n; j++) {
        if (ar[j][i] < min) {
          min2 = min;
          min = ar[j][i];
        }
      }
      s.push_back(min);
    }
    bool chck = false;
    map<int, int> mp;
    for (long long i = 0; i < n; i++) {
      int c = 0;
      for (long long j = 0; j < 5; j++) {
        if (s[j] == ar[i][j]) {
          c++;
        }
      }
      mp[i] = c;
    }
    long long maxcou = 0, maxval = 0, item;
    for (auto it : mp) {
      if (maxval < it.second) {
        maxval = it.second;
        maxcou = 0;
      }
      if (it.second == maxval) {
        maxcou++;
        item = it.first;
      }
    }
    if (maxcou > n / 2) {
      cout << -1 << endl;
    } else {
      cout << item + 1 << endl;
    }
  }
}
