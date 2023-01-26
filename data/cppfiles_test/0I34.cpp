#include <bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> const& x, pair<string, int> const& y) {
  if (y.first[0] != x.first[0]) {
    return y.first[0] > x.first[0];
  } else {
    return y.first[1] < x.first[1];
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<string, int> > inputs(n);
  for (int i = 0; i < n; i++) {
    pair<string, int> p1;
    string s;
    cin >> s;
    p1.first = s;
    p1.second = i;
    inputs[i] = p1;
  }
  auto cmp = [](string const& x, string const& y) {
    return y[0] > x[0] || y[1] < x[1];
  };
  sort(inputs.begin(), inputs.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << inputs[i].second + 1 << " ";
  }
  cout << endl;
  return 0;
}
