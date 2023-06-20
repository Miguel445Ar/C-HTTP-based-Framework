#include "RoutesManager.hpp"
#include <stack>

RoutesManager::RoutesManager()
{
	this->_root = new Node('.');
	this->_size = 0;
}
void RoutesManager::addRoute(const std::string& path)
{
	Node* current = this->_root;
	uint32_t lastIndex = path.length() - 1;
	for (uint32_t i = 0; i < path.length(); ++i) {
		Node*& child = (*current)[path[i]];
		if (child && i == lastIndex && child->isEndOfWord()) throw "\nRoute already exists\n";
		if (child && i == lastIndex) child->setEndOfWord(true);
		else child = new Node(path[i], i == lastIndex);
		current = child;
	}
	current = nullptr;
}
bool RoutesManager::eraseRoute(const std::string& path)
{
	using std::stack;
	
	return false;
}
bool RoutesManager::findRoute(const std::string& path)
{
	Node* current = this->_root;
	uint32_t lastIndex = path.length() - 1;
	for (uint32_t i = 0; i < path.length(); ++i) {
		Node*& child = (*current)[path[i]];
		if (child && i == lastIndex && child->isEndOfWord()) return true;
		if (child && i == lastIndex) return false;
		if (!child) return false;
		current = child;
	}
	current = nullptr;
}

RoutesManager::Node::Node(const char value, const bool isEndOfWord)
{
	this->_value = value;
	this->_endOfWord = isEndOfWord;
	this->_children = new Node * [MAX_CHARACTERS];
	for (unsigned short i = 0; i < MAX_CHARACTERS; ++i) this->_children[i] = nullptr;
	this->_slashChild = this->_hyphenChild = nullptr;
}

void RoutesManager::Node::setChild(unsigned short pos)
{

}

RoutesManager::Node*& RoutesManager::Node::operator[](char child) {
	if (child == '/') return this->_slashChild;
	if (child == '-') return this->_hyphenChild;
	uint32_t begin = static_cast<uint32_t>('A');
	uint32_t pos = static_cast<uint32_t>(child) - begin;
	return this->_children[pos];
}
