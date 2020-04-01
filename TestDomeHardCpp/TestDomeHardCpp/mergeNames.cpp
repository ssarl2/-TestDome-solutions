#include <iostream>
#include <vector>
#include <set>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
	std::set<std::string> st;
	for (size_t i = 0; i < names1.size(); i++)
	{
		st.insert(st.end(), names1.at[i]);
	}
	for (size_t i = 0; i < names2.size(); i++)
	{
		st.insert(names2[i]);
	}
	std::vector<std::string> result;
	for (auto element : st) {
		result.insert(result.end(), element);
	}
	return result;
}

#ifndef RunTests
int main()
{
	std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
	std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };

	std::vector<std::string> result = unique_names(names1, names2);
	for (auto element : result)
	{
		std::cout << element << ' '; // should print Ava Emma Olivia Sophia
	}
}
#endif