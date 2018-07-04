//Bradley Macdonald
//2018
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/**
* \file BinaryTree.h
* \version 1.0
* \author Bradley Macdonald
* \date 2018
*
*  Structs for creating binary search trees.
*/

template <typename T>
struct TreeNode
{

	TreeNode() {
		left = nullptr;
		right = nullptr;
	}

	TreeNode(const int &id) {
		this->id = id;
		left = nullptr;
		right = nullptr;
	}

	unsigned long long id;
	T val;
	TreeNode * left;
	TreeNode * right;

	bool AddNode(TreeNode<T> * n) {
		if (n->id < id) {
			if (left == nullptr) {
				left = n;
				return true;
			}
			else {
				return left->AddNode(n);
			}
		}
		else if (n->id > id) {
			if (right == nullptr) {
				right = n;
				return true;
			}
			else {
				return right->AddNode(n);
			}
		}
		return false;
	}

	TreeNode<T> * Search(const int &id) {
		if (this->id == id) {
			return this;
		}
		else if (id < this->id && left != nullptr) {
			return left->Search(id);
		}
		else if (id > this->id && right != nullptr) {
			return right->Search(id);
		}

		return nullptr;
	}

	void Vist() {
		if (left != nullptr) {
			left->Vist();
		}
		if (right != nullptr) {
			right->Vist();
		}
	}

	void Clean() {
		if (left != nullptr) {
			left->Clean();
		}
		if (right != nullptr) {
			right->Clean();
		}

		if (left != nullptr) {
			delete left;
			left = nullptr;
		}
		if (right != nullptr) {
			delete right;
			right = nullptr;
		}
	}

	TreeNode<T> * Remove(const int &id, TreeNode<T> *parent) {
		if (id < this->id) {
			if (left != nullptr) {
				return left->Remove(id, this);
			}
			else {
				return nullptr;
			}
		}
		else if (id > this->id) {
			if (right != nullptr) {
				return right->Remove(id, this);
			}
			else {
				return nullptr;
			}
		}
		else {
			if (left != nullptr && right != nullptr) {
				this->id = right->MinValue();
				return right->Remove(this->id, this);
			}
			else if (parent->left == this) {
				parent->left = (left != nullptr) ? left : right;
				return this;
			}
			else if (parent->right == this) {
				parent->right = (left != nullptr) ? left : right;
				return this;
			}
		}
		return false;
	}

	unsigned long long MinValue() {

		if (left == nullptr)

			return id;

		else

			return left->MinValue();

	}

};


template <typename T>
class BinaryTree
{
public:
	BinaryTree() {
		p_root = nullptr;
		m_size = 0;
	}

	bool AddNode(TreeNode<T> * n) {
		if (p_root == nullptr) {
			p_root = n;
			m_size++;
			return true;
		}
		else {
			bool added = p_root->AddNode(n);
			if (added) {
				m_size++;
			}
			return added;
		}
		return false;
	}

	TreeNode<T> * Search(const unsigned long long &id) {
		return p_root->Search(id);
	}

	void Traverse() {
		p_root->Vist();
	}

	size_t size() {
		return m_size;
	}

	void Empty() {
		if (p_root != nullptr) {
			p_root->Clean();
			delete p_root;
			p_root = nullptr;
		}
	}

	bool Remove(const unsigned long long &id) {
		if (p_root == nullptr) {
			return false;
		}

		if (p_root->id == id) {
			TreeNode<T> auxRoot(0);
			auxRoot.left = p_root;
			TreeNode<T> *removedNode = p_root->Remove(id, &auxRoot);
			p_root = auxRoot.left;
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			TreeNode<T> * removedNode = p_root->Remove(id, nullptr);
			if (removedNode != nullptr) {
				delete removedNode;
				return true;
			}
			else {
				return false;
			}
		}
	}



private:
	TreeNode<T> * p_root;
	size_t m_size;
};


#endif //BINARY_TREE_H
