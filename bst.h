#pragma once
#include <vector>
#include <exception>
#include <memory>
#include <iostream>

using std::cout;
using std::endl;

namespace cop3530 {

	template<typename Key, typename T>
	class bst {
		struct node {
			Key key; // key
			T data; // value
			node* left; // left child
			node* right; // right child

			node() {
			}
			node(Key k, T t) {
				key=Key(k);
				data=T(t);
				left=nullptr;
				right=nullptr;
			}
		};
		size_t treeSize;

		node* root;
		// root of tree

	public:
		bst();
		~bst();
		void insert(const Key& key, const T& t);
		node* insertHelper(node* root, const Key& key, const T& t);
		void erase(const Key& key);
		void eraseHelper(node* root, const Key& key);
		T& at(const Key& key);
		T& atHelper(node* root, const Key& key);
		bool contains(const Key& key) const;
		bool empty() const;
		size_t size() const;
		std::vector<std::pair<Key, T>> inorder_contents();
		std::vector<std::pair<Key, T>> inorder_contentsHelper(node* root, std::vector<std::pair<Key, T>>& contents);
		std::vector<std::pair<Key, T>> preorder_contents();
		std::vector<std::pair<Key, T>> preorder_contentsHelper(node* root, std::vector<std::pair<Key, T>>& contents);

	};

	template<typename Key, typename T>
	bst<Key, T>::bst() {
		root = nullptr;
		treeSize = 0;
	}

	template<typename Key, typename T>
	bst<Key, T>::~bst()
	{
		delete root;
		root = nullptr;
		treeSize = 0;

	}

	template<typename Key, typename T>
	typename bst<Key, T>::node* bst<Key, T>::insertHelper(node* root, const Key& key, const T& t) {
		//root is going to null after i insert - think about passing it as const and using a second variable to keep track of the parent nodes

		if (root == nullptr)
		{
			root = new node(key, t);
			cout << "Passed in key: " << key << " " << "Passed in data: " << t << endl;

			cout << "root key: " << root->key << " " << "root data: " << root->data << endl;
			treeSize++;
		}
		else if (root->key == key)
		{
			root->data = t;
		}
		else
		{
			if (root->key > key)
			{
				root->left=insertHelper(root->left, key, t);
				cout << "Left" << endl;
			}
			else
			{
				root->right=insertHelper(root->right, key, t);
				cout << "right" << endl;
			}
		}

		return root;
	}

	template<typename Key, typename T>
	void bst<Key, T>::insert(const Key& key, const T& t) {
		root=insertHelper(root, key, t);
	}

	template<typename Key, typename T>
	void bst<Key, T>::eraseHelper(node* root, const Key& key) {
		if (node == nullptr)
		{
			throw std::runtime_error("Node is null");
		}
	}
	template<typename Key, typename T>
	void bst<Key, T>::erase(const Key& key) {

	}

	template<typename Key, typename T>
	T& bst<Key, T>::atHelper(node* root,const Key& key) {
		if (root == nullptr)
		{
			throw std::runtime_error("Node is null");
		}
		else if (root->key == key)
		{
			T temp;
			temp = root->data;
			return temp;
		}
		else if (key < root->key)
		{
			atHelper(root->left, key);
		}
		else if (key > root->key)
		{
			atHelper(root->right, key);
		}
		
	}

	template<typename Key, typename T>
	T& bst<Key, T>::at(const Key& key)
	{
		T temp;

		temp=atHelper(root, key);
		return  temp;
	}

	template<typename Key, typename T>
	bool bst<Key, T>::contains(const Key& key) const {
		if (root == nullptr)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	template<typename Key, typename T>
	bool bst<Key, T>::empty() const {
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename Key, typename T>
	size_t bst<Key, T>::size() const {
		return 0;
	}

	template<typename Key, typename T>
	std::vector<std::pair<Key, T>> bst<Key, T>::inorder_contentsHelper(node* root, std::vector<std::pair<Key, T>>& contents) {
		

		if (root == nullptr)
		{			
			return contents;
			
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			contents.push_back(std::make_pair(root->key, root->data));
		}
		else
		{
			inorder_contentsHelper(root->left, contents);			
			contents.push_back(std::make_pair(root->key, root->data));			
			inorder_contentsHelper(root->right, contents);				
		}
		cout << "Size of the Tree is: " << treeSize << endl;
		return contents;
	}

	template<typename Key, typename T>
	std::vector<std::pair<Key, T>> bst<Key, T>::inorder_contents() {
		std::vector<std::pair<Key, T>> contents;
		contents = inorder_contentsHelper(root, contents);
		return contents;
	}

	template<typename Key, typename T>
	std::vector<std::pair<Key, T>>  bst<Key, T>::preorder_contentsHelper(node* root, std::vector<std::pair<Key, T>>& contents)
	{
		

		if (root == nullptr)
		{
			return contents;
			
		}
		else if (root->left == nullptr && root->right == nullptr)
		{
			contents.push_back(std::make_pair(root->key, root->data));
		}
		else
		{
			contents.push_back(std::make_pair(root->key, root->data));			
			preorder_contentsHelper(root->left, contents);
			preorder_contentsHelper(root->right, contents);
		}
		cout << "Size of the Tree is: " << treeSize << endl;
		return contents;
	}
	template<typename Key, typename T>
	std::vector<std::pair<Key, T>> bst<Key, T>::preorder_contents() {
		std::vector<std::pair<Key, T>> contents;
		contents = preorder_contentsHelper(root, contents);
		return contents;
	}

}
