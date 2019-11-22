// 递归中序遍历
// 借助vector<TreeNode*> 而不是使用计数器

TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k <= 0) {
		return nullptr;
	}
	vector<TreeNode*> result;
	KthNodeCore(pRoot, k, result);

	if (k > result.size()) {
		return nullptr;
	}
	return result[k - 1];
}

void KthNodeCore(TreeNode* pRoot, int k, vector<TreeNode*>& result) {
	if (pRoot == nullptr) {
		return;
	}
	if (pRoot->left != nullptr) {
		KthNodeCore(pRoot->left, k, result);
	}
	result.push_back(pRoot);
	if (result.size() == k) {
		return;
	}
	if (pRoot->right != nullptr) {
		KthNodeCore(pRoot->right, k, result);
	}

	return;
}

// 非递归中序遍历
// 借助vector<TreeNode*> 而不是使用计数器
void KthNodeCore(TreeNode* pRoot, int k, vector<TreeNode*>& result) {
	if (pRoot == nullptr) {
		return;
	}
	stack<TreeNode*> stackTreeNode;
	TreeNode* pNode = pRoot;
	while (pNode != nullptr || !stackTreeNode.empty()) {
		while (pNode != nullptr) {
			stackTreeNode.push(pNode);
			pNode = pNode->left;
		}
		if (!stackTreeNode.empty()) {
			pNode = stackTreeNode.top();
			stackTreeNode.pop();
			result.push_back(pNode);
			if (result.size() == k) {
				return;
			}
			pNode = pNode->right;
		}

	}


	return;
}


// 递归中序遍历, 使用计数器




// 非递归中序遍历, 使用计数器
