#include <bits/stdc++.h>
using namespace std;
bool prime[7532];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
string ans = "";
void printSubsequence(string input, string output) {
  if (input.empty()) {
    if (prime[stoi(output)] == false) {
      ans = output;
      return;
    }
    return;
  }
  if (ans != "") return;
  printSubsequence(input.substr(1), output + input[0]);
  printSubsequence(input.substr(1), output);
}
int main() {
  SieveOfEratosthenes(7532);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[10] = {0};
    int p = -1;
    ans = "";
    for (int i = 0; i < n; i++) {
      a[s[i] - '0']++;
      if (a[s[i] - '0'] > 1) {
        p = s[i] - '0';
        break;
      }
    }
    if (p != -1) {
      cout << 2 << endl;
      cout << p << p << endl;
    } else {
      if (a[1] > 0) {
        cout << "1\n1";
      } else if (a[6] > 0) {
        cout << "1\n6";
      } else if (a[9] > 0) {
        cout << "1\n9";
      } else if (a[8] > 0) {
        cout << "1\n8";
      } else if (a[4] > 0) {
        cout << "1\n4";
      } else {
        printSubsequence(s, "");
        cout << (ans.size()) << endl << ans;
      }
      cout << endl;
    }
  }
}
