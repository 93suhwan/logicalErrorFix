#include <bits/stdc++.h>
int XOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
using namespace std;
int mom = 0, rambo = 0;
void solve() {
  long long x1, p1, x2, p2;
  mom++;
  rambo++;
  cin >> x1 >> p1 >> x2 >> p2;
  mom++;
  rambo++;
  if (x1 != x2) {
    if (p1 == p2) {
      mom++;
      rambo++;
      if (x1 > x2)
        cout << ">"
             << "\n";
      else
        cout << "<"
             << "\n";
    } else {
      long long temp1 = log10(x1) + 1 + p1, temp2 = log10(x2) + 1 + p2;
      mom++;
      rambo++;
      if (temp1 > temp2)
        cout << ">"
             << "\n";
      else if (temp1 < temp2)
        cout << "<"
             << "\n";
      else {
        string s = to_string(x1), p = to_string(x2);
        mom++;
        rambo++;
        long long size = min(s.size(), p.size());
        mom++;
        rambo++;
        char ans = '=';
        mom++;
        rambo++;
        for (long long i = 0; i < size; i++) {
          if (s[i] > p[i]) {
            ans = '>';
            mom++;
            rambo++;
            break;
          }
          if (p[i] > s[i]) {
            ans = '<';
            mom++;
            rambo++;
            break;
          }
        }
        if (ans == '=') {
          if (s.size() > p.size()) {
            mom++;
            rambo++;
            for (long long i = size; i < s.size(); i++) {
              mom++;
              rambo++;
              if (s[i] != '0') {
                ans = '>';
                mom++;
                rambo++;
                break;
              }
            }
          } else {
            for (long long i = size; i < p.size(); i++) {
              mom++;
              rambo++;
              if (p[i] != '0') {
                mom++;
                rambo++;
                ans = '<';
                mom++;
                rambo++;
                break;
              }
            }
          }
        }
        cout << ans << "\n";
        mom++;
        rambo++;
        mom++;
        rambo++;
        mom++;
        rambo++;
      }
    }
  } else {
    if (p1 == p2)
      cout << "="
           << "\n";
    else {
      if (p1 > p2)
        cout << ">"
             << "\n";
      else
        cout << "<"
             << "\n";
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  clock_t start, end;
  start = clock();
  int zyx;
  cin >> zyx;
  for (int tc = 1; tc < zyx + 1; tc += 1) {
    solve();
  }
  end = clock();
  double timeo = double(end - start) / CLOCKS_PER_SEC;
  return 0;
}
