// search files : ctrl + P
// go to the end to view the soln(main func)
#include "bits/stdc++.h"
#define deb(x) cout << #x << " " << x << endl;
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/hash_policy.hpp"
// #include "ext/pb_ds/exception.hpp"
// #include "ext/pb_ds/list_update_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include "ext/pb_ds/trie_policy.hpp"
// #include "ext/pb_ds/tag_and_trait.hpp"
#define ld long double
#define ll long long int
#define MOD 1000000007
#define vvn vector<vector<Node*>>
#define vs vector<string>
#define vvs vector<vs>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define vvb vector<vb>
#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define vd vector<ld>
#define vvd vector<vd>
#define umap unordered_map
#define uset unordered_set
#define chash custom_hash 
#define pq priority_queue
#define pb push_back
#define all(a)                          ::begin(a),::end(a)
#define sz(X) (ll)((X).size())

// used for debugging => use like this : deb(x) => output if x == 200 : x 200

#define Fo(i, n) for (ll i=0; i<n; i++)

#define fo(i, a, b) for (ll i=a; i<b; i++)  

// eg on how to use the above macro
// int c = 2, d = 5;
// fo(i, c, d) cout << i << '\n';

using namespace std;

string YES="YES\n";
string NO="NO\n";

struct custom_hash {
	// use it like this : umap<ll, ll, chash> mapp;
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31); \
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}  // eg : read(x, y, z);

template<typename... T>
void write(T&&... args) {
    ((cout << args << " "), ...);
}  // eg : write(x, y, z, "im a good boi", 4.5, 6);

template<typename T>
bool f(T x, T y) {
    return x>y;
}  // sort a vector in reverse manner : sort(all(vec), f<ll>);

template<typename A, typename B>
ll count(A vec, B ele, bool isSorted) {
    if (isSorted) {
        auto it1=upper_bound(vec.begin(), vec.end(), ele);
        auto it2=lower_bound(vec.begin(), vec.end(), ele);
        return it1-it2;
    }
    return count(vec.begin(), vec.end(), ele);
}

template <typename A> 
A myMax(A a,A b) {
   if (a>b) return a;
   return b;
}

template <typename A, typename ... Args>
A myMax(A a, A b, Args ...args) {
   return myMax(myMax(a,b), args...);
}

template <typename A> 
A myMin(A a,A b) {
   if (a<b) return a;
   return b;
}

template <typename A, typename ... Args>
A myMin(A a, A b, Args ...args) {
   return myMin(myMin(a, b), args...);
}

template<typename A, typename B>
void printMap(map<A, B> mapp) {
    for (auto ele : mapp) cout << ele.first << " : " << ele.second << '\n';
}

template<typename A, typename B>
void printUmap(umap<A, B> mapp) {
    for (auto ele : mapp) cout << ele.first << " : " << ele.second << '\n';
}

string strMap(ll i, ll j) { return to_string(i)+":"+to_string(j); }

ll modExp(ll b, ll p) {
    // o(logp)
    ll res=1;
    b=b%MOD;
    if (b==0) return 0;
    while (p>0) {
        if (p&1) res=(res*b)%MOD;
        p=p>>1;
        b=(b*b)%MOD;
    }
    return res;
}

ll createPalindrome(ll input, ll b, bool isOdd) {
    ll n=input;
    ll palin=input;
    if (isOdd) n/=b;
    while (n>0) {
        palin=palin*b+(n%b);
        n/=b;
    }
    return palin;
}

void generatePalindromes(ll n) {
    ll number;
    // Run two times for odd and even length palindromes
    for (ll j=0; j<2; j++) {
        ll i=1;
        while ((number=createPalindrome(i, 10, j%2)) < n) {
            cout << number << " ";
            i++;
        }
    }
}

ll MAXN=1e6+1;
vl SPF(MAXN);
void spf() { 
    // shortest prime factor
    // o(log n) time 
    SPF[1]=1;
    fo(i, 2, MAXN) SPF[i] = i;
    for (ll i=4; i<MAXN; i+=2) SPF[i] = 2;
    for (ll i=3; i*i<MAXN; i++) {
        if (SPF[i]==i) {
            for (ll j=i*i; j<MAXN; j+=i) if (SPF[j]==j) SPF[j]=i;
        }
    }
}

bool isPowerofTwo(ll n) {
    if (n==0) return 0;
    if ((n&(~(n-1)))==n) return 1;
    return 0;
}

ll modDiv(ll num, ll den) {
    // calculates (num/den)%MOD
    ll inv=(ll)pow(den, MOD-2);
    return ((num%MOD)*(inv%MOD))%MOD;
}

// disjoint set union cluster
void make_set(ll v, vl &parent, vl &size) {
    //o(1). dont forget to declare parent and size array with size (n+1)(not n)
    parent[v]=v;
    size[v]=1;
}
ll find_set(ll v, vl &parent) {
    //o(1)
    if (v==parent[v]) return v;
    return parent[v]=find_set(parent[v], parent);
}
void union_sets(ll a, ll b, vl &parent, vl &size) {
    // o(1)
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a!=b) {
        if (size[a]<size[b]) swap(a, b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

ll fact(ll n) {
    if (n==0) return 1;
    ll ans=n;
    for (ll i=n-1; i>=1; --i) ans=ans*i;
    return ans;
}

ll nc2(ll n) { return (n*(n-1))/2; }

vl topo(vl jobs, vvl deps) {  // topological sort
    ll n=jobs.size();
	umap<ll, vl, chash> adj;  // adjacency list which maps prerequisites to their parents	
	umap<ll, ll, chash> in;   // it maps a node to the no of prerequisites required for it
	for (int i=0; i<deps.size(); ++i) {
		adj[deps[i][0]].push_back(deps[i][1]);  
		in[deps[i][1]]++;
	}
	deque<ll> q; 
	ll count=0;  // maximum no of jobs that we can complete. if it is less than n, then we cant complete all the jobs
	vl ans;
	for (auto job : jobs)	{
		if (in.find(job)==in.end()) {  // if a job has no prerequisites, then we add it to the queue
			q.push_back(job);
		}
	}
	while (q.size()) {
		count++;  
		int curr=q.front();
		ans.push_back(curr);
		q.pop_front();
		for (auto ele : adj[curr]) {
			in[ele]--;
			if (in[ele]==0) q.push_back(ele);
		}
	}
	if (count<n) return {};
    return ans;
}

ll bin_search(vl vec, ll no) {
    // finds the lower bound of "no" which is stored in "ele". make sure array is sorted!
    ll n=vec.size();
    ll i=0, j=vec.size();
    ll ele, ele2;
    if (vec[0]>=no) return vec[0];
    if (vec.back()<no) return -1;
    while (i<=j) {
        ll mid=(i+j)/2;
        ll el=vec[mid];
        if (mid-1<n && el>=no && vec[mid-1]<no) {
            ele=vec[mid];
            ele2=vec[mid-1];
            break;
        } else if (el<no) i=mid+1;
        else j=mid-1;
    }
    return ele;
}

vl primeFactors(ll n) {
    // this returns primes in this fashion : if 4 is a factor of n, then the returned vector contains 2 twos
    // o(sqrt(x)/logx)
    vl ans;
    if (n==2) return ans;
    while (!(n&1)) {        
        ans.pb(2);
        n=n/2;
    }
    for (ll i=3; i<=sqrt(n); i=i+2) {            
        while (n%i==0) {
            ans.pb(i);
            n=n/i;
        }
    }        
    if (n>2) ans.pb(n);
    return ans;
}

vl factors(ll n) {
    // o(sqrtn)
    vl ans;
    for (ll i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            if (n/i==i) ans.pb(i);
            else {
                ans.pb(i); 
                ans.pb(n/i);
            }
        }
    }
    return ans;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }

template<typename A>
A prefixSums(A vec) {
    ll n=vec.size();
    A ans(n);
    ans[0]=vec[0];
    fo(i, 1, n) ans[i]=ans[i-1]+vec[i];
    return ans;
}

ll kthbit(ll n, ll k) {
    // kth bit from lsb
    return (n>>k)&1;
}

bool isPrime(ll n) {
    vl primes=primeFactors(n);
    if (sz(primes)==1) return true;
    return false;
}

bool isSubSequence(string s1, string s2, ll m, ll n) {
    ll j=0;
    for (ll i=0; i<n && j<m; i++) if (s1[j]==s2[i]) j++;
    return (j==m);
}

// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
// *ordered_set.find_by_order(ind)(logn), ordered_set.order_of_key(ele)(logn)
void solve();
// vulnerabilities :
// 1. dont use inbuilt names for variables which are declared globally
// 2. when using a value after converting to it from char to int or vice versa, store the result of the 
//    conversion in a variable and use that variable
// 3. confusing mean with median 
// 4. for expressions involving with division, scale both sides of the expression by the divisor to avoid
//    precision errors
// 5. array size limit : 10^7
// 6. when giving break inside a 2D array iteration, make sure u add 2 breaks, one fr breaking out of the row
//    loop and another fr breaking out of the col loop
// 7. forgetting to read all input and breaking at the middle of input when the ans is found
// 8. convert long long to int before submission
// 9. forgetting to precompute prefix sums outside the test case loop
// 10. beware of overflows
//
// important functions to study : 
// generating palindromic numbers
//
// 1. reverse sort a vector vl: sort(all(vec), greater<ll>());
// 2. count elements in an array : count(vec, ele, isSorted);
// 3. finding max : myMax(3, 4, 5, 2, 5, ...);
// 4. use strMap(ll i, ll j) to convert pairs to strings
// 5. __builtin_popcount(n);  // counts no of set bits, for long(__builtin_popcountl), for long long(popcountll)
// 6. priority_queue<ll> // default is max heap. 
// 7. min heap : priority_queue<ll, vl, greater<ll>>
// 8. converting char to int : ch-'0', converting int to char : n+'0'
// 9. converting vc to string : accumulate(vec(all), string{});
// 10. gcd : __gcd()
// 11. reversing a vector : reverse(all(vec));
// 12. __builtin_ctz(n) // count no of trailing zeros(doesnt work fr n==0)
// 13. __builtin_clz(n) // count no of leadin zeros(doesnt work fr n==0)
// 14. multiply by 2:n<<1
// 15. %(2^k)==&(2^k-1)
//
// upper_bound specs:
// vector: upper_bound(all(vec), ele);
// finding index of lower_bounded element : lower_bound(blah...)-vec.begin()
// maps : map.upper_bound(ele);
//
// functions:
// 1. modExp(base, power)
// 2. generatePalindrome(n)
// 3. spf()
// 4. isPowerOfTwo(n)
// 5. modDivide(n, k) // modular division
// 6. Note : nlogn soln can pass for 10^9 computations
// 7. primeFactors(n)
// 8. strMap(i, j)
// 9. prefixSums(vec)
// 10. factors(n) // returns all factors of n
// 11. kthbit(n, k) // returns the kth bit of n
// 12. isPrime(n)  // returns prime or composite
// 13. isSubSequence(s1, s2, a, b)  // returns whether s1 is a subsequence of string s2, a=len(s1), b=len(s2)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15) << fixed;
    ll t=1; 
    read(t);
    while (t--) {
        ll n;
        string s;
        read(n);
        vl vec(n);
        ll e=0;
        fo(i, 0, n) {
            read(vec[i]);
            if (vec[i]==0) e++;
        }
        if (e==n) {
            fo(i, 1, n+1) {
                cout << i << ' ';
            }
            cout << '\n'; continue;
        }
        umap<ll, ll, chash> map;
        fo(i, 0, n) {
            ll ele=vec[i];
            ll temp=ele;
            ll pos=0;
            while (temp!=0) {
                if (temp&1) {
                    map[pos]++;
                }
                pos++;
                temp/=2;
            }
        }
        ll gcd=0;
        for (auto ele : map) {
            gcd=__gcd(gcd, ele.second);
        }
        vl ans=factors(gcd);
        for (auto ele : ans) {
            cout << ele << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    
}
 


  