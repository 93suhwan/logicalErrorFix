#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define int                     ll
#define ar                      array
#define sz(v)                   (int)(v.size())
#define inf                     1e18
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int>
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void tarun_the_coder()
{
	int n;
	cin >> n;
    string s;
    cin >> s;
    unordered_map<int,int>mp;
    mp[0]=0;
    int sum=0,i=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            sum--;
        }
        else
        {
            sum++;
        }

        if(sum==0 || mp.find(sum)!=mp.end())
        {
            break;
        }
        mp[sum]=i;
    }

    if(i!=n)
    {
         cout<<mp[sum]+1<<" "<<i+1<<endl;
    }
    else
    {
        cout<<"-1 -1\n";
    }
}

signed main() {

	FIO
	int t;
	t = 1;
	cin >> t;
	fo(i, 0, t - 1) {
    tarun_the_coder();
	}
	return 0;
}
