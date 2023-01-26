#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
const int mod = 2147483647;
const int N = 201020;
typedef pair<int, int> PII;
int n, m;
int arr[N];
int num[N];
vector<string> qm;
void init() {
  qm.clear();
  int cnt = 0;
  for (long long i = 1; i <= 1e8; i *= 2) {
    qm.push_back(to_string(i));
  }
}
int sol(string s, string t) {
  int sp = 0;
  int tp = 0;
  int op = 0;
  while (sp < s.length() && tp < t.length()) {
    if (s[sp] == t[tp]) {
      tp++;
      op++;
    }
    sp++;
  }
  return s.length() - op + t.length() - op;
}
int main() {
  int t;
  cin >> t;
  init();
  while (t--) {
    string s;
    cin >> s;
    int res = s.length() + 1;
    for (auto p2 : qm) res = min(res, sol(s, p2));
    cout << res << endl;
  }
  return 0;
}
