#include <bits/stdc++.h>
using namespace std;
bool my_compare(pair<string, long long int> a, pair<string, long long int> b) {
  long long int n = a.first.length();
  for (long long int i = 0; i < n; i++) {
    if (a.first[i] == b.first[i])
      continue;
    else if (i % 2 == 0)
      return a.first[i] < b.first[i];
    else
      return b.first[i] < a.first[i];
  }
  return a < b;
}
int main() {
  {
    long long int n, m;
    cin >> n >> m;
    vector<pair<string, long long int> > s;
    for (long long int i = 0; i < n; i++) {
      string s1;
      cin >> s1;
      s.push_back(make_pair(s1, i + 1));
    }
    sort(s.begin(), s.end(), my_compare);
    for (long long int i = 0; i < n; i++) cout << s[i].second << " ";
  }
}
