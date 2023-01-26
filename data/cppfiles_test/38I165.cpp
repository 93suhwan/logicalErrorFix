#include <bits/stdc++.h>
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << "\n"; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << "\n"; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << "\n"; }
void no(bool t = 1) { yes(!t); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T>
void scan(vector<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void solve() {
  long long n, t{};
  cin >> n;
  while (1) {
    if (n % 6 == 0) {
      cout << ((n / 6) * 15) << "\n";
      return;
    } else if (n % 8 == 0) {
      cout << ((n / 8) * 20) << "\n";
      return;
    } else if (n % 10 == 0) {
      cout << ((n / 10) * 25) << "\n";
      return;
    }
    n++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
