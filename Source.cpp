#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct node {
	string data;
	node *next;
	int peri;
	node() {
		data = "0";
		next = NULL;
		peri = 0;
	}
};
class periority {
private:
	int size;
	node *head;
	node *tail;
public:
	periority() {
		size = 0;
		head = NULL;
		tail = NULL;
	}
	void display();
	int sizes();
	bool remove();
	int highperi();
	string gethighperiEle();
	bool add(string, int);
	int search(string);
	bool searchcity(string, periority a);
};
void periority::display() {
	node *t = head;
	while (t != NULL) {
		std::cout << t->data << "/" << t->peri << " ";
		t = t->next;

	}


}
int periority::sizes() {

	return size;
}
bool periority::remove() {
	node *t = head;
	if (size > 0) {
		head = head->next;
		t->next = NULL;

		delete t;
		size--;
		return true;

	}
	else
		return false;

}
int periority::highperi() {

	node *t = head;
	if (size > 0) {
		return t->peri;

	}
	else
		return 0;

}
string periority::gethighperiEle() {
	//node *t = head;
	if (size > 0) {
		return head->data;

	}
	else
		return "0";

}
bool periority::add(string a, int p) {
	node *t = new node();

	t->data = a;
	t->peri = p;


	if (head == NULL) {
		head = t;
		tail = t;
		size++;
		return true;
	}
	else if (head->peri > p)
	{
		t->next = head;
		head = t;
		size++;
		return true;

	}
	else if (tail->peri <= p) {
		tail->next = t;
		tail = tail->next;
		size++;
		return true;
	}

	if (size > 0) {
		node *r, *q = head;
		r = q->next;
		node *s = new node();
		while (r != NULL) {
			if (r->peri <= p) {

				r->next = r;
				q->next = q;

			}
			else

				q->next = t;
			t->next = r;
			size++;
			return true;
		}
	}
	return false;

}
int periority::search(string s) {
	node *t = head;
	if (size > 0)
	{
		int r = 0;
		while (t != NULL) {
			if (t->data.compare(s) == 0)
			{
				return r;
			}
			t = t->next;
			r++;
		}
	}
	return -1;
}
bool periority::searchcity(string s, periority a) {
	node *t = a.head;
	while (t != NULL) {
		if (t->data.compare(s) == 0) {
			return true;
		}
		t = t->next;
	}
	return false;


}
void main() {
	periority a, p[5], q[5];

	p[0].add("Zoo Road", 4);
	p[0].add("under pass Road", 20);
	p[0].add("Wand Roas", 30);

	p[1].add("CBT Road", 20);
	p[1].add("Zoa Road", 19);
	p[1].add("Over head bridge way", 40);
	p[1].add("Zoo Road", 4);

	p[2].add("Link Road", 8);
	p[2].add("kaza Road", 6);
	p[2].add("under pass Road", 20);
	p[2].add("Zoa Road", 19);

	p[3].add("kaza Road", 6);
	p[3].add("Wand Roas", 30);
	p[3].add("Over head bridge way", 40);
	p[3].add("Ring Road", 4);

	p[4].add("Link road", 8);
	p[4].add("CBT", 20);
	p[4].add("Ring Road", 16);

	int j = 0, current = 0;

	while (j<5) {
		for (int i = j; i<5; i++) {
			if (p[current].searchcity(p[current].gethighperiEle(), p[i + 1])) {
				cout << p[current].gethighperiEle() << current << endl;
				current++;
			}
		}
		j++;
	}

	_getch();
}
