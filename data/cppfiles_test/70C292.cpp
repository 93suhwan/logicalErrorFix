#include <bits/stdc++.h>
using namespace std;
void solve() {
  string t;
  cin >> t;
  string z = t;
  set<char> characters;
  unordered_map<char, long long> visited;
  vector<char> secondAns;
  for (long long i = 0; i < t.length(); i++) {
    characters.insert(t[i]);
  }
  long long size = characters.size();
  char temp = t[t.length() - 1];
  secondAns.push_back(temp);
  long long a = 0, b;
  if (size == 1) {
    cout << t << " " << temp << "\n";
    return;
  }
  for (long long i = 0; i < t.length(); i++) {
    if (t[i] == temp) {
      a++;
    }
  }
  b = a / size;
  if (a % size != 0) {
    cout << -1 << "\n";
    return;
  }
  long long end = t.length() - 1;
  long long sum = b;
  for (long long i = 1; i <= size - 1; i++) {
    long long j = end;
    long long temp1 = sum;
    while (sum--) {
      t[j] = '.';
      j--;
      end--;
    }
    sum = temp1;
    visited[temp] = 1;
    long long p = end;
    while (p >= 0) {
      if (visited[t[p]] == 0) {
        temp = t[p];
        secondAns.push_back(temp);
        break;
      }
      p--;
    }
    a = 0;
    for (long long k = 0; k <= end; k++) {
      if (t[k] == temp) {
        a++;
      }
    }
    if (a % (size - i) != 0) {
      cout << -1 << "\n";
      return;
    }
    b = a / (size - i);
    sum += b;
  }
  string x;
  for (long long i = 0; i < t.length(); i++) {
    if (t[i] == '.') {
      break;
    }
    x = x + t[i];
  }
  string y = x;
  unordered_map<char, long long> cut;
  for (long long d = secondAns.size() - 1; d >= 0; d--) {
    cut[secondAns[d]] = 1;
    for (long long c = 0; c < x.length(); c++) {
      if (cut[x[c]] != 1) {
        y += x[c];
      }
    }
  }
  if (y != z) {
    cout << -1 << "\n";
    return;
  }
  cout << x << " ";
  for (long long d = secondAns.size() - 1; d >= 0; d--) {
    cout << secondAns[d];
  }
  cout << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
