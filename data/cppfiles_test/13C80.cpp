#include <bits/stdc++.h>
using namespace std;
void into() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  into();
  long long int t;
  cin >> t;
  cin.get();
  while (t--) {
    string s;
    getline(cin, s);
    int count_a = 0;
    int count_b = 0;
    int count_c = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        count_a++;
      }
      if (s[i] == 'B') {
        count_b++;
      }
      if (s[i] == 'C') {
        count_c++;
      }
    }
    if (count_b == (count_a + count_c)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
