#include<iostream>
#include<conio.h>
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

		if (x < t->data)
		{
			AddNodetoTree(t->pLeft, x);
		}
		else if (x > t->data)
		{
			AddNodetoTree(t->pRight, x);
		}
	}
}

/* void Browser_NLR(TREE& t)
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

}*
// xuất các node có 2 con
void Node_Co_2_Con(TREE t)
{
	if (t != NULL)
	{
		// xử lí
		if (t->pLeft != NULL && t->pRight != NULL) // con trái và con phải có tồn tại phần tử
		{
			cout << t->data << "  ";
		}
		Node_Co_2_Con(t->pLeft); // duyệt sang cây con trái của node hiện tại
		Node_Co_2_Con(t->pRight); // duyệt sang cây con phải của node hiện tại
	}
}
bool Check_Prime_Numbers(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		if (x == 2)
		{
			return true;
		}
		else
		{
			if (x % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < x; i++)
				{
					if (x % i == 0)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
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
}*/
// tim tat ca cac node co trong cay nhi phan tim kiem...
int AllNodeForTREE(TREE& t)
{
	if (t == NULL) return 0;
	else return(AllNodeForTREE(t->pRight) + AllNodeForTREE(t->pLeft)) + 1;
}

// Tong chan trong cay nhi phan tim kiem...
int SplitTatol(TREE& t)
{
	if (t != NULL)
	{
		int h = SplitTatol(t->pLeft);
		int k = SplitTatol(t->pRight);
		if (t->data % 2 == 0)
		{
			return  t->data + h + k;
		}
		else
		{
			return h + k;
		}
		return 0;
	}

}
// Tong le trong cay nhi phan tim kiem...
int RetailTotal(TREE& t)
{
	if (t != NULL)
	{
		int h = RetailTotal(t->pLeft);
		int k = RetailTotal(t->pRight);
		if (t->data % 2 != 0)
		{
			return t->data + h + k;
		}
		else
		{
			return h + k;
		}
		return 0;
	}
}
// Kiem tra so nguyen to trong cay...
bool CheckkPrimes(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		if (x == 2)
		{
			return true;
		}
		else
		{
			if (x % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < x; i++)
				{
					if (x % i == 0)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
// Dem so nguyen to co trong cay nhi phan ....
void NumberCoutPrimes(TREE t, int& Number)
{
	if (t != NULL)
	{
		if (CheckkPrimes(t->data) == true)
		{
			Number++;
		}
		// Duyet cac node ben trai..
		NumberCoutPrimes(t->pLeft, Number);
		// Duyet cac node ben phai...
		NumberCoutPrimes(t->pRight, Number);

	}
}
// Tinh tong cac so nguyen to da tim kiem
int SumNumberPrimes(TREE t, int& Sum)
{

	if (t != NULL)
	{
		int h = SumNumberPrimes(t->pLeft, Sum);
		int k = SumNumberPrimes(t->pRight, Sum);
		if (CheckkPrimes(t->data) == true)
		{
			return Sum = t->data + h + k;

		}
		else
		{
			return h + k;
		}
		return 0;
	}
}
void Menu(TREE& t)
{
	while (true)
	{
		system("cls");		
		cout << "\n\n\t\t ";
		cout << "\n1. Insert information";
		/*cout << "\n2\tNLR\n\t\t\t";
		cout << "\n3\tLNR\n\t\t\t";
		cout << "\n4\tLRN\n\t\t\t";
		cout << "\n5\tSearch\n\t\t\t";*/
		cout << "\n6. Node co 2 con";
		cout << "\n8. Dem so luong so nguyen to";
		cout << "\n7\tDeleteNOPE\n\t\t\t";
		cout << "\n9\ The number of molecules present in the binary tree is :";
		cout << "\n11\Sum of odd numbers in leaf trees :";
		cout << "\n12\The number of primes is :";
		cout << "\n13\tThe sum of prime numbers is: ";

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
		/*else if (makechoice == 2)
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
		}*/
		else if (makechoice == 9) {
			cout << "\n\t\t\t The number of molecules present in the binary tree is :" 
				<< AllNodeForTREE(t) << endl;
			cout << "\n\t\t\t Node co hai con la:";
			system("pause");
		}

		else if (makechoice == 11) {
			cout << "\n\t\t\t Sum of odd numbers in leaf trees:"
				<< RetailTotal(t);
			RetailTotal(t);
		}
		else if (makechoice == 12) {
			int Number = 0;
			NumberCoutPrimes(t, Number);
			cout << "\n\t\t\t The number of primes is :" << Number;
			system("pause");
		}
		else if (makechoice == 13) {
			int Sum = 0;
			SumNumberPrimes(t, Sum);
			cout << "\n\t\t\t The sum of prime numbers is: " << Sum;
			system("pause");
		}
		/*else if (makechoice == 7)
		{
			int x;
			cout << "\nEnter the value to delete: ";
			cin >> x;
			DeleteNode(t, x);
		}
		else if (makechoice == 7) {
		}*/
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