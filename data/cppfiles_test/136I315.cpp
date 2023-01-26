//░░░░░░░░░░ // You have struggled your way here with no guidance from anyone,keep the faith
//░░░░░░░░▄▐░▄▄█████▄▄     //You have practiced a hell lot of questions,have faith in yourself
//░░░░░░▄█████████████▄▀▄▄▄▄▄    //Dont just stare at the problem use that damn pen and paper
//░░░░░█████████████████▄██████ 
//░░░░████▐█████▌████████▌█████▌
//░░░████▌█████▌█░████████▐▀██▀
//░▄█████░█████▌░█░▀██████▌█▄▄▀▄
//░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
//▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
//░░███░▌▄█▌░░▀░░▀██░░▀██████▌
//░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
//░░░░██▌░░░░░░░░░░░░░▐███████▌
//░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
//░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀    
//░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀
//░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄
//░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄
//░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄
//░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐
//░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌
//░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐
//░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌
//░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//===============================Macros============================================//
typedef long long ll;
typedef vector<int> vi;
#define    FOR(i,a,n)   for(ll i=a;i<n;i++) 
#define ROF(i,a,n)  for(ll i=a;i>n;i--)
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<string> vs;
#define LSOne(S) ((S) & -(S))                    // the key operation
#define modulo 1000000007
#define pf push_front 
#define pb push_back
#define pof pop_front
#define pob pop_back
#define f front 
#define b back
# define ff first 
# define ss second
#define p push
#define po pop
#define t top
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF INT64_MAX
#define FNI INT64_MIN
//==============================Classes===============================================//

//======================================Fenwick Tree====================================//
class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};


class RUPQ {                                     // RUPQ variant
private:
  FenwickTree ft;                                // internally use PURQ FT
public:
  RUPQ(int m) : ft(FenwickTree(m)) {}
  void range_update(int ui, int uj, ll v) {
    ft.update(ui, v);                            // [ui, ui+1, .., m] +v
    ft.update(uj+1, -v);                         // [uj+1, uj+2, .., m] -v
  }                                              // [ui, ui+1, .., uj] +v
  ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};


//============================================================================//

//=============================Segment Tree===================================//

class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vi A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child

  int conquer(int a, int b) {
    if (a == -1) return b;                       // corner case
    if (b == -1) return a;
    return min(a, b);                            // RMQ
  }

  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag
      st[p] = lazy[p];                           // [L..R] has same value
      if (L != R)                                // not a leaf
        lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
      else                                       // L == R, a single index
        A[L] = lazy[p];                          // time to update this
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return -1;                        // infeasible
    if ((L >= i) && (R <= j)) return st[p];      // found the segment
    int m = (L+R)/2;
    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                   RMQ(r(p), m+1, R, max(i, m+1), j        ));
  }

  void update(int p, int L, int R, int i, int j, int val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
      int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
      int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
      st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
    }
  }

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

//===========================================================================================

//================================Union Find Disjoint sets=============================================//
class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};
//==============================================================================================

//==============================================================================================

//========================================Functions=============================================

// ll _sieve_size;
// bitset<10000010> bs;                             // 10^7 is the rough limit
// vll p;                                           // compact list of primes

// void sieve(ll upperbound) {                      // range = [0..upperbound]
//   _sieve_size = upperbound+1;                    // to include upperbound
//   bs.set();                                      // all 1s
//   bs[0] = bs[1] = 0;                             // except index 0+1
//   for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
//     // cross out multiples of i starting from i*i
//     for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
//     p.push_back(i);                              // add prime i to the list
//   }
// }

// bool isPrime(ll N) {                             // good enough prime test
//   if (N < _sieve_size) return bs[N];             // O(1) for small primes
//   for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
//     if (N%p[i] == 0)
//       return false;
//   return true;                                   // slow if N = large prime
// } // note: only guaranteed to work for N <= (last prime in vll p)^2

// int numPF(ll N) {
//   int ans = 0;
//   for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
//     while (N%p[i] == 0) { N /= p[i]; ++ans; }
//   return ans + (N != 1);
// }

// int numDiffPF(ll N) {
//   int ans = 0;
//   for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
//     if (N%p[i] == 0) ++ans;                      // count this prime factor
//     while (N%p[i] == 0) N /= p[i];               // only once
//   }
//   if (N != 1) ++ans;
//   return ans;
// }

// ll sumPF(ll N) {
//   ll ans = 0;
//   for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
//     while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
//   if (N != 1) ans += N;
//   return ans;
// }

// int numDiv(ll N) {
//   int ans = 1;                                   // start from ans = 1
//   for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
//     int power = 0;                               // count the power
//     while (N%p[i] == 0) { N /= p[i]; ++power; }
//     ans *= power+1;                              // follow the formula
//   }
//   return (N != 1) ? 2*ans : ans;                 // last factor = N^1
// }

// ll sumDiv(ll N) {
//   ll ans = 1;                                    // start from ans = 1
//   for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
//     ll multiplier = p[i], total = 1;
//     while (N%p[i] == 0) {
//       N /= p[i];
//       total += multiplier;
//       multiplier *= p[i];
//     }                                            // total for
//     ans *= total;                                // this prime factor
//   }
//   if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
//   return ans;
// }

// ll EulerPhi(ll N) {
//   ll ans = N;                                    // start from ans = N
//   for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
//     if (N%p[i] == 0) ans -= ans/p[i];            // count unique
//     while (N%p[i] == 0) N /= p[i];               // prime factor
//   }
//   if (N != 1) ans -= ans/N;                      // last factor
//   return ans;
// }

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

void BFS(vector<int> nodes,map<int,vector<int>> adjacency)
{
    int n=nodes.size(); // number of nodes
    int s=1; // source vertex
 
    queue<int> q;
    vector<bool> used(n+1);
    vector<int> d(n+1), p(n+1);
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adjacency[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
    }
    int u=10;
    if (!used[u]) {
    cout << "No path!";
    }
    else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
}

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

ll kadane_algorithm(vll v)
{
  ll curr=v[0],best=v[0]; // make these 0 for an array that allows 0 
  // ll sum=0;
  FOR(i,1,v.size())
  {
    // sum
    curr=max(v[i],curr+v[i]);
    best=max(curr,best);
  }
  return best;


}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vll v(n);
        FOR(i,0,n)
        cin>>v[i];
        ll sum=0;
        FOR(i,0,n)
        sum+=v[i];
        vll v1(n,sum);
        ll num=(n*n*(n+1))/2;
        ll num1=(n*(n+1))/2;
        bool flag=0;
        FOR(i,0,n)
        {
            v1[i]-=num1*v[i];
            ll succ=i-1;
            if(succ==-1)
            succ=n-1;
            v1[i]+=num1*v[succ];
            if(v1[i]<=0||v1[i]%num!=0)
            {
                flag=1;
            }
            v1[i]/=num;
        }
        if(flag||sum%(num1)!=0)
        cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            FOR(i,0,n)
            cout<<v1[i]<<" ";
            cout<<endl;
        }

    }
    // FOR(m,1,t+1)
    // {
    //     cout<<"Case #"<<m<<": ";
    // }
    return 0;
}