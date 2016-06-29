#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node *next;
};

typedef struct Node * node_ptr;

void swap_nodes(node_ptr np1, node_ptr np2);

node_ptr newNode(int data) {
	node_ptr temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

node_ptr mergetwo(node_ptr np1, node_ptr np2) {
	
	if(np1 == np2) return np1;	
	node_ptr temp = NULL, cur = NULL;
	while(np1 && np2) {
		if(temp) {
			if(np1->data < np2->data) {
				cur->next = np1;
				np1 = np1->next;
				cur = cur->next;
			} else { 
				cur->next = np2;
				np2 = np2->next;
				cur = cur->next;
			}
		} else {
			if(np1->data < np2->data){
				temp = np1;
				np1 = np1->next;
			} else {
				temp = np2;
				np2 = np2->next;
			}
			cur = temp;
		}
	}

	if(np1) {
		cur->next = np1;
	}
	if(np2) {
		cur->next = np2;
	}

	return temp;
}

void mergeklists(vector<node_ptr>& lists) {
	int limit = lists.size()-1;
	while(limit != 0) {
		int i = 0, j = limit;
		while(i < j) {
			lists[i] = mergetwo(lists[i], lists[j]);
			i++;
			j--;
			if(i>=j)
				limit = j;
		}
	}

} 

void mergeinplace(node_ptr np1, node_ptr np2) {
	node_ptr np1c = np1;
	while(np1) {
		if(np1->data > np2->data) {
			swap_nodes(np1, np2);
			// fix np2
			node_ptr temp = np2;
			while(temp->next) {

				if(temp->data > temp->next->data) {
					swap_nodes(temp,temp->next);
					temp = temp->next;
					continue;
				} else break;
			}
		}
		np1 = np1->next;
	}

	

}

void swap_nodes(node_ptr np1, node_ptr np2) {
	int temp = np1->data;
	np1->data = np2->data;
	np2->data = temp;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<node_ptr> lists;

	while(N-- > 0) {
		int k = K;
		node_ptr head = NULL, last = NULL;
		while(k-- > 0) {
			int item;
			cin >> item;
			node_ptr list = newNode(item);
			if(head){
				last->next = list;
				last = list;
			} else {
				head = list;
				last = list;
			}
		}
		lists.emplace_back(head);
	}

	// mergeklists(lists);
	mergeinplace(lists[0], lists[1]);
	node_ptr list1 = lists[0];
	node_ptr list2 = lists[1];

	while(list1) {
		cout << list1->data << "  ";
		list1 = list1->next;
	}

	while(list2) {
		cout << list2->data << "  ";
		list2 = list2->next;
	}
	
	cout << endl;

}