/*#pragma once
#include "Binary_Search_Tree.h"
#include "MorseCode.h"

class BSTMorse : public Binary_Search_Tree<MorseCode>
{
public:
	// Constructor
	BSTMorse() : Binary_Search_Tree<MorseCode>() {}
	virtual bool insert(const MorseCode& item);

private:
	virtual bool insert(BTNode<MorseCode>*& local_root,
		const MorseCode& item);
};
	bool BSTMorse:: insert(const MorseCode& item) {
		return insert(this->root, item);
	}

	bool BSTMorse::insert(BTNode<MorseCode>*& local_root, const MorseCode& item) {
		if (local_root == NULL) {
			local_root = new BTNode<MorseCode>(item);
			return true;
		}
		else {
			if (item.GetCode()[0]=='*')
				return insert(local_root->left, item);
			else if (item.GetCode()[0] == '_')
				return insert(local_root->right, item);
			else
				return false;
		}
	}
	*/