#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct Ternary {
	int data;
	Ternary *left;
	Ternary *middle;
	Ternary *right;
};

typedef struct Ternary * ternary_ptr;

ternary_ptr create_ternary_node(int data) {
	ternary_ptr temp = new Ternary;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->middle = NULL;
	return temp;
}

void print_list(ternary_ptr head) {
    cout << "Created Double Linked list is: " << endl;
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

pair<ternary_ptr, ternary_ptr> tree_to_dll(ternary_ptr root) {
	if(root->left == NULL) return pair<ternary_ptr, ternary_ptr>(root, root);
	pair<ternary_ptr, ternary_ptr> tp_l, tp_m, tp_r;
	tp_l = tree_to_dll(root->left);
	tp_l.first->left = root;
	tp_m = tree_to_dll(root->middle);
	tp_l.second->right = tp_m.first;
	tp_m.first->left = tp_l.second;
	tp_r = tree_to_dll(root->right);
	tp_m.second->right = tp_r.first;
	tp_r.first->left = tp_m.second;
	root->right = tp_l.first;
	root->left = NULL;
	return pair<ternary_ptr, ternary_ptr>(root, tp_r.second);

}

int main() {

	ternary_ptr root = create_ternary_node(30);
    root->left = create_ternary_node(5);
    root->middle = create_ternary_node(11);
    root->right = create_ternary_node(63);
    root->left->left = create_ternary_node(1);
    root->left->middle = create_ternary_node(4);
    root->left->right = create_ternary_node(8);
    root->middle->left = create_ternary_node(6);
    root->middle->middle = create_ternary_node(7);
    root->middle->right = create_ternary_node(15);
    root->right->left = create_ternary_node(31);
    root->right->middle = create_ternary_node(55);
    root->right->right = create_ternary_node(65);

    // print_list(root);
    tree_to_dll(root);
    print_list(root);

	return 0;
}