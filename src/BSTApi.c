
#include <stdio.h>
#include <stdlib.h> 
#include "../include/BSTApi.h"

TreeNode * createTreeNode(TreeDataPtr data){

	TreeNode *node = malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL; 
	node->right = NULL; 
	node->parent = NULL; 

	return node; 

}

Tree * createBinTree(CompareFunc compare, DeleteFunc del){
	
	Tree * tree = malloc(sizeof(Tree)); 
	tree->root = NULL; 
	tree->deleteFunc = del;
	tree->compareFunc = compare;

	return tree; 
}

info *createInfo(double userRating, double systemRating, char sentence[], char word[], int occurences){

	info* newInfo = malloc(sizeof(info)); 
	strcpy(newInfo->word, word); 
	strcpy(newInfo->sentence, sentence); 

	newInfo->userRating = userRating; 
	newInfo->systemRating = systemRating; 
	newInfo->occurences = occurences; 

	return newInfo; 
} 
void destroyBinTree(Tree * toDestroy){
	deleteTree(toDestroy->root);
	free(toDestroy->root);
	free(toDestroy);
}
void deleteTree(TreeNode* currentNode){
	if(currentNode->right != NULL){
		deleteTree(currentNode->right);
		free(currentNode->right->data);
		free(currentNode->right);
	}
	if(currentNode->left != NULL){
		deleteTree(currentNode->left); 
		free(currentNode->left->data);
		free(currentNode->left); 
	}
}
void addToTree(Tree * theTree, TreeDataPtr data){
	
	TreeNode* toAdd = createTreeNode(data);

	if(theTree->root == NULL){

		theTree->root = toAdd; 
	}else{
		addNode(theTree->root, toAdd);
	}
}
void addNode(TreeNode* current, TreeNode* toAdd){
	TreeDataPtr cData = current->data;
	TreeDataPtr nData = toAdd->data;

	//first time adding
	if(current == NULL){
		addNode(current, toAdd);
	}
	//case if its not empty
	if(((info*)cData)->word > ((info*)nData)->word){
		if(current->left == NULL){
			current->left = toAdd; 
		}else{
			addNode(current->left, toAdd); 
		}
	}else{
		if(current->right == NULL){
			current->right = toAdd; 
		}else {
			addNode(current->right, toAdd); 
		}
	}
}
void removeFromTree(Tree * theTree, TreeDataPtr data);

TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data){
	if(theTree->root == NULL){
		return NULL;
	}
	else {
		TreeNode* result = findNode(theTree->root, data);
		if(result != NULL){
			return ((info*)result->data);
		}
		return NULL;
	}
}
TreeDataPtr findNode(TreeNode* current, TreeDataPtr* toFind){
	char key1[100], key2[100];
	if(current == NULL || strcmp(key1,key2) == 0){
		return current;
	}
	strcpy(key1, ((info*)current->data)->word);
	strcpy(key2, ((info*)toFind)->word);

	if(strcmp(key1, key2) < 0){
		return findNode(current->left, toFind);
	}
	else if(strcmp(key1, key2) > 0){
		return findNode(current->right, toFind);
	}

	return current;
}
TreeDataPtr getRootData(Tree * theTree){
	return theTree->root->data;
}

void printInOrder(Tree * theTree, PrintFunc printData){

	if (theTree == NULL){
		printf("Tree is empty\n"); 
		return; 
	}
	printInOrderCall(theTree->root, printData); 
}

void printInOrderCall(TreeNode * currentNode, PrintFunc printData){

	if(currentNode == NULL){
		return; 
	}

	if (currentNode != NULL){
		printInOrderCall(currentNode->left, printData); 
		printData(currentNode->data); 
		printInOrderCall(currentNode->right, printData); 

	}
}


void stringInfo(void*data){
	info * newInfo = (info*)data; 

	printf("| Word: %s | User Rating: %lf | System Rating: %lf | Occurences: %d |\n", newInfo->word, newInfo->userRating, newInfo->systemRating, newInfo->occurences); 
}



void printPreOrder(Tree * theTree, PrintFunc printData);

void printPostOrder(Tree * theTree, PrintFunc printData);

int isTreeEmpty(Tree* theTree){
	if(theTree->root == NULL){
		return 1;
	} else{
		return 0;
	}
}

int isLeaf( TreeNode * treeNode){
	if(treeNode->left == NULL && treeNode->right == NULL){
		return 1; 
	}else{
		return 0; 
	}
}

int hasTwoChildren( TreeNode *treeNode){
	
	if(treeNode->left == NULL || treeNode->right == NULL){
		return 1; 
	}else{
		return 0; 
	}}

int getHeight( TreeNode* treeNode ){

	int depthLeft = 1, depthRight = 1;
	if(treeNode->left != NULL){
		depthLeft = getHeight(treeNode->left);
	}
	if(treeNode->right != NULL){
		depthRight = getHeight(treeNode->right);
	}

	if(depthRight > depthLeft){
		return depthRight+1;
	}else{
		return depthLeft+1;
	}
}
