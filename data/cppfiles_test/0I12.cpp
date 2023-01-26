#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Forx(i, a, b, x) for (int i = (a); i <= (b); i+=x)
#define read(a) ll a; cin >> a;
#define Ford(i, a, b) for (ll i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define fast_io 
#define ll long long int
#define vi         vector<int>
#define vll        vector<ll>
#define vpii       vector<pair<int,int>>
#define pr         pair<ll,ll>
#define vpll       vector<pair<ll,ll>>
#define all(v)     v.begin(),v.end()
#define sz(container) int((container).size())
#define cut(x) {cout<<x<<"\n"; continue;}
#define setprec(x) cout << fixed << showpoint << setprecision(15)<<x<<"\n";
#define endl '\n';
#define fi first
#define se second


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x)
 {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) 
{int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
typedef tree<pr,null_type,less<pr>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

//*s.find_by_order() ->returns an iterator to the k-th largest element (counting from zero);
//s.order_of_key() ->number of elements strictly smaller then our item;
//st.rbegin()->second; last element in se
//st.erase(prev(st.end())); delete last element in set;
//sort(a+1,a+n+1,[](ll x,ll y){return abs(x)>abs(y);});
//sort(v.begin(), v.end(), greater<int>()); -> not sure work for first also if second are equal;
//q=lower_bound(all(v[a[i]]),i)-v[a[i]].begin()+1;
// s.substr(start_ind,length);
// vpll shift={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}} ->shift operator;
//bool comp(pr a,pr b){return a.second<b.second;} // use for differentiate order of comparision;
// cntbit(x) __builtin_popcount(x); -> no. of bits in given no.;
// true false; memset(dp,-1,sizeof(dp));
// std::random_shuffle(all(vec));

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
const ll Maxn=2e5+5;
const ll Inf=1e18;



vector<int> sort_cyclic_shifts(string const& s) 
{
    int n = s.size();
    const int alphabet = 256;
     vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    // Basic step 0th iteration

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    // basic iteration ends
    

    vector<int> pn(n), cn(n);

    for (int h = 0; (1 << h) < n; ++h) 
    {
      // kth iteration form k-1th;

        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }

    // done all steps;

    return p;

}


vector<int> suffix_array_construction(string s) 
{
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}


struct sparse_table
{
  vector<vector<int>> st;
  vector<int> lt;

  sparse_table(vector<int> & vec)
  {
    int n=vec.size();
    int k=log2(n);
    st.resize(n,vector<int>(k+1));

    for (int i = 0; i < n; i++)
    st[i][0] = vec[i];

    for (int j = 1; j <= k; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
    st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

   // fill log table;
   
   lt.resize(n+1);
   lt[1]=0;
   for (int i = 2; i <= n; i++)
   lt[i] = lt[i/2] + 1;

  }

  int query(int l,int r)
  {
    int p=lt[r-l+1];

    return min(st[l][p],st[r-(1<<p)+1][p]);
  }
};

int main()
{
  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
  //“one of them is all alone and ever more shall be so”;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  // we need lcp,lcs,range min,haromoic values;

  // all take nlogn time;

  string s; cin>>s;
  int n=s.size();
  
  if(n==1)
  {
    cout<<1;
    return 0;
  }

  string str=s;
  reverse(all(str));

  vi p = suffix_array_construction(s);
  vi lcp = lcp_construction(s,p);

  vi p1 = suffix_array_construction(str);
  vi lcs = lcp_construction(str,p1);
  

  For(i,0,n-1) p1[i]=n-1-p1[i];

  vi idp(n),ids(n); // mapping of each ind with corr posn in p;
  For(i,0,n-1) idp[p[i]]=i,ids[p1[i]]=i;
  
  sparse_table lcs_table(lcs);
  sparse_table lcp_table(lcp);
  
  int ans=1;
  
  debug(lcp);
  debug(p);
  debug(lcs);
  debug(p1);

  For(len,1,n)
  {
    // can we change here for len->k to k->len;
    // oh yeah
    
    Forx(i,0,n-1,len)
    {
      
      int idl1=idp[i];
      int idr1=idp[i];
      
      int idl2=ids[i];
      int idr2=ids[i];
      
      // we can slide it tho

      For(k,1,n) // k+1 consecutive;
      {
        if(i+k*len>=n) break;

        idl1=min(idl1,idp[i+k*len]);
        idr1=max(idr1,idp[i+k*len]);

        int Lcp=lcp_table.query(idl1,idr1-1);
        
        idl2=min(idl2,ids[(i+k*len)]);
        idr2=max(idr2,ids[(i+k*len)]);

        int Lcs=lcs_table.query(idl2,idr2-1);

        int curr=min(Lcs,len)+min(Lcp,len)-len;

        if(curr>0)
        {
          ans=max(ans,k+1);
          debug(len,i,k+1);
        }
      }

    }

    debug(len,ans);
  }

  cout<<ans;
  

 }