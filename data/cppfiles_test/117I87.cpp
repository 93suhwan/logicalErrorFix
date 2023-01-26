        #include <bits/stdc++.h>
        using namespace std;
        #define  ll long long
        #define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/tree_policy.hpp>
        using namespace __gnu_pbds;
        #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
        #define ld long double
        #define pb push_back
        #define all(v) v.begin(), v.end()
        //const double eps = 1e-7;
        ll lcm(ll a, ll b) { return (b / __gcd(a, b)) * a; }
        #pragma GCC optimize("Ofast")
        #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
        #pragma GCC optimize("unroll-loops")
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int freq[1000000];
        const int N=1e3;


/*
         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#   ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##    C++
                        ##   C++C++C++
               o##########  C++C++C++C++
             o##"   ""###  C++C++C++C++C++
 o#######o  ###   oo####  C++C++C++C++C++C++
o##"  ""#############""   C++C++C++C++C++C++C++
##"         ##            C++C++C++C++C++C++C++C++
##          ###
##           ###
##            ##
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/

        int parents[N] , cnt[N];
        void intialzie(int n) {
            for (int i=1;i<=n;i++)
            {
                parents[i]=i;
                cnt[i]=1;
            }
        }
        int Find_parent(int u) {
            if (u == parents[u])return u;
            return parents[u] = Find_parent(parents[u]);
        }
        bool sameparent(int u ,int v)

        {
            return  parents[u] == parents[v];
        }
        int mxx= 0;
        void merge(int u, int v) {
            u = Find_parent(u);
            v = Find_parent(v);
            if (u != v) {
                if (cnt[u] > cnt[v])
                    swap(u, v);
                parents[u] = v;
                cnt[v] += cnt[u];
                mxx = max(cnt[v],mxx);
                cout << mxx-1 << " = cnt\n";
            }
        }
//struct  DSU {
//    int parents[N] , cnt[N];
//
//
//    void intialzie(int n) {
//        for (int i=1;i<=n;i++)
//        {
//            parents[i]=i;
//            cnt[i]=1;
//        }
//    }
//    int Find_parent(int u) {
//        if (u == parents[u])return u;
//        return parents[u] = Find_parent(parents[u]);
//    }
//    void merge(int u, int v) {
//        //      cout << u  << " " << v << " \n";
//        u = Find_parent(u);
//        v = Find_parent(v);
//        if (u != v) {
//            if (cnt[u] > cnt[v])
//                swap(u, v);
//            parents[u] = v;
//            cnt[v] += cnt[u];
//        }
//    }
//};
/*
//void solveE ()
//{
//    map<int,int>mp;
//    set<int>st;
//
//    int n;
//    cin >> n;
//    vector<int>arr(n);
//    for (int i=0;i<n;i++)
//    {
//        cin >> arr[i];
//        mp[arr[i]]++;
//
//    }
//    sort(arr.begin(),arr.end());
//    //  9 9 8 7 6 5 4 2 1
//    // 1 1 1 4 4 4
//    // 4 4 4 1 1 1
//    // 5
//    for (int i=n-1;i>0;i++)
//    {
//        if (arr[i]==arr[i-1])
//        {
//            if (arr[i]+1 <=150001)
//            {
//                arr[i] = arr[i]+1;
//            }
//        }
//
//    }
//    // 10
//    //
//    // 1 2 4 6 7 8 9 10
//    for (int i=0;i<n;i++)
//    {
//        st.insert(arr[i]);
//        if (mp[arr[i]]==1)mp[arr[i]]--;
//
//    }
//    cout << st.size();
//    return;
//    for (int i=0;i<n;i++)
//    {
//        if (mp[arr[i]]==1) // its uniqe
//        {
//            st.insert(arr[i]);
//            continue;
//        }
//        if (mp[arr[i]]>1) // if im not uniqe !!
//        {
//            if (mp[arr[i]+1]>=1 && mp[arr[i]-1]>=1)
//            {
//                st.insert(arr[i]);
//                continue;// dont need to change it ..
//            }
//            if (mp[arr[i]+1]==0 && arr[i]+1 <=150001) // no thing is after  me now ..
//            {
//                mp[arr[i]]--;
//                mp[arr[i]+1]++;
//                st.insert(arr[i]);
//                st.insert(arr[i]+1);
//                continue;
//            }
//            if (mp[arr[i]-1]==0 && arr[i]-1 >=1 )
//            {
//                mp[arr[i]]--;
//                mp[arr[i]-1]++;
//                st.insert(arr[i]-1);
//            }
//        }
//    }
//    // for (auto it:st)cout << it << " ";
//    //  return;
//    cout << st.size();
//}
 */

        void dowork(int m1,int m2,vector<vector<char>>&tmpgrid) {

            ll ans = 0;

            int n, m;
            for (int move = 0; move < 4; ++move) {
                n = m1 + dx[move];
                m = m2 + dy[move];


                if (tmpgrid[n][m] == '.') {

                    ans++;
                }
            }
            if(ans==1 or !cnt){
                tmpgrid[m1][m2]='+';
                for (int k = 0; k < 4; ++k) {
                    n=m1+dx[k];
                    m=m2+dy[k];
                    if(tmpgrid[n][m]=='.')
                        dowork(n,m,tmpgrid);
                }
            }
        }

        void solve(){
            ll tmp2 =0 ;


            ll y,zz;
            cin>>y>>zz;
            map<ll,ll>mep2;
            for (int i=0;i<500;i++)mep2[i]=i++;

            vector<vector<char>> griiid(y+7,vector<char>(zz+7,'F'));
            pair<int,int> st;
            for (int i = 1; i <=y; ++i) {
                for (int j = 1; j <= zz; ++j) {
                    cin>>griiid[i][j];
                    if(griiid[i][j]=='L')
                        st.first=i,st.second=j;
                }
            }
            for (int k = 0; k < 4; ++k) {
                int i=st.first+dx[k];
                int j=st.second+dy[k];
                if(griiid[i][j]=='.')
                    dowork(i,j,griiid);
            }

            for (int i = 1; i <=y; ++i) {
                for (int j = 1; j <= zz; ++j){
                    cout<<griiid[i][j];
                }
                cout << "\n";

            }

        }
        int main()
        {
            fast;
     //   freopen("cases.in", "r", stdin);
             int test;
            cin >>test;
           while (test--)
            {
                solve();
        //     cout << "\n";
            }

        }