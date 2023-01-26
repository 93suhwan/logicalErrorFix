#include <bits/stdc++.h>
using namespace std;
void init_code() {}
long long int a[200001][31];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init_code();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a, as;
    for (long long int i = 0; i < n; ++i) {
      long long int x;
      cin >> x;
      a.push_back(x);
      as.push_back(x);
    }
    string s;
    cin >> s;
    vector<long long int> a1, a0;
    for (long long int i = 0; i < n; ++i) {
      if (s[i] == '1')
        a1.push_back(a[i]);
      else
        a0.push_back(a[i]);
    }
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());
    sort(a0.begin(), a0.end());
    reverse(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());
    reverse(a1.begin(), a1.end());
    map<long long int, long long int> m;
    long long int j = 0;
    for (long long int i = 0; i < a1.size(); ++i) {
      m[a1[i]] = as[j++];
    }
    for (long long int i = 0; i < a0.size(); ++i) {
      m[a0[i]] = as[j++];
    }
    for (long long int i = 0; i < n; ++i) {
      cout << m[a[i]] << " ";
    }
    cout << endl;
  }
  return 0;
}
