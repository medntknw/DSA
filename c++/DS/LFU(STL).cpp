#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>

using namespace std;

class LFUCache{
    int n;
    int currsize;
    int minf;
    unordered_map<int, pair<int,pair<int, list<int>::iterator> > > kmp; // {key, {value, {frequency, **DLL} }}
    unordered_map<int, list<int> > fmap; // {frequency, DLL}

    public:
        LFUCache(int capacity){
            currsize = 0;
            n = capacity;
        }
        int get(int key){
            if(kmp.find(key) == kmp.end()) return -1;
            int freq = kmp[key].second.first;
            int value = kmp[key].first;
            if(freq == minf && fmap[freq].size()==0){
                minf++;
            }
            list<int>::iterator itr = kmp[key].second.second;
            kmp[key].second.first +=1; 
            fmap[freq].erase(itr);
            fmap[kmp[key].second.first].push_back(key);
            return value;
        }

        void put(int key, int value){
            if(kmp.find(key) == kmp.end()){
                if(currsize == n){
                    int rmkey = fmap[minf].front();
                    fmap[minf].pop_front();
                    kmp.erase(rmkey);
                    currsize--;
                }
                minf = 1;
                fmap[1].push_back(key);
                kmp[key] = {value, {1, --fmap[1].end()}};
                currsize++;
            }
            else{
                get(key);
                kmp[key].first = value;
            }

        }

};
int main(int argc, char*argv[]){
    LFUCache l = LFUCache(2);
    // l.put(1,1);
    // l.put(2,2);
    // cout<<"Get -> "<<l.get(1)<<endl;
    // l.put(3,3);
    // l.cache.printList();
    // debug(l.freq[1]);
    // debug(l.freq[2]);
    // cout<<"Get -> "<<l.get(2)<<endl;
    // cout<<"Get -> "<<l.get(3)<<endl;
    // l.put(4,4);
    // cout<<"Get -> "<<l.get(1)<<endl;
    // cout<<"Get -> "<<l.get(3)<<endl;
    // cout<<"Get -> "<<l.get(4)<<endl;
    
    return 0;
}