#include <bits/stdc++.h>
using namespace std;
bool even(long long int x) { return (x % 2 == 0); }
bool odd(long long int x) { return (x % 2 != 0); }
bool compare(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first)
    return p1.second <= p2.second;
  else
    return p1.first > p2.first;
}
vector<long long int> presum(vector<long long int> v) {
  vector<long long int> res(v.size());
  res[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    res[i] = res[i - 1] + v[i];
  }
  return res;
}
void precision(int a) { cout << setprecision(a) << fixed; }
int count(string s) {
  int oc = 0, ec = 0;
  int o = 0, e = 0;
  for (int i = 0; i < s.length(); i++) {
    if (odd(i))
      o++;
    else if (even(i))
      e++;
    if (s[i] == '1') {
      if (odd(i))
        oc++;
      else if (even(i))
        ec++;
    }
    if ((oc > (ec + (5 - e))) or (ec > (oc + (5 - o)))) {
      return (i + 1);
    }
  }
  return s.length();
}
void tell(string s, int i, vector<int>& v) {
  if (i == 10) {
    v.push_back(count(s));
    return;
  }
  if (s[i] == '?') {
    string s1 = s, s2 = s;
    s1[i] = '1';
    s2[i] = '0';
    tell(s1, i + 1, v);
    tell(s2, i + 1, v);
  } else
    tell(s, i + 1, v);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> v;
    int i = 0;
    while (i != 10 && s[i] != '?') {
      i++;
    }
    if (i == 10)
      v.push_back(count(s));
    else
      tell(s, i, v);
    sort(v.begin(), v.end());
    cout << v[0] << endl;
  }
}
