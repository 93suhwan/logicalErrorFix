#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
vector<long long> fac(int a) {
  vector<long long> num;
  num.push_back(1);
  for (int i = 0; i <= primes.size(); ++i) {
    long long cnt = 0;
    while (a % primes[i] == 0) {
      ++cnt;
      a = a / primes[i];
    }
    vector<long long> temp = num;
    long long mult = primes[i];
    for (long long j = 0; j < cnt; ++j) {
      for (auto elem : temp) num.push_back(elem * mult);
      mult *= primes[i];
    }
    if (primes[i] * primes[i] > a) break;
  }
  if (a != 1) {
    vector<long long> temp = num;
    long long mult = a;
    for (auto elem : temp) num.push_back(elem * mult);
  }
  return num;
}
int main() {
  vector<long long> num(5000000, 1);
  for (long long i = 2; i < num.size(); ++i) {
    if (num[i] == 1) {
      primes.push_back(i);
      for (long long l = 2; l < 500000; ++l) {
        if (l * i > 4500000) break;
        num[l * i] = 0;
      }
    }
  }
  long long a, p;
  cin >> a >> p;
  vector<long long> ways(a + 1, 0);
  ways[1] = 1;
  long long prsum = 1;
  long long prdiv = 0;
  vector<long long> fact;
  for (int i = 2; i < a + 1; ++i) {
    fact.clear();
    fact = fac(i);
    for (auto elem : fact) {
      if (elem == i)
        continue;
      else {
        prdiv = prdiv - ways[elem - 1] + ways[elem];
        if (prdiv < 0) prdiv += p;
        prdiv = prdiv % p;
      }
    }
    ways[i] += prsum;
    ways[i] = ways[i] % p;
    ways[i] += prdiv;
    ways[i] = ways[i] % p;
    prsum += ways[i];
    prsum = prsum % p;
  }
  cout << ways[a] << "\n";
  return 0;
}
