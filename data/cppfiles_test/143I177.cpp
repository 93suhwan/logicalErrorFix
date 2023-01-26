#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define nl "\n"
typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;
typedef vector<vi>vvi;
typedef vector<long long>vl;
typedef vector <vl>vvl;
typedef tree<pair<int,int>, null_type,less<pair<int, int>>, rb_tree_tag,
    tree_order_statistics_node_update> indexed_multiset;
template<class T> void print(T& a) { for(auto x:a)cout<<x<<" "; cout<<"\n";}
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
const long double PI = 3.14159265358979;
const long double EPS=1e-9;


int main()
{
    FastIO

    int tt; cin>>tt;
    while(tt--)
    {
        int n,x; cin>>n;
        int cnt[n+1],cost[n+1];
        memset(cnt,0,sizeof(cnt));
        memset(cost,-1,sizeof(cost));

        

        for(int i=0; i<n; i++)
        {
            cin>>x;
            cnt[x]++;
        }

        // for(int i=0; i<=n; i++)cout<<cnt[i]<<" ";
        // cout<<nl;
        // for(int i=0; i<=n; i++)cout<<cost[i]<<" ";
        // cout<<nl;

        stack<int> st;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<cnt[i]; j++)
            {
                st.push(i);
            }
            if(st.empty())break;
            
            if(i==0)cost[i]=0;
            else cost[i]=cost[i-1];

            cost[i]+=(i-st.top());
            st.pop();
        }
        cout<<cnt[0]<<" ";
        for(int i=1; i<=n; i++)
        {
            if(cost[i-1]==-1)cout<<-1<<" ";
            else cout<<cost[i-1]+cnt[i]<<" ";
        }
        cout<<nl;
    }

    return 0;
}