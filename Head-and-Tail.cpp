#include <iostream>

using namespace std;

class headtail
{
public:
	int* start;
	int* end;
	int* p;
	int* q;
	int* r; // solo para imprimir

	headtail(int A[], int size)
	{

		start = A;
		end = A + size;
		p = start;
		q = start;
		r = p;

	}

	void push(int x)
	{

		if ((((q + 1) > end) && (start == p)) || (p == (q + 1)))
		{
			cout << "TAMOS LLENOS\n";
		}
		else
		{
			if (q == end)
			{
				q = start;
				*q = x;
			}
			else {
				*q = x;
				q++;
			}
		}

	}

	int pop() {

		int tmp{ -1 };


		if (p == q)
		{
			cout << "TA VACIO\n";
		}
		else
		{
			if ((p + 1) > end)
			{
				tmp = *p;
				p = start;
			}
			else {
				tmp = *p;
				p++;
			}
		}

		return tmp;
	}

	void printA()
	{
		if (p == q)
		{
			r = p;
			cout << "VACIO";
		}

		if (p > q)
		{
			r = q;

			while (true)
			{

				cout << *r << " ";
				r++;

				if (r == end)
				{
					r = start;
				}

				if (r == q)
				{
					cout << *r << " ";
					break;
				}

			}

		}
		else
		{
			r = p;

			for (; r < q; r++)
			{
				cout << *r << " ";
			}
		}

		r = p;

		cout << endl;
	}

	~headtail()
	{
		start = nullptr;
		end = nullptr;
		p = nullptr;
		q = nullptr;
		r = nullptr;

	}

private:

};


int main() {

	int A[10]{  };

	headtail arr(A, 10);

	for (int i{ 1 }; i < 15; i++) 
	{
		arr.push(i);
	}

	arr.printA();

	for (int i{ 1 }; i < 15; i++) 
	{
		arr.pop();
	}


	for (int i{ 1 }; i < 8; i++) 
	{
		arr.push(i);
	}


	for (int i{ 1 }; i < 4; i++) 
	{
		arr.pop();
	}
	arr.printA();


	for (int i{ 0 }; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";


	for (int i{ 1 }; i < 11; i++) 
	{
		arr.push(i);
	}
	arr.printA();


	for (int i{ 1 }; i < 13; i++) 
	{
		arr.pop();
	}


}
