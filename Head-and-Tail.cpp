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
		q = end;
		r = p;

	}

	void push(int x)
	{

		if ((q > end) || (p == (q + 1)))
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
				q++;
				*q = x;
			}
		}

	}

	int pop() {

		int tmp{-1};

		if ((p + 1) == q)
		{
			p++;
			cout << "TA VACIO\n";
		}
		else {
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

		if (p > q)
		{
			r = p;
			
			while (true)
			{

				cout << *r << " ";
				r++;

				if (r == end)
				{
					r = start;
				}

				if ( r == q)
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

	int A[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};


	headtail arr(A, 10);

	arr.printA();

	arr.pop();
	arr.pop();
	arr.pop();
	arr.printA();
	arr.pop();
	arr.printA();
	arr.pop();
	arr.printA();
	arr.pop();
	arr.printA();

	arr.push(1);
	arr.push(12);
	arr.push(2);
	arr.push(2);
	arr.printA();

	arr.push(2);
	arr.printA();

	arr.push(2);
	arr.printA();

	arr.push(2);
	arr.push(2);

	arr.printA();

	cout << "a";


}