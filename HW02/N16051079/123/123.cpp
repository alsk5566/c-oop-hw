<<<<<<< HEAD
// 123.cpp : 定義主控台應用程式的進入點。
//

#include"stdafx.h"
#include <iostream>
#include <string>


using namespace std;


struct Node
{
	int data;
	Node *L, *R;
};

void showTree(Node *mover)
{

	if (mover != NULL)
	{
		showTree(mover->L);
		cout << mover->data << endl;
		showTree(mover->R);
	}
}

int main()
{
	Node *root = new Node(), *mover = root;
	cout << "輸入樹根的值:" << endl;
	cin >> root->data;

	root->L = NULL;
	root->R = NULL;

	int pData;
	while (cout << "請輸入:\n", cin >> pData)
	{
		bool end = false;
		mover = root;
		while (!end)
		{
			if (pData > mover->data)
			{
				if (mover->R == NULL)
				{
					mover->R = new Node();
					end = true;
				}
				mover = mover->R;
			}
			else
			{
				if (mover->L == NULL)
				{
					mover->L = new Node();
					end = true;
				}
				mover = mover->L;
			}
		}
		mover->data = pData;

		cout << "\n中序走訪:\n\n";
		showTree(root);
	}
	system("pause");
}

=======
// 123.cpp : 定義主控台應用程式的進入點。
//

#include"stdafx.h"
#include <iostream>
#include <string>
using namespace std;


struct Node
{
	int data;
	Node *L, *R;
};

void showTree(Node *mover)
{

	if (mover != NULL)
	{
		showTree(mover->L);
		cout << mover->data << endl;
		showTree(mover->R);
	}
}

int main()
{
	Node *root = new Node(), *mover = root;
	cout << "輸入樹根的值:" << endl;
	cin >> root->data;

	root->L = NULL;
	root->R = NULL;

	int pData;
	while (cout << "請輸入:\n", cin >> pData)
	{
		bool end = false;
		mover = root;
		while (!end)
		{
			if (pData > mover->data)
			{
				if (mover->R == NULL)
				{
					mover->R = new Node();
					end = true;
				}
				mover = mover->R;
			}
			else
			{
				if (mover->L == NULL)
				{
					mover->L = new Node();
					end = true;
				}
				mover = mover->L;
			}
		}
		mover->data = pData;

		cout << "\n中序走訪:\n\n";
		showTree(root);
	}
	system("pause");
}

>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808
