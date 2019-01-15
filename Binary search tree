#include<iostream>
using namespace std;
template <typename X_X>
struct node
{
	X_X data;
	node<X_X>* L_Ch;
	node<X_X>* R_Ch;
};
template <typename X_X>
class TREE
{
private:
	node<X_X>* ROOT;
	bool is_empty() {
		if (ROOT == nullptr)
			return true;
		return false;
	}
	node<X_X>* create_node(X_X val) {
		node<X_X>* T_N = new node<X_X>{val,nullptr,nullptr};//i learned new way wohooo
		//T_N->data = val;
		//T_N->L_Ch = T_N->R_Ch = nullptr;
		return T_N;
	}

	node<X_X>* search_node(X_X key, node<X_X>* crr) {
		while (crr != nullptr) {
			if (crr->data == key)		return crr;
			else if (crr->data < key)	crr = crr->R_Ch;
			else if (crr->data > key)		crr = crr->L_Ch;
		}
		return nullptr;
	}
	void insert_REC(node<X_X>* start, X_X val) {
		node<X_X>* T_N = create_node(val);
		if (is_empty())
			ROOT = T_N;
		else if (val < start->data) {
			if (start->L_Ch == nullptr)
				start->L_Ch = T_N;
			else if (start->L_Ch != nullptr)
				insert_REC(start->L_Ch, val);
		}
		else if (val > start->data) {
			if (start->R_Ch == nullptr)
				start->R_Ch = T_N;
			else if (start->R_Ch != nullptr)
				insert_REC(start->R_Ch, val);
		}
	}
	void insert_X(node<X_X>* &crr, int val)
	{
		if (crr == nullptr)
			crr = create_node(val);
		else if (val < crr->data)
			insert_X(crr->L_Ch, val);
		else if (val > crr->data)
			insert_X(crr->R_Ch, val);
	}
	void inorder(node<X_X>* start) {
		if (start != nullptr) {
			inorder(start->L_Ch);
			cout << start->data << "\t";
			inorder(start->R_Ch);
		}
	}
	int give_max_val(int n1, int n2) {
		if (n1 < n2)
			return n2;
		return n1;
	}
	int hight(node<X_X>* start) {
		if (start == nullptr)
			return -1;
		else
			return give_max_val(hight(start->L_Ch), hight(start->R_Ch)) + 1;
	}
	node<X_X>* min_val(node<X_X>* crr)
	{
		if (crr->L_Ch == nullptr)
			return crr;
		else min_val(crr->L_Ch);
	}
	node<X_X>* max_val(node<X_X>* crr)
	{
		if (crr->R_Ch == nullptr)
			return crr;
		else min_val(crr->R_Ch);
	}
	void delete_node(node<X_X>* &crr, X_X key) {
		if (crr == nullptr)
			return;
		if (key < crr->data)
			delete_node(crr->L_Ch, key);
		else if (key > crr->data)
			delete_node(crr->R_Ch, key);
		else if (crr->L_Ch != nullptr&&crr->R_Ch != nullptr) {
			crr->data = min_val(crr->R_Ch)->data;
			delete_node(crr->R_Ch, crr->data);
		}
		else {
			node<X_X>* t_n = crr;
			if (crr->L_Ch != nullptr)
				crr = crr->L_Ch;
			else
				crr = crr->R_Ch;
			delete t_n;
		}
	}
	bool search(X_X key, node<X_X>* crr) {
		while (crr != nullptr) {
			if (crr->data == key)		return true;
			else if (crr->data < key)	crr = crr->R_Ch;
			else if (crr->data > key)		crr = crr->L_Ch;
		}
		return false;
	}
	void delete_whole_tree_at_once(node<X_X>*&crr)
	{
		if (crr != nullptr)
		{
			delete_whole_tree_at_once(crr->L_Ch);
			delete_whole_tree_at_once(crr->R_Ch);
			delete crr;
		}
		crr = nullptr;
	}
public:
	TREE() {
		ROOT = nullptr;
	}
	void insert(X_X val) {
		insert_REC(ROOT, val);
	}
	void _insert(X_X val) {
		insert_X(ROOT, val);
	}
	void show() {
		inorder(ROOT);
	}
	int give_hight() {
		return hight(ROOT);
	}
	bool search(X_X key) {
		return search(key, ROOT);
	}
	node<X_X>* search_node(X_X key) {
		return search_node(key, ROOT);
	}
	void delete_key(X_X val)
	{
		delete_node(ROOT, val);
	}
	~TREE()
	{
		delete_whole_tree_at_once(ROOT);
	}

private:

};

int main()
{
	TREE<int> CX;
	for (int i = 0; i < 10; i++)
	{
		int x = 1 + rand() % 100;
		CX.insert(x);
		cout << x << endl;
	}
	CX.show();
	cout << endl << CX.search(42);
	cout << endl;
	CX.delete_key(42);
	CX.show();
	//cout<<endl<<CX.give_hight()<<endl;
	CX.~TREE();
	system("pause");
	return 0;
}
