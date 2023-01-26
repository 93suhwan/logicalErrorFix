#include <bits/stdc++.h>
using namespace std;
vector<long long int> calc(long long int n) {
  long long int temp = n, exchange = 1;
  while (temp > 0) {
    temp /= 10;
    exchange *= 10;
  }
  exchange /= 10;
  if (exchange == n) exchange /= 10;
  vector<long long int> v;
  while (n > 0) {
    v.push_back(exchange);
    n -= exchange;
  }
  return v;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, s, i;
    cin >> s >> n;
    multiset<long long int> ms;
    long long int ss = s, mult = 1;
    while (ss > 0) {
      long long int temp = (ss % 10) * mult;
      ss /= 10;
      if (temp > 0) ms.insert(temp);
      mult *= 10;
    }
    long long int si = ms.size();
    while (si < n) {
      multiset<long long int>::iterator it;
      for (it = ms.begin(); it != ms.end(); it++) {
        if (*it > 1) break;
      }
      vector<long long int> v = calc(*it);
      ms.erase(it);
      long long int sis = v.size();
      for (i = 0; i < sis; i++) ms.insert(v[i]);
      si = ms.size();
    }
    while (si > n) {
      long long int temp1 = *ms.rbegin();
      ms.erase(ms.find(temp1));
      long long int temp2 = *ms.rbegin();
      ms.erase(ms.find(temp2));
      ms.insert(temp1 + temp2);
      si = ms.size();
    }
    multiset<long long int>::iterator it;
    for (it = ms.begin(); it != ms.end(); it++) cout << *it << " ";
    cout << "\n";
  }
}
