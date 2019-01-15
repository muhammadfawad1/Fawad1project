#include <iostream>
using namespace std;
template <typename _QW>
class stake_X
{
	int size_X, fo_I_X, Ba_I_X;
	_QW *_storage;
public:
	stake_X(int size = 10)
	{
		size_X = size;
		_storage = new _QW[size_X];
		fo_I_X = 0;
		Ba_I_X = 0;
	}
	bool is_empty()
	{
		if (fo_I_X == Ba_I_X)
			return true;
		return false;
	}
	bool is_full()
	{
		if (Ba_I_X == size_X)
			return true;
		return false;
	}
	void PUSH_Val_X(_QW ELE_X)
	{
		if (!is_full())
		{
			_storage[Ba_I_X] = ELE_X;
			Ba_I_X++;
		}
		else
		{
			cout << "\nit is full can't push\n";
		}
	}
	_QW POP_Val_X()
	{
		if (!is_empty())
		{
			Ba_I_X--;
			return _storage[Ba_I_X];
		}
		else
		{
			cout << "\nit is empty can't pop\n";
		}
	}
	_QW give_Top()
	{
		return _storage[Ba_I_X - 1];
	}
	void display()
	{
		for (int i = 0; i < Ba_I_X; i++)
		{
			cout << "\n| " << _storage[i] << " |\n";
			cout << "-----";

		}
	}
	
	~stake_X()
	{
		delete[] _storage;
	}
};
template <typename XX>
class quee
{
	XX *_stor;
	int _size, Fo_po, Ba_po, _count;
public:
	quee(int si)
	{
		_size = si;
		_stor = new XX[_size];
		Fo_po = 0;
		Ba_po = 0;
		_count = 0;
	}
	bool is_emp()
	{
		if (_count == 0)
			return true;
		return false;
	}
	bool is_full()
	{
		if (_count >= _size)
			return true;
		return false;
	}
	void enquee(XX ele)
	{
		if (!is_full())
		{
			_stor[Ba_po] = ele;
			_count++;
			Ba_po = (Ba_po + 1) % _size;
		}
		else cout << "\nit is full\n";
	}
	XX dequee()
	{
		if (!is_emp())
		{
			Fo_po = (Fo_po + 1) % _size;
			_count--;
			return _stor[Fo_po - 1];
		}
		else
		{
			cout << "\nit is empty garbage val : ";
			return _stor[Fo_po - 1];
		}
	}
	void show()
	{
		int y = _count;
		int x = Fo_po;
		while (y)
		{
			y--;
			cout << "\n| " << _stor[x] << " |\n";
			cout << "-----";
			x = (x + 1) % _size;
		}	
	}
	~quee()
	{
		delete[] _stor;
	}

private:

};
void Reverse(quee <int> & que1,stake_X<int> & Stak1)
{
	for (int i = 0; !Stak1.is_empty(); i++)
	{
		que1.enquee(Stak1.POP_Val_X());
	}
}
int main()
{
	stake_X<int> Stak1(10);
	quee<int> que1(10);
	for (int i = 1; i < 11; i++)
		Stak1.PUSH_Val_X(i*20);
	Stak1.display();
	cout << "\n";
	cout << endl;
	Reverse(que1, Stak1);
	cout << "\n";
	que1.show();
	cout << "\n";
	system("pause");

}
