#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct ListNode {
	T data;
	shared_ptr<ListNode<T>> next;
};

int main() {
	shared_ptr<ListNode<int>> F = nullptr, L = nullptr;
	for (int i = 0; i < 10; ++i) {
      shared_ptr<ListNode<int>> temp =
          make_shared<ListNode<int>>(ListNode<int>{i, nullptr});
      temp->next = F;
      F = temp;
    }

    while(F) {
    	cout << F->data << endl;
    	F = F->next;
    }

}