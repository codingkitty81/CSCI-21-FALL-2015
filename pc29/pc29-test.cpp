/* 
 * Unit test for Programming Challenge 29
 * This test exercises the programmers knowledge and understanding of the 
 * STL.
 *
 * Katherine Jouzapaitis
 * Date created: 12/7/2015
 * Date last modified:
 * 
 * NOTES
 *
 * need to add std=c++11 to compiler flags
 * add code for each numbered item in each of the unit tests
 * comment out TEST_CASEs as need to build in increments
 *
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <utility> // pair
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#include <sstream>

using namespace std;

TEST_CASE ("STL pair") {
	// 1. Declare a <int,string> pair named m_pair, first=1, second="apple"
	pair<int, string> m_pair (1, "apple");

	// 2. Retrieve first data element
	CHECK(m_pair.first == 1);

	// 3. Retrieve second data element
	CHECK(m_pair.second == "apple");
}

TEST_CASE ("STL sequence containers") {
	// ARRAY //
	// 1. Declare a std::array of integer, size 10, named m_array
	vector<int> m_array (10);

	// 2. Use size function
	CHECK(m_array.size() == 10);

	// 3. Use fill function to fill array with 1
	m_array.assign(10, 1);

	for (unsigned int i=0; i<m_array.size(); i++) {
		// 4. Use operator[]
		CHECK(m_array[i] == 1);
	}

	// 5. Use fill function to fill array with 5
	m_array.assign(10, 5);

	// 6. Use foreach style loop to iterate
	for (auto i : m_array) {
		CHECK(i == 5);
	}

	// VECTOR //
	// 7. Declare a std::vector of string named m_vector
	deque<string> m_vector;

	// 8. Use size function
	CHECK(m_vector.size() == 0);

	// 9. Use empty function
	CHECK(m_vector.empty());

	// 10. Use push_back function to append "apple", "banana", "orange" to m_vector
	m_vector.push_back("apple");
	m_vector.push_back("banana");
	m_vector.push_back("orange");

	// 11. Use size function
	CHECK(m_vector.size()== 3);

	// 12. Use insert function to insert "grape" in front of "orange"
	m_vector.insert(m_vector.end() - 1, "grape");

	// 13. Use operator[]
	CHECK(m_vector[2] == "grape");

	// 14. Use erase function to erase "banana"
	m_vector.erase(m_vector.begin() + 1);

	// 15. Use size function
	CHECK(m_vector.size() == 3);

	// 16. Use operator[]
	CHECK(m_vector[0] == "apple");
	CHECK(m_vector[1] == "grape");
	CHECK(m_vector[2] == "orange");

	// 17. Iterate using vector<string>::iterator
	stringstream ss;
	for (deque<string>::iterator i = m_vector.begin(); i != m_vector.end(); ++i) {
		ss << *i << ' ';
	}
	CHECK(ss.str() == "apple grape orange ");

	// 18. Use clear function
	m_vector.clear();
	
	// 19. Use size function
	CHECK(m_vector.size() == 0);
}

TEST_CASE ("STL sequence container with pair") {
	// 1. Declare a std::vector of std::pair<string,float> named m_vector
	deque<pair<string, float> > m_vector;

	// 2. Use push_back to add pair "exam 1" = 98.5f
	m_vector.push_back(make_pair("exam 1", 98.5f));

	// 3. Use vector operator[] and pair first/second
	CHECK(get<0>(m_vector[0]) == "exam 1");
	CHECK(get<1>(m_vector[0]) == 98.5f);

	// 4. Use push_back to add pairs "exam 2" = 82.0f, "exam 3" = 92.5f
	m_vector.push_back(make_pair("exam 2", 82.0f));
	m_vector.push_back(make_pair("exam 3", 92.5f));

	// 5. Use vector size function
	CHECK(m_vector.size() == 3);

	// 6. Iterate using vector<pair<string, float> >::iterator and pair first/second
	stringstream ss;
	for (auto i : m_vector) {
		ss << i.first << ',' << i.second << ' ';
	}
	CHECK(ss.str() == "exam 1,98.5 exam 2,82 exam 3,92.5 ");
}

TEST_CASE ("STL container adaptors") {
	// STACK //
	// 1. Declare a std::stack of char named m_stack
	stack<char> m_stack;

	// 2. Use size function
	CHECK(m_stack.size() == 0);

	// 3. Use empty function
	CHECK(m_stack.empty());

	// 4. Use for loop to push chars from string s onto stack
	string s("hello");
	for (unsigned int i = 0; i < s.length(); i++) {
		m_stack.push(s[i]);
	}

	// 5. Use size function
	CHECK(m_stack.size() == 5);

	// 6. Use top function
	CHECK(m_stack.top() == 'o');

	// 7. Use pop function
	m_stack.pop();

	// 8. Use size function
	CHECK(m_stack.size() == 4);

	// 9. Use top function
	CHECK(m_stack.top() == 'l');

	// 10. Use while loop, empty function, and pop function to clear m_stack
	while (!m_stack.empty()) {
		m_stack.pop();
	}

	// 11. Use size function
	CHECK(m_stack.size() == 0);

	// QUEUE //
	// 12. Declare a std::queue of char named m_queue
	queue<char> m_queue;

	// 13. Use size function
	CHECK(m_queue.size() == 0);

	// 14. Use empty function
	CHECK(m_queue.empty());

	// 15. Use for loop to push chars from string s onto queue
	for (unsigned int i = 0; i < s.length(); i++) {
		m_queue.push(s[i]);
	}

	// 16. Use size function
	CHECK(m_queue.size() == 5);

	// 17. Use front function
	CHECK(m_queue.front() == 'h');

	// 18. Use back function
	CHECK(m_queue.back() == 'o');

	// 19. Use pop function
	m_queue.pop();

	// 20. Use front function
	CHECK(m_queue.front() == 'e');

	// 21. Use size function
	CHECK(m_queue.size() == 4);

	// 22. Use while loop, empty function, and pop function to clear m_queue
	while (!m_queue.empty()) {
		m_queue.pop();
	}

	// 23. Use size function
	CHECK(m_queue.size() == 0);
}

TEST_CASE ("STL associative containers") {
	// MAP //
	// 1. Declare a std::map of <string,int> named m_map
	map<string, int> m_map;

	// 2. Use size function
	CHECK(m_map.size() == 0);

	// 3. Use empty function
	CHECK(m_map.empty());

	// 4. Use operator[] to add "apples" = 3 to m_map
	m_map["apples"] = 3;

	// 5. Use operator[]
	CHECK(m_map["apples"] == 3);

	// 6. Use operator[] to add "bananas" = 2, "oranges" = 1 to m_map
	m_map["bananas"] = 2;
	m_map["oranges"] = 1;

	// 7. Use size function
	CHECK(m_map.size() == 3);

	// 8. Use operator[]
	CHECK(m_map["bananas"] == 2);
	CHECK(m_map["oranges"] == 1);

	// 9. Iterate using map<string, int>::iterator, and first/second
	stringstream ss;
	for (map<string, int>::iterator i = m_map.begin(); i != m_map.end(); ++i) {
		ss << i->first << ',' << i->second << ' ';
	}
	CHECK(ss.str() == "apples,3 bananas,2 oranges,1 ");

	// 10. Use erase function to erase "bananas"
	m_map.erase("bananas");

	// 11. Use size function
	CHECK(m_map.size() == 2);

	// 12. Iterate using map<string, int>::iterator, and first/second
	ss.str("");
	for (map<string, int>::iterator i = m_map.begin(); i != m_map.end(); ++i) {
		ss << i->first << ',' << i->second << ' ';
	}
	CHECK(ss.str() == "apples,3 oranges,1 ");	

	// 13. Use clear function
	m_map.clear();

	// 14. Use size function
	CHECK(m_map.size() == 0);

	// 15. Use empty function
	CHECK(m_map.empty());
}
