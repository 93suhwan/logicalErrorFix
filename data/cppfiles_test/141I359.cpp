// Problem: C. Wrong Addition
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author: vampire_questt
// Time: 2021-12-20 20:20:52

#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


// ____________________________Vampire_Questt____________________________


#define int long long
#define float long double
#define double long double

#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define pi pair<int , int>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(arr) arr.begin() , arr.end()
#define set_bits __builtin_popcountll
#define endl "\n"

#define ip(arr , n) for(int i = 0; i < n; i++) cin >> arr[i]
#define op(arr , n) for(int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
#define ipp(arr , n) for(int i = 0; i < n; i++) cin >> arr[i].ff >> arr[i].ss
#define opp(arr , n) for(int i = 0; i < n; i++) cout << '(' << arr[i].ff << ',' << arr[i].ss << ')' << ' '; cout << endl;
#define ip2d(arr , m , n) for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];
#define op2d(arr , m , n) for(int i = 0; i < m; i++) {for(int j = 0; j < n; j++) cout << arr[i][j] << ' '; cout << endl;}

const double PI = 3.141592653589793238462;
const int MOD = 1e9+7;
const int MOD1 = 998244353;

template<class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Methods : order_of_key(key_element); and find_by_order(0_based_index);

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ' '; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

template<class T> void _print(T x);
template<class T , class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> st);
template<class T> void _print(multiset<T> mst);
template<class T , class V> void _print(map<T,V> m);
template<class T> void _print(pbds<T> ost);

template<class T> void _print(T x) {cerr << x;}
template<class T , class V> void _print(pair<T,V> p) {cerr << '{'; _print(p.ff); cerr << ','; _print(p.ss); cerr << '}';}
template<class T> void _print(vector<T> v) { cerr << '[' << ' ';for(T i : v) { _print(i);cerr << ' ';} cerr << ']';}
template<class T> void _print(set<T> st) { cerr << '[' << ' ';for(T i : st) { _print(i);cerr << ' ';} cerr << ']';}
template<class T> void _print(multiset<T> mst) { cerr << '[' << ' ';for(T i : mst) { _print(i);cerr << ' ';} cerr << ']';}
template<class T , class V> void _print(map<T,V> m) { cerr << '[' << ' ';for(auto i : m) { _print(i);cerr << ' ';} cerr << ']';}
template<class T> void _print(pbds<T> ost) { cerr << '[' << ' ';for(T i : ost) { _print(i);cerr << ' ';} cerr << ']';}


// ___________Just Think Faster, there's no need to code faster___________


bool isNumber(const string& str){
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        // freopen("Error.txt" , "w" , stderr);
    #endif


    int test_cases = 1;
    cin >> test_cases;
    while(test_cases--)
    {
    	string a , s , b = "";
    	cin >> a >> s;
    	int sza = a.length() , szs = s.length();
    	vi ss(szs) , aa(sza);
    	for(int i = 0; i < sza; i++){
    		aa[i] = a[i]-'0';
    	}
    	for(int i = 0; i < szs; i++){
    		ss[i] = s[i]-'0';
    	}
    	// debug(aa);
    	// debug(ss);
    	bool ok = true;
    	int i = szs-1 , j = sza-1;
    	while(j >= 0){
    		if(i >= 0 && ss[i] >= aa[j]){
    			int x = ss[i] , y = aa[j];
    			debug(x)
    			debug(y)
    			b = char(x-y+'0')+b;
    			i--;
    			j--;
    		}
    		else{
    			if(i >= 1){
    				int x = ss[i-1]*10+ss[i];
    				int y = aa[j];
    				debug(x)
    				debug(y)
    				b = char(x-y+'0')+b;
    			}
    			else{
    				debug(i)
    				ok = false;
    				break;
    			}
    			i -= 2;
    			j--;
    		}
    		debug(b)
    	}
    	while(i >= 0){
    		b = s[i]+b;
    		i--;
    	}
    	if(!isNumber(b)){
    		ok = false;
    	}
    	if(ok){
    		cout << b << endl;
    	}
    	else{
    		cout << -1 << endl;
    	}
    }

    return 0;


// In case of any doubt, always go for a dry run, cuz there's something called Murphy's Law and it's real


}

