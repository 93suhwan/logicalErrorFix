#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string n1, n2;
    long long a, b;
    cin >> n1 >> a;
    cin >> n2 >> b;
    if (n1.size() + a > n2.size() + b)
      cout << ">\n";
    else if (n1.size() + a < n2.size() + b)
      cout << "<\n";
    else {
      long long n3 = stol(n1);
      long long n4 = stol(n2);
      if (n1.size() > n2.size())
        n4 *= pow(10, n1.size() - n2.size());
      else if (n1.size() < n2.size())
        n3 *= pow(10, n2.size() - n1.size());
      if (n3 > n4)
        cout << ">\n";
      else if (n3 < n4)
        cout << "<\n";
      else
        cout << "=\n";
    }
  }
}
