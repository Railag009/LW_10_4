#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct Dlist
{

	int info;
	Dlist* next, * prev;

};


int main()
{

	Dlist* head, * p, * r;
	int x, k, y;
	int max, i, j, a, b, c;
	float sr;

	cout << "Enter number - ";
	cin >> a;
	cout << endl;

	head = new Dlist;
	cin >> x;
	head->info = x;
	head->next = NULL;
	head->prev = NULL;
	p = head;

	b = 0;
	c = 0;
	k = 0;

	cin >> x;
	while (x)
	{
		
		r = new Dlist;
		r->info = x;
		r->next = NULL;
		r->prev = p;
		p->next = r;
		p = r;
		cin >> x;
				
	}

	p = head;

	while (p != NULL)
	{

		k = p->info;
		i = 0;
		while (k > 0)
		{
			if (k % 10 == a) i++;
			k /= 10;
		}

		if (i != 0) b++;

		k = p->info;
		y = 0;
		while (k > 0)
		{
			y++;
			k /= 10;
		}

		if (y % 2 == 0) c++;

		p = p->next;
	}

	if (b >= 3)
	{
		p = head->next;

		while (p != NULL)
		{
			j = 1;
			sr = 0;
			while (j < p->prev->info)
			{

				if (p->prev->info % j == 0) sr += j;
				j++;

			}

			if (p->prev->info == sr)
			{

				r = p;
				p->prev->next = r->next;
				p->next->prev = p->prev;
				p = p->next;
				delete r;
				p = p->next;

			}
			else
			{
				p = p->next;
			}

		}

	}
	else
	{
		p = head->next;

		while (p != NULL)
		{

			if (p->info % 2 != 0)
			{

				r = new Dlist;
				r->info = c;
				r->next = p->next;
				r->prev = p;
				p->next = r;
				p = r;

			}

			p = p->next;

		}

		p = head;

		if (p->info % 2 != 0)
		{

			r = new Dlist;
			r->info = c;
			r->next = p->next;
			r->prev = p;
			p->next = r;
			p = r;

		}

	}

	p = head;

	while (p != NULL)
	{

		cout << p->info << setw(3);
		p = p->next;
	}

}