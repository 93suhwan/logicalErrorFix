#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long int ceil(long long int r, long long int d) {
  return (r / d) + (bool)(r % d);
}
string perform(string a) {
  a.push_back('0');
  reverse(a.begin(), a.end());
  while (a[0] == '0') {
    reverse(a.begin(), a.end());
    a.pop_back();
    reverse(a.begin(), a.end());
  }
  return a;
}
bool possible(string a, string b) {
  int n = a.length();
  int m = b.length();
  for (int i = 0; i <= m - n; i++) {
    bool found = true;
    for (int j = 0; j < i; j++) {
      if (b[j] == '0') {
        found = false;
        continue;
      }
    }
    for (int j = i + n; j < m; j++) {
      if (b[j] == '0') {
        found = false;
        continue;
      }
    }
    string temp1 = b.substr(i, n);
    string temp2 = temp1;
    reverse(temp1.begin(), temp1.end());
    if (found && (a == temp1 || a == temp2)) {
      return true;
    }
  }
  return false;
}
string change_string(long long int num) {
  string a1 = "";
  for (long long int i = 0; i <= 60; i++) {
    if (num & (1LL << i))
      a1 += '1';
    else
      a1 += '0';
  }
  reverse(a1.begin(), a1.end());
  while (a1[0] == '0') {
    reverse(a1.begin(), a1.end());
    a1.pop_back();
    reverse(a1.begin(), a1.end());
  }
  return a1;
}
void inputAArray(int siz, vector<int> &arr) {
  for (int i = 0; i < siz; i++) arr[i] = 1 + rand();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int t;
  t = 1;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    string a1 = "", b1 = "";
    a1 = change_string(a);
    b1 = change_string(b);
    if (a1 == b1) {
      cout << "YES" << endl;
      continue;
    } else if (b1.back() == '0') {
      cout << "NO" << endl;
      continue;
    }
    string p = a1;
    string q = perform(p);
    if (possible(p, b1) || possible(q, b1)) {
      cout << "YES" << endl;
      continue;
    }
    reverse(p.begin(), p.end());
    reverse(q.begin(), q.end());
    if (possible(p, b1) || possible(q, b1)) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
