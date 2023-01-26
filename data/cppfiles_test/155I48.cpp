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
    vector<long long int> a;
    for (long long int i = 0; i < n; ++i) {
      long long int x;
      cin >> x;
      a.push_back(x);
    }
    string s;
    cin >> s;
    sort(a.begin(), a.end());
    long long int j = 0, k = n - 1;
    for (long long int i = 0; i < n; ++i) {
      if (s[i] == '1')
        cout << a[k--] << " ";
      else
        cout << a[j++] << " ";
    }
    cout << endl;
  }
  return 0;
}
