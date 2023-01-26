#include <bits/stdc++.h>
using namespace std;
unsigned long long m;
bool cmp(pair<string, unsigned long long> &x,
         pair<string, unsigned long long> &y) {
  unsigned long long i;
  for (i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (x.first[i] != y.first[i]) return x.first[i] < y.first[i];
    } else {
      if (x.first[i] != y.first[i]) return x.first[i] > y.first[i];
    }
  }
}
int main() {
  unsigned long long n;
  cin >> n >> m;
  vector<pair<string, unsigned long long>> res;
  for (unsigned long long i = 0; i < n; i++) {
    string buf;
    cin >> buf;
    res.push_back(make_pair(buf, i + 1));
  }
  sort(res.begin(), res.end(), cmp);
  for (auto i : res) {
    cout << i.second << " ";
  }
  return 0;
}
