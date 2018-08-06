//Bradley Macdonald
//2018
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <assert.h>
#include <algorithm>

#ifdef __linux__
#include <stddef.h> //size_t
#endif

//Self balance code from.
// I converted it to c++ from java.
//https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/balancedtree/AVLTreeRecursive.java
//Uncomment this when ever you want the rotates to be printed.
//#define __BALANCE_TEST

#ifdef __BALANCE_TEST
#include <iostream>
#endif

#define __BENCHMARK_LOOP_ADD
#define __BENCHMARK_LOOP_SEARCH


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
	TreeNode(const unsigned long long &id, T val = T()) {
		this->id = id;
		left = nullptr;
		right = nullptr;
		this->val = val;
	}

	int type = -1;
	unsigned long long id; 	//! The ID of the node.
	T val;									//! Data the node has of type T
	TreeNode * left;				//! Node with an ID less than the parent node.
	TreeNode * right;				//! Node with an ID greater than the parent node.
	int bf; 								//!< The balance of the child nodes.
	int height = 0;
	TreeNode * perent = nullptr;

	/**
	*	\brief Adds a node to the tree.
	*	\param n The TreeNode to add to the tree.
	*	\return True if tree node was added to the tree.
	*/

	TreeNode<T> * AddNode(TreeNode<T> * n) {

		if (n->id < id) {
			if (left == nullptr) {
				n->perent = this;
				left = n;
				//Update(n);
				Update(this);
				if (perent != nullptr) {
					Update(perent);
					return Balance(perent);
				}
				//return Balance(n);
				return Balance(this);
			}
			else {
				left->AddNode(n);
				return this;
			}
			return nullptr;
		}
		else if (n->id > id) {
			if (right == nullptr) {
				n->perent = this;
				right = n;
				//Update(n);
				Update(this);
				if (perent != nullptr) {
					Update(perent);
					return Balance(perent);
				}
				//return Balance(n);
				return Balance(this);
			}
			else {
				right->AddNode(n);
				return this;
			}
			return nullptr;
		}
		return nullptr;
	}

	/**
	*	\brief Finds a node with the given ID.
	*	\param id The id to find.
	*	\return A pointer to the found node. Nullptr if the node wasn't found.
	*/

	TreeNode<T> * Search(const unsigned long long &id) {
		//assert(this != nullptr);
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

	TreeNode<T> * Remove(const unsigned long long &id, TreeNode<T> *parent) {
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
		return nullptr;
	}

	void CallOnVal(const unsigned long long &id, void (*callback)(const unsigned long long &, T*)) {
		if (this->id == id) {
			callback(id, &val);
			return;
		}
		else if (id < this->id && left != nullptr) {
			left->CallOnVal(id, callback);
			return;
		}
		else if (id > this->id && right != nullptr) {
			right->CallOnVal(id, callback);
			return;
		}
	}

	void CallOnVal(void(*callback)(const unsigned long long &, T*)) {
		callback(this->id, &val);
	}

	void CallOnAllVal(void(*callback)(const unsigned long long &, T*)) {

		callback(this->id, &val);

		if (left != nullptr) {
			left->CallOnAllVal(callback);
		}

		if(right != nullptr) {
			right->CallOnAllVal(callback);
		}
	}

	void CallOnTypeVal(const unsigned long long &type, void(*callback)(const unsigned long long &, T*)) {
		if (type == this->type) {
			this->CallOnVal(callback);
		}
		if (left != nullptr) {
			left->CallOnTypeVal(type, callback);
		}
		if (right != nullptr) {
			right->CallOnTypeVal(type, callback);
		}
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
private:
	void Update(TreeNode<T> *  node) {
		int leftNodeHeight  = (node->left  == nullptr) ? -1 : node->left->height;
		int rightNodeHeight = (node->right == nullptr) ? -1 : node->right->height;

		// Update this node's height.
		node->height = 1 + std::max(leftNodeHeight, rightNodeHeight);

		node->bf = rightNodeHeight - leftNodeHeight;

		#ifdef __BALANCE_TEST
		// std::cout << "Update(): " << node->bf << '\n';
		#endif
	}

	TreeNode<T> * Balance(TreeNode<T> *  node) {

		if(node->bf == -2) {
			if(node->left->bf <= 0) {
				return leftLeftCase(node);
			}
			else {
				return leftRightCase(node);
			}
		}
		else if(node->bf == 2) {

			if(node->right->bf >= 0) {
				return rightRightCase(node);
			}
			else {
				return rightLeftCase(node);
			}
		}
		return node;
	}

	TreeNode<T> * RotateLeft(TreeNode<T> *  node) {
		//This will be returned and be the right node. its ok i know what it does.
		TreeNode<T> * newPerent = node->right;
		if (node->perent != nullptr) {
			node->perent->right = newPerent;
		}
		node->right = newPerent->left;
		newPerent->left = node;
		newPerent->perent = node->perent;
		node->perent = newPerent;
		Update(node);
		Update(newPerent);
		#ifdef __BALANCE_TEST
		std::cout << "RotateLeft()\n";
		#endif
		return newPerent;
	}

	TreeNode<T> * RotateRight(TreeNode<T> *  node) {
		//This will be returned and be the right node. its ok i know what it does.
		TreeNode<T> * newPerent = node->left;
		if (node->perent != nullptr) {
			node->perent->left = newPerent;
		}
		node->left = newPerent->right;
		newPerent->right = this;
		newPerent->perent = node->perent;
		node->perent = newPerent;
		Update(node);
		Update(newPerent);
		#ifdef __BALANCE_TEST
		std::cout << "RotateRight()\n";
		#endif
		return newPerent;
	}

	TreeNode<T> * rightLeftCase(TreeNode<T> * node) {
    node->right = RotateRight(node->right);
    return rightRightCase(node);
  }

	TreeNode<T> * rightRightCase(TreeNode<T> * node) {
    return RotateLeft(node);
  }

	TreeNode<T> * leftRightCase(TreeNode<T> * node) {
    node->left = RotateLeft(node->left);
    return leftLeftCase(node);
  }

	TreeNode<T> * leftLeftCase(TreeNode<T> * node) {
	    return RotateRight(node);
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
			//Don't need these. THis is the first update.
			//p_root->Update();
			//p_root->Balance();
			return true;
		}
		else {
			#ifdef __BENCHMARK_LOOP_ADD
			TreeNode<T> * node = p_root;
			while(true) {
				if(n->id == node->id) {
					return false;
				}
				else if(n->id < node->id) {
					if(node->left != nullptr) {
						node = node->left;
					}
					else {
						//bool added = false;
						//added = node->AddNode(n);
						//node->left = n;
						if (node->AddNode(n)) {
							//Roots perent must always be nullptr
							if (p_root->perent != nullptr) {
								while (p_root->perent != nullptr) {
									p_root = p_root->perent;
								}
							}
							m_size++;
							return true;
						}
						return false;
					}
				}
				else if(n->id > node->id) {
					if(node->right != nullptr) {
						node = node->right;
					}
					else {
						//bool added = false;
						//added = node->AddNode(n);
						//node->right = n;
						if (node->AddNode(n)) {
							//Roots perent must always be nullptr
							if (p_root->perent != nullptr) {
								while (p_root->perent != nullptr) {
									p_root = p_root->perent;
								}
							}
							m_size++;
							return true;
						}
						return false;
					}
				}
			}

			#else

			bool added = false;
			added = p_root->AddNode(n);
			if (added) {
				m_size++;
			}
			return added;
			#endif // __BENCHMARK_LOOP_ADD
		}
		return false;
	}

	/**
	*	\brief Finds a node with the given ID.
	*	\param id The ID to find.
	*	\return A pointer to the found node. Nullptr if the node wasn't found.
	*/

	TreeNode<T> * Search(const unsigned long long &id) {

		#ifdef __BALANCE_TEST
		std::cout << "Searching for: " << id << '\n';
		#endif
		if (p_root) {
			#ifdef __BENCHMARK_LOOP_SEARCH

			TreeNode<T> * node = p_root;
			while(true) {
				if (id == node->id) {
					return node;
				}
				else if (id < node->id) {
					if (node->left != nullptr) {
						//Check if the left has the right id.
						node = node->left;
					}
					else {
						return nullptr;
					}
				}
				else if (id > node->id){
					if (node->right != nullptr) {
						//Check if the left has the right id.
						node = node->right;
					}
					else {
						return nullptr;
					}
				}
				/*
				if(node->right == nullptr && node->left == nullptr) {
					return nullptr;
				}
				*/
			}

			#else
			return p_root->Search(id);
			#endif //__BENCHMARK_LOOP
		}
		return nullptr;
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

	void CallOnVal(const unsigned long long &id, void(*callback)(const unsigned long long &, T*)) {
		TreeNode<T> * node = this->Search(id);
		node->CallOnVal(callback);
	}

	void CallOnAllVal(void(*callback)(const unsigned long long &, T*)) {

		p_root->CallOnAllVal(callback);
	}

	void CallOnTypeVal(const unsigned long long &type, void(*callback)(const unsigned long long &, T*)) {
		p_root->CallOnTypeVal(type, callback);
	}


private:
	TreeNode<T> * p_root;	//!< The base of the tree.
	size_t m_size;				//!< The current number of nodes in the tree.
};


#endif //BINARY_TREE_H
