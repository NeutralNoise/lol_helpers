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

/**
*	\struct TreeNode
*	\brief Describes a node on the tree.
*/

template <typename T>
struct TreeNode
{
	/**
	*	\brief Defualt constructor
	*
	*/
	TreeNode() {
		left = nullptr;
		right = nullptr;
	}

	/**
	*	\brief Creates a tree node with the given id
	*	\param id The ID the node will have.
	*/
	TreeNode(const int &id) {
		this->id = id;
		left = nullptr;
		right = nullptr;
	}

	unsigned long long id; 	//! The ID of the node.
	T val;									//! Data the node has of type T
	TreeNode * left;				//! Node with an ID less than the parent node.
	TreeNode * right;				//! Node with an ID greater than the parent node.

	/**
	*	\brief Adds a node to the tree.
	*	\param n The TreeNode to add to the tree.
	*	\return True if tree node was added to the tree.
	*/

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

	/**
	*	\brief Finds a node with the given ID.
	*	\param id The id to find.
	*	\return A pointer to the found node. Nullptr if the node wasn't found.
	*/

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

	/**
	*	\brief Vists the nodes joined to this node.
	*/

	void Vist() {
		if (left != nullptr) {
			left->Vist();
		}
		if (right != nullptr) {
			right->Vist();
		}
	}

	/**
	*	\brief Deletes all the pointers.
	*/

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

	/**
	*	\brief Removes a node from the tree.
	*	\param id The ID of the node to remove.
	*	\param parent Which node this node is connected too.
	*	\return A pointer to the removed node. Nullptr if the node wasn't removed.
	*/

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

	/**
	*	\brief Finds the lowest ID
	*	\return The lowest ID as an unsigned long long.
	*/

	unsigned long long MinValue() {
		if (left == nullptr)
			return id;
		else
			return left->MinValue();
	}
};

/**
*	\class BinaryTree
*	\brief API for interacting with binary trees.
*/

template <typename T>
class BinaryTree
{
public:

	/**
	*	\brief Defualt constructor
	*/

	BinaryTree() {
		p_root = nullptr;
		m_size = 0;
	}

	/**
	*	\brief Adds a node to the tree.
	*	\param n The TreeNode to add to the tree.
	*	\return True if tree node was added to the tree.
	*/

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

	/**
	*	\brief Finds a node with the given ID.
	*	\param id The ID to find.
	*	\return A pointer to the found node. Nullptr if the node wasn't found.
	*/

	TreeNode<T> * Search(const unsigned long long &id) {
		return p_root->Search(id);
	}

	/**
	*	\brief Vist each node on the tree. But don't do anything else.
	*/

	void Traverse() {
		p_root->Vist();
	}

	/**
	*	\brief Gets the current size of the tree.
	*	\return The current number of nodes on the tree.
	*/

	size_t size() {
		return m_size;
	}

	/**
	*	\brief Distroys the tree. Does all the cleaning.
	*/

	void Empty() {
		if (p_root != nullptr) {
			p_root->Clean();
			delete p_root;
			p_root = nullptr;
		}
	}

	/**
	*	\brief Removes a given node from the tree.
	* \param id The ID of the node to remove.
	*	\return True if the node was removed. Else its false;
	*/

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
	TreeNode<T> * p_root;	//!< The base of the tree.
	size_t m_size;				//!< The current number of nodes in the tree.
};


#endif //BINARY_TREE_H
