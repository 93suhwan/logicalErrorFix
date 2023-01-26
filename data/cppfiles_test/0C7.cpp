#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool cmp(pair<string, long long int> s1, pair<string, long long int> s2) {
  int k = s1.first.size();
  for (int i = 0; i < k; i++) {
    if (s1.first[i] == s2.first[i]) continue;
    if (i % 2 == 0) {
      return s1.first[i] < s2.first[i];
    } else {
      return s1.first[i] > s2.first[i];
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, long long int>> s1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    s1.push_back(make_pair(s, i + 1));
  }
  sort(s1.begin(), s1.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << s1[i].second << " ";
  }
  return 0;
}
