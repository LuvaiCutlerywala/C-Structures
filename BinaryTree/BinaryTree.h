#pragma once

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BT_Node BT_Node;
struct BT_Node {
	char* value;
	BT_Node* parent;
	BT_Node* left;
	BT_Node* right;
};

typedef struct BinaryTree BinaryTree;
struct BinaryTree {
	int size;
	int maxSize;
	BT_Node* root;
};

BinaryTree* bt_generate(const int);
void bt_add(BinaryTree*, char*, BT_Node*);

#endif