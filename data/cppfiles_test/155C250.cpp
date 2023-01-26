#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    string s;
    cin >> s;
    vector<pair<int, int>> one, zero;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        one.push_back({vec[i], i + 1});
      else
        zero.push_back({vec[i], i + 1});
    }
    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());
    int temp = n;
    for (int i = one.size() - 1; i >= 0; i--) {
      one[i].first = temp;
      temp--;
      swap(one[i].first, one[i].second);
    }
    for (int i = zero.size() - 1; i >= 0; i--) {
      zero[i].first = temp;
      temp--;
      one.push_back({zero[i].second, zero[i].first});
    }
    sort(one.begin(), one.end());
    for (int i = 0; i < n; i++) {
      cout << one[i].second << " ";
    }
    cout << endl;
  }
}
