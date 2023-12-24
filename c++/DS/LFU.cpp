#include<iostream>
#include<map>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;

class Node {
    public:
        int val;
        int frequency;
        list<int>::iterator freq_mp;
        Node* left;
        Node* right;
        Node(int v){
            val = v;
            left = NULL;
            right = NULL;
            frequency = 1;
        }
};

class DoublyLinkedList {
    public:
        Node* front;
        Node* back;
        int n;
        int currsize=0;
        DoublyLinkedList(int size){
            n = size;
        }

        int size(){
            return currsize;
        }
        void insert_back(int val){
            if(currsize == n) return;
            Node* curr = back;
            Node* newnode = new Node(val);
            if(currsize == 0){
                back = newnode;
                front = newnode;
                currsize++;
                return;
            }
            currsize++;
            newnode->left = back;
            back->right = newnode;
            back = newnode;
        }
        void printList() {
            cout<<"Size= "<<currsize<<endl;
            Node* n = front;
            while (n != NULL) {
                cout << '(' << n->val<<"," << n->frequency<<')' << " ";
                n = n->right;
            }
            cout << endl;
        }

        int pop_back(){
            if(currsize == 0) return -1;
            Node* tmp = back;
            if(currsize == 1){
                front = NULL;
                back = NULL;
                int ret = tmp->val;
                delete tmp;
                currsize--;
                return ret;
            }
            currsize--;
            back = back->left;
            back->right = NULL;
            int ret = tmp->val;
            delete tmp;
            return ret;
        }

        int pop_front(){
            if(currsize == 0) return -1;
            Node* tmp = front;
            if(currsize == 1){
                front = NULL;
                back = NULL;
                int ret = tmp->val;
                delete tmp;
                currsize--;
                return ret;
            }
            currsize--;
            front = front->right;
            front->left = NULL;
            int ret = tmp->val;
            delete tmp;
            return ret;
        }

        int pop_x(Node* node){
            if (node == front) {
                return pop_front();
            }
            if (node == back) {
                return pop_back();
            }
            currsize--;
            node->left->right = node->right;
            node->right->left = node->left;
            node->right = NULL;
            node->left = NULL;
            int  ret = node->val;
            delete node;
            return ret;
        }
};

class LFUCache {
    public:
        DoublyLinkedList cache;
        int n;
        int minf; // minimum frequency at a given time
        unordered_map<int, Node*> mp; // used to get the node pointer in dll
        unordered_map<int, list<int> > freq; // used to get the key of lowest frequency and remove it in O(1) [worst case: O(N)]
        LFUCache(int capacity): cache(capacity){ // initializing both LFU and cache(DLL) with capacity
        /*
        `:cache(capacity)`: This is an initializer list, and it initializes the member variable `cache` with the value of the capacity parameter.
        */
            n = capacity;
        }

        int get(int key) {
            if(mp.find(key) == mp.end()){
                return -1;
            }
            Node* ptr_to_node = mp[key];
            // remove the key from dll of frequency
            freq[ptr_to_node->frequency].erase(ptr_to_node->freq_mp);
            // Change minf
            if(minf == ptr_to_node->frequency && freq[ptr_to_node->frequency].size() == 0){
                minf+=1;
            }
            // Increase frequency
            ptr_to_node->frequency+=1;
            // Add to new frequency set
            freq[ptr_to_node->frequency].push_back(key);
            ptr_to_node->freq_mp=--freq[ptr_to_node->frequency].end();
            // Return value
            return ptr_to_node->val;
        
        }
        
        void put(int key, int value) {
            // If key doesn't exist in cache
            if(mp.find(key) == mp.end()){
                if(cache.size() == n){
                    // Remove the first key (oldest) from lowest frequency and the cache itself
                    int rmkey = freq[minf].front();
                    freq[minf].pop_front();
                    Node* node = mp[rmkey];
                    cache.pop_x(node);
                    mp.erase(rmkey);
                }
                cache.insert_back(value);
                mp[key] = cache.back;
                minf = 1;
                freq[1].push_back(key);
                cache.back->freq_mp=--freq[1].end();
            }
            // If key exists in cache
            else{
                mp[key]->val = value;
                get(key);
            }
            
        }
};

void debug(list<int>&l){
    for(auto i: l){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    LFU l = LFU(2);
    l.put(1,1);
    l.put(2,2);
    cout<<"Get -> "<<l.get(1)<<endl;
    l.put(3,3);
    // l.cache.printList();
    // debug(l.freq[1]);
    // debug(l.freq[2]);
    cout<<"Get -> "<<l.get(2)<<endl;
    cout<<"Get -> "<<l.get(3)<<endl;
    l.put(4,4);
    cout<<"Get -> "<<l.get(1)<<endl;
    cout<<"Get -> "<<l.get(3)<<endl;
    cout<<"Get -> "<<l.get(4)<<endl;
}