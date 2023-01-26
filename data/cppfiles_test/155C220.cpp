#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  while (cin >> n) {
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    string s;
    cin >> s;
    vector<pair<int, int> > one;
    vector<pair<int, int> > zero;
    pair<int, int> p;
    int o = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        p.second = i;
        p.first = arr[i];
        one.push_back(p);
        o++;
      } else {
        p.second = i;
        p.first = arr[i];
        zero.push_back(p);
      }
    }
    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());
    o = n - o + 1;
    for (int i = 0; i < one.size(); i++) {
      arr[one[i].second] = o++;
    }
    o = 1;
    for (int i = 0; i < zero.size(); i++) {
      arr[zero[i].second] = o++;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
