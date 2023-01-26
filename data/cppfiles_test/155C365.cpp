#include <bits/stdc++.h>
using namespace std;
int main() {
  int testc;
  cin >> testc;
  while (testc--) {
    long long num;
    cin >> num;
    vector<pair<long long, long long>> v(num);
    for (long long i = 0; i < num; i++) cin >> v[i].first, v[i].second = i;
    string s;
    cin >> s;
    sort((v).begin(), (v).end());
    long long st = num;
    for (long long i = num - 1; i >= 0; i--) {
      if (s[v[i].second] == '1') {
        v[i].first = st;
        st--;
      }
    }
    for (long long i = num - 1; i >= 0; i--) {
      if (s[v[i].second] == '0') {
        v[i].first = st;
        st--;
      }
    }
    for (long long i = num - 1; i >= 0; i--) {
      swap(v[i].first, v[i].second);
    }
    sort((v).begin(), (v).end());
    for (long long i = 0; i < num; i++) cout << v[i].second << " ";
    cout << "\n";
  }
  for (int i = 0; i < 0; i++) {
  }
}
