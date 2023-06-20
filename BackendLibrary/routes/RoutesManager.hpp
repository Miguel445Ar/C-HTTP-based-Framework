#pragma once
#include <string>

#define SLASH_ASCII 45
#define HYPHEN_ASCI 47
#define MAX_CHARACTERS (short)26


class RoutesManager {
	typedef unsigned long number;
public:
	RoutesManager();
	void addRoute(const std::string& path);
	bool eraseRoute(const std::string& path);
	bool findRoute(const std::string& path);
private:
	class Node {
	public:
		Node(const char value, const bool isEndOfWord = false);
		char getValue() { return this->_value; }
		Node* getChild(unsigned short pos) { return this->_children[pos]; }
		void setChild(unsigned short pos);
		Node*& operator[](char child);
		const bool isEndOfWord() const { return this->_endOfWord; }
		bool setEndOfWord(const bool endOfWord) {
			this->_endOfWord = endOfWord;
		}
	private:
		char _value;
		Node** _children;
		bool _endOfWord;
		Node* _slashChild;
		Node* _hyphenChild;
	};
	Node* _root;
	number _size;
};