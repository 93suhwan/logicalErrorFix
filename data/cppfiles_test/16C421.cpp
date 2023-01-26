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
    string s, p;
    cin >> s;
    p = s;
    sort(s.begin(), s.end());
    long long int l = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] != p[i]) l++;
    }
    cout << l << endl;
  }
}
