#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    bool leftThread;
    bool rightThread;

    TreeNode(int value)
	{
    	data=value; 
		left=0;
		right=0;
		leftThread=true;
		rightThread=true;
	}
};

class DBL {
public:
	TreeNode* root;
    DBL()   
	{
    	root=0;
	}
	
void insert(int value) 
	{
        TreeNode* newNode = new TreeNode(value);
        if (root==0)
		{
            root = newNode;
            return;
        }

        TreeNode* current = root;
        TreeNode* parent = 0;

        while (true) {
            parent = current;

            if (value < current->data) {
                if (current->leftThread!=true) {
                    current = current->left;
                } else {
                    newNode->left = current->left;
                    newNode->right = current;
                    current->left = newNode;
                    current->leftThread = false;
                    return;
                }
            } else {
                if (current->rightThread!=true) {
                    current = current->right;
                } else {
                    newNode->left = current;
                    newNode->right = current->right;
                    current->right = newNode;
                    current->rightThread = false;
                    return;
                }
            }
        }
    }


void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    TreeNode* deleteRec(TreeNode* root, int value) {
        if (root==0) 
		{
            cout<<"Value not found."<<endl;
            return root;
        }

        if (value<root->data) 
		{
            root->left=deleteRec(root->left, value);
        } else if (value > root->data)
		{
            root->right=deleteRec(root->right, value);
        } else 
		{
            if (root->leftThread && root->rightThread) 
			{
                delete root;
                return 0;
            } else if (root->leftThread)
			 {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            } else if (root->rightThread) 
			{
                TreeNode* temp=root->left;
                delete root;
                return temp;
            } else {
                TreeNode* inOrderSucc=inOrderSuccessor(root);
                root->data=inOrderSucc->data;
                root->right=deleteRec(root->right, inOrderSucc->data);
            }
        }
        return root;
    }

    
    void inOrder()
	 {
        TreeNode* current = leftMost();
        while (current != 0) {
            cout << current->data << " ";
            current = inOrderSuccessor(current);
        }
        cout<<endl;
    }

    
    TreeNode* leftMost()
	 {
        TreeNode* current = root;
        while (current != 0 && !current->leftThread) {
            current = current->left;
        }
        return current;
    }


    TreeNode* inOrderSuccessor(TreeNode* node) {
        if (node->rightThread) {
            return node->right;
        } else {
            node = node->right;
            while (!node->leftThread) {
                node = node->left;
            }
            return node;
        }
    }
TreeNode * maxValueNode(TreeNode * node) {
    TreeNode * current = node;

    while (current->right != NULL) {
      current = current->right;
    }
    return current;
  }

TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;

    while (current-> left != NULL) {
      current = current-> left;
    }
    return current;
  }
    TreeNode *iterativeSearch(int v) 
	{
    if (root==0) 
	{
      return root;
    } 
	else{
      TreeNode * temp=root;
      while (temp!=0) 
	  {
        if (v==temp->data) 
		{
          return temp;
        } else if (v<temp->data) 
		{
          temp=temp->left;
        } else 
		{
          temp=temp->right;
        }
      }
      return 0;
    }
  }
  

void updateValue(int oldValue, int newValue)
{
    TreeNode* nodeToUpdate=iterativeSearch(oldValue);

    if (nodeToUpdate==0) 
	{
        cout<<"Value not found"<<endl;
    } else 
	{
        nodeToUpdate->data=newValue;
        cout<<"Value updated successfully."<<endl;
    }
}


};

int main()
{
    DBL tree;
    TreeNode *tree2=new TreeNode(0);
    int  value;
    
while(1)
{
	cout<<"1.Add node"<<endl;
	cout<<"2.Delete node"<<endl;
	cout<<"3.Print tree"<<endl;
	cout<<"4.Search value"<<endl;
	cout<<"5.Update value"<<endl;
	cout<<"6.Max value"<<endl;
	cout<<"7.Min value"<<endl;
	cout<<"8.Exit(0)"<<endl;
	cin>>value;
	if(value==0)
    {
    	break;
	}
	else if(value==1)
	{
	cout<<"Enter value:";
    cin>>value;
    tree.insert(value);
    cout<<"Value inserted successfully"<<endl;
	}
    
	else if(value==2)
	{
	cout<<"Enter value (deletion):";
    cin>>value;
    tree.deleteNode(value);
	}
	else if(value==3)
	{
	cout << "In-order traversal: ";
    tree.inOrder();
	}
	else if(value==4)
	{
	cout<<"Enter value (Serach):";
    cin>>value;
    tree2=tree.iterativeSearch(value);
    if(tree2==0)
         {
    	cout<<"Value not found"<<endl;
	     }
	else
	    {
		cout<<"Value found"<<endl;
	    }
	}
	else if (value == 5) 
	{
       cout<<"Enter old value : ";
       int old_v;
       cin>>old_v;
       cout<<"Enter new value: ";
       int new_v;
       cin>>new_v;
       tree.updateValue(old_v, new_v);
    }
	else if(value==6)
	{
	cout<<"Maximum value:";
	TreeNode *obj1=tree.maxValueNode(tree.root);
	cout<<obj1->data;
	}
	else if(value==7)
	{
	cout<<"Minimum value:";
	TreeNode *obj2=tree.minValueNode(tree.root);
	cout<<obj2->data;
	}
	else
	{cout<<"Enter right option"<<endl;}
	cout<<endl;
}
}

