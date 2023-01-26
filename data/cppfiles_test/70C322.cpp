#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;
    int l = t.length();
    vector<long long int> count(26, 0);
    vector<long long int> freq(26, 0);
    count[t[l - 1] - 97] = 1;
    string orig = "";
    string seq = "";
    seq.push_back(t[l - 1]);
    for (int i = (l - 2); i >= 0; i--) {
      if (count[t[i] - 97] == 0) seq.push_back(t[i]);
      count[t[i] - 97]++;
    }
    reverse(seq.begin(), seq.end());
    bool flag = true;
    for (int i = 0; i < (int)seq.length(); i++) {
      if ((count[seq[i] - 97] % (i + 1)) != 0) {
        flag = false;
        break;
      } else
        freq[seq[i] - 97] = count[seq[i] - 97] / (i + 1);
    }
    if (!flag) {
      cout << -1 << "\n";
      continue;
    }
    int sum = 0;
    for (long long int x : freq) sum += x;
    orig = t.substr(0, sum);
    string dup = orig, tmp = "", check_t = orig;
    int k = 0;
    while (dup.length() > 0) {
      tmp = "";
      for (int i = 0; i < (int)dup.length(); i++) {
        if (dup[i] != seq[k]) tmp = tmp + dup[i];
      }
      check_t = check_t + tmp;
      dup = "";
      dup = tmp;
      k++;
    }
    if (t != check_t) {
      cout << -1 << "\n";
      continue;
    }
    cout << orig << " " << seq << "\n";
  }
  return 0;
}
