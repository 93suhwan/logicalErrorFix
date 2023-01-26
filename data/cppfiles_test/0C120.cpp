#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<string, int> > inputs(n);
  for (int i = 0; i < n; i++) {
    pair<string, int> p1;
    string s;
    cin >> s;
    for (int i = 1; i < m; i += 2) {
      s[i] = ('Z' - (s[i] - 'A')) + 'A';
    }
    p1.first = s;
    p1.second = i;
    inputs[i] = p1;
  }
  sort(inputs.begin(), inputs.end());
  for (int i = 0; i < n; i++) {
    cout << inputs[i].second + 1 << " ";
  }
  cout << endl;
  return 0;
}
