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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
class MaxHeap{
    private:
        int n;
        int curr=0;
        vector<int>v;
        void heapify(int idx){
            int parent_idx = (idx-1)/2;
            if(parent_idx<0){
                return;
            }
            if(v[parent_idx] < v[idx]){
                swap(v[parent_idx], v[idx]);
                heapify(parent_idx);
            }
        }
        void maxHeapify(int idx){
            int l = 2*idx + 1;
            int r = 2*idx + 2;
            int largest;
            if(l<=curr-1 && v[l]>v[idx]){
                largest = l;
            }
            else{
                largest = idx;
            }
            if(r<=curr-1 && v[r]>v[largest]){
                largest = r;
            }
            // We find largest among parent, left and right because
            /*
                4   --->    7     
               7 8         4  8
               
               if i just compare left and then swap then we are not exactly creating a correct max heap.
            */
            if(largest != idx){
                swap(v[idx], v[largest]);
                maxHeapify(largest);
            }
        }
    public:
        MaxHeap(int n){
            v.resize(n);
        }
        int size(){
            return curr;
        }
        void debug(){
            for(int i=0;i<size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        void insert(int x){
            int idx = curr++;
            v[idx] = x;
            heapify(idx);
        }
        int pop(){
            int root = v[0];
            v[0] = v[curr-1];
            curr--;
            maxHeapify(0);
            return root;
        }
};
void solve(){
    MaxHeap x = MaxHeap(10);
    x.insert(5);
    x.insert(3);
    x.insert(4);
    x.debug();
    x.insert(6);
    x.debug();
    cout<<"Root="<<x.pop()<<endl;
    x.debug();

}
int main(int argc, char *argv[]){
    fast_cin();
    solve();
    return 0;
}