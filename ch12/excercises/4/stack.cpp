#include "stack.h"
#include <cstring>

Stack::Stack(int n) {
	if (n > 0) {
		size = n;
		pitems = new Item[n];
	}
	else {
		size = 0;
		pitems = nullptr;
	}
	top = -1;
}

Stack::Stack(const Stack &st) {
	if(st.size > 0) {
		size = st.size;
		pitems = new Item[st.size];
		std::memcpy(pitems, st.pitems, ((unsigned int)(st.top + 1)) * sizeof(Item));
		top = st.top;
	} else {
		size = 0;
		pitems = nullptr;
		top = -1;
	}
}

Stack::~Stack() {
	if (pitems)
		delete []pitems;
}

bool Stack::isempty() const { return top <= -1; }

bool Stack::isfull() const { return top == size - 1;}

bool Stack::push(const Item &item) {
	if (isfull())
		return false;
	else {
		pitems[++top] = item;
		return true;
	}
}

bool Stack::pop(Item &item) {
	if (isempty())
		return false;
	else {
		item = pitems[top--];
		return true;
	}
}

Stack &Stack::operator=(const Stack &st) {
	if (&st == this)
		return *this;
	if (pitems)
		delete []pitems;
	size = st.size;
	pitems = new Item[st.size];
	std::memcpy(pitems, st.pitems, ((unsigned int)(st.top + 1)) * sizeof(Item));
	top = st.top;
	return *this;
}
