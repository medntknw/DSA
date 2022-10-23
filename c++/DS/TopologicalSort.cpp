#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<int>adj[100005], in_degree(100005, 0), visited(100005, 0);
class Compare
{
public:
    bool operator() (int a, int b)
    {
        return a>b;
    }
};
void initialize(int n){
    for(int i=0;i<n;i++){
        adj[i].clear();
        in_degree[i] = visited[i] = 0;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    initialize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    priority_queue<int, vector<int>, Compare>q;
    for(int i=1;i<=n;i++){
        if(in_degree[i] == 0){
            q.push(i);
            visited[i]=1;
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.top();
        cout<<node<<" ";
        ans.push_back(node);
        q.pop();
        for(auto i: adj[node]){
            if(!visited[i]){
                in_degree[i]--;
                if(in_degree[i] == 0){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}
int main(int argc, char *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fast_cin();
    solve();
    return 0;
}