#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.length(); i++) {
      v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != v[i]) {
        c++;
      }
    }
    cout << c << endl;
  }
}
