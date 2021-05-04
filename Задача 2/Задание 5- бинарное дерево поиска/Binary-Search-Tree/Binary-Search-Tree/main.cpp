#include <iostream>
using namespace std;

class TNode
{
public:
	// constructor
	TNode(int value)
	{
		el_value = value; // number, in the high of the tree

		left = right = nullptr; // pointer to the left, right descendant
	}

	// fields
	int el_value;
	TNode *left;
	TNode *right;
};

class Binary_Tree
{
public:
	// constructor
	Binary_Tree(int k)
	{
		root = new TNode(k);
		size = 1;
	}
	
	// methods	void print()
	void print() // print tree
	{
		print_tree(root);
		cout << endl;
	};

	void insert(int k) // insert element into a tree
	{
		TNode *curr = root;

		while (curr !=nullptr && curr->el_value != k)
		{
			if (curr->el_value > k && curr->left == NULL)
			{
				curr->left = new TNode(k);
				++size;
				return;
			}
			if (curr->el_value < k && curr->right == NULL)
			{
				curr->right = new TNode(k);
				++size;
				return;
			}
			if (curr->el_value > k)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}

	bool find(int k) // find element in the tree
	{
		TNode *curr = root;

		while (curr != nullptr && curr->el_value != k)
		{
			if (curr->el_value > k) // curr value more than key => pointer to the left values
			{
				curr = curr->left;
			}
			else // curr value less than key => pointer to the right values
			{
				curr = curr->right;
			}
		}

		return curr != nullptr; // return result of finding
	}

private:
	TNode *root; // pointer to the root of the tree
	int size; // number of el in the tree

	void print_tree(TNode *curr) // output tree
	{
		if (curr != nullptr) // check if not nullptr
		{
			// recursive
			print_tree(curr->left);

			cout << curr->el_value << " ";

			print_tree(curr->right);
		}
	}
};

int main()
{
	// create bin tree
	Binary_Tree *binary_tree = new Binary_Tree(10);

	// insert values
	binary_tree->insert(6);
	binary_tree->insert(7);
	binary_tree->insert(8);

	binary_tree->insert(14);
	binary_tree->insert(15);
	binary_tree->insert(16);

	binary_tree->print();

	cout << binary_tree->find(15) << endl; // true
	cout << binary_tree->find(26) << endl; // false

	system("pause");
	return 0;
};
