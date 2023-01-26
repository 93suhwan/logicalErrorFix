#include <bits/stdc++.h>
using namespace std;
long long int cnt = 0;
void generate_parenthesis(int n, char *out, int open, int close, int i,
                          vector<string> &s) {
  int nn = n * 2;
  if (i == nn) {
    out[i] = '\0';
    s.push_back(out);
    cnt++;
    return;
  }
  if (cnt == n) return;
  if (open < n) {
    out[i] = '(';
    generate_parenthesis(n, out, open + 1, close, i + 1, s);
  }
  if (close < open) {
    out[i] = ')';
    generate_parenthesis(n, out, open, close + 1, i + 1, s);
  }
  if (cnt == n) return;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, open, close;
    cin >> n;
    char out[100];
    vector<string> s;
    generate_parenthesis(n, out, 0, 0, 0, s);
    sort(s.begin(), s.end(), greater<string>());
    long long int c = 0;
    for (auto x : s) {
      cout << x << endl;
      c++;
      if (c == n) break;
    }
  }
  return 0;
}
