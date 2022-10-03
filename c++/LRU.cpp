#include<bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define FF                first
#define SS                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=(a);i<(b);i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define fastio            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mp                make_pair
#define pii               pair<int,int>
#define inf               1e18
#define mod               1000000007
#define PI                3.1415926535
#define endl              "\n"
#define runtime cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int sbt(int x) {return __builtin_popcount(x);}
inline int mul(int a, int b, int m = mod) { return (a * b) % m; }
inline int add(int a, int b, int m = mod) { return (a + b) % m; }
inline int sub(int a, int b, int m = mod) { return (a - b + m) % m; }

class Node {
public:
	pair<int, int>data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList {
	int n;
	int currsize = 0;
	Node* start = NULL;
	Node* end = NULL;

public:
	DoublyLinkedList(int size) {
		n = size;
	}

	Node* get_start() {
		return start;
	}

	Node* get_end() {
		return end;
	}

	int get_size() {
		return currsize;
	}

	// O(1)
	void add(pair<int, int>val) {
		if (currsize == n) {
			return;
		}
		Node* newnode = new Node();
		newnode->data = val;
		newnode->next = NULL;
		newnode->prev = NULL;

		if (currsize == 0) {
			start = newnode;
			end = newnode;
			currsize++;
			return;
		}
		currsize++;
		newnode->prev = end;
		end->next = newnode;
		end = newnode;
	}

	void printList() {
		Node* n = start;
		while (n != NULL) {
			cout << '(' << n->data.first << ',' << n->data.second << ')' << " ";
			n = n->next;
		}
		cout << endl;
	}

	pair<int, int> pop_front() {
		if (currsize == 0) {
			return { -1, -1};
		}
		Node* tmp = start;
		if (currsize == 1) {
			end = NULL;
			start = NULL;
			pair<int, int>ret = tmp->data;
			delete tmp;
			currsize--;
			return ret;
		}
		currsize--;
		start->next->prev = NULL;
		start = start->next;
		pair<int, int>ret = tmp->data;
		delete tmp;
		return ret;
	}

	pair<int, int> pop_back() {
		if (currsize == 0) {
			return { -1, -1};
		}
		Node* tmp = end;
		if (currsize == 1) {
			end = NULL;
			start = NULL;
			pair<int, int> ret = tmp->data;
			delete tmp;
			currsize--;
			return ret;
		}
		currsize--;
		end = end->prev;
		end->next = NULL;
		pair<int, int> ret = tmp->data;
		delete tmp;
		return ret;
	}

	pair<int, int> pop_x(Node* n) {
		if (n == start) {
			return pop_front();
		}
		if (n == end) {
			return pop_back();
		}
		currsize--;
		n->prev->next = n->next;
		n->next->prev = n->prev;
		n->next = NULL;
		n->prev = NULL;
		pair<int, int> ret = n->data;
		delete n;
		return ret;

	}

};
class LRUCache
{
	int n;
	DoublyLinkedList l;
	map<int, Node*>hash;

public:
	LRUCache(int capacity): l(capacity) {
		n = capacity;
	}

	int get(int key)
	{
		if (hash.find(key) == hash.end()) {
			return -1;
		}
		Node* node = hash[key];
		int ret = node->data.second;
		l.pop_x(node);
		l.add({key, ret});
		return ret;
	}

	void put(int key, int value)
	{
		if (hash.find(key) != hash.end()) {
			Node* node = hash[key];
			l.pop_x(node);
			l.add({key, value});
			hash[key] = l.get_end();
			return;
		}
		if (l.get_size() == n) {
			Node* node = l.get_start();
			int k = node->data.first;
			int v = node->data.second;
			hash.erase(k);
			l.pop_front();
			l.add({key, value});
			hash[key] = l.get_end();
			return;

		}
		l.add({key, value});
		hash[key] = l.get_end();
		return;

	}
};

int32_t main() {
	fastio
	int c, q;
	cin >> c >> q;
	LRUCache cache = LRUCache(c);
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int k;
			cin >> k;
			cout << cache.get(k) << endl;
		}
		else {
			int k, v;
			cin >> k >> v;
			cache.put(k, v);
		}
	}
	runtime
	return 0;
}
