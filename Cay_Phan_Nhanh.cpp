#include<iostream>
using namespace std;

//ho ten: le nam dai an
// lop k59th

struct node
{
	int data; 
	struct node* pLeft; 
	struct node* pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;

void CreateTree(TREE& t)
{
	t = NULL;
}
void AddNodetoTree(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			AddNodetoTree(t->pLeft, x);
		}
		else if (t->data < x)
		{
			AddNodetoTree(t->pRight, x);
		}
	}
}

void Browser_NLR(TREE& t)
{
	if (t != NULL)
	{
		cout << t->data << " "; 
		Browser_NLR(t->pLeft);
		Browser_NLR(t->pRight);
	}
}

void Browser_LNR(TREE& t)
{
	if (t != NULL)
	{
		Browser_LNR(t->pLeft);
		cout << t->data << "  ";
		Browser_LNR(t->pRight);
	}
}

void Browser_LRN(TREE& t)
{
	if (t != NULL)
	{
		Browser_LRN(t->pLeft);
		Browser_LRN(t->pRight);
		cout << t->data << "  "; 
	}
}
NODE* Search(TREE t, int x)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (x < t->data)
		{
			Search(t->pLeft, x);
		}
		else if (x > t->data)
		{
			Search(t->pRight, x);
		}
		else 
		{
			return t;
		}
	}

}
void DeleteNode(TREE& t, int data) 
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (data < t->data)
		{
			DeleteNode(t->pLeft, data);
		}
		else if (data > t->data)
		{
			DeleteNode(t->pRight, data);
		}
		else
		{
			NODE* X = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			delete X;
		}
	}
}
void Menu(TREE& t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ";
		cout << "\n1. Insert information";
		cout << "\n2\tNLR\n\t\t\t";
		cout << "\n3\tLNR\n\t\t\t";
		cout << "\n4\tLRN\n\t\t\t";
		cout << "\n5\tSearch\n\t\t\t";
		cout << "\n6\tDeleteNOPE\n\t\t\t";
		cout << "\n0. Finish";
		cout << "\n\n\t\t ";

		int makechoice;

		cout << "\nEnter selection: ";
		cin >> makechoice;
		if (makechoice < 0 || makechoice > 6)
		{
			cout << "\nInvalid selection";
			system("pause");
		}
		else if (makechoice == 1)
		{
			int x;
			cout << "\nEnter an integer x: ";
			cin >> x;
			AddNodetoTree(t, x);
		}
		else if (makechoice == 2)
		{
			cout << "\n\t\t Browser_NLR\n";
			Browser_NLR(t);
			system("pause");
		}
		else if (makechoice == 3)
		{
			cout << "\n\t\t Browser_LNR\n";
			Browser_LNR(t);
			system("pause");
		}
		else if (makechoice == 4)
		{
			cout << "\n\t\t Browser_LRN\n";
			Browser_LRN(t);
			system("pause");
		}
		else if (makechoice == 5)
		{
			int x;
			cout << "\nEnter the element to search: ";
			cin >> x;
			NODE* p = Search(t, x);
			if (p == NULL)
			{
				cout << "\nMolecules " << x << " does not exist in the tree";
			}
			else
			{
				cout << "\nMolecules" << x << " exists in the tree";
			}
			system("pause");
		}
		else if (makechoice == 6)
		{
			int x;
			cout << "\nEnter the value to delete: ";
			cin >> x;
			DeleteNode(t, x);
		}
		else
		{
			break;
		}

	}

}
int main()
{
	TREE t;
	CreateTree(t);
	Menu(t);

	system("pause");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file