#include "CTokenize.h"
using namespace std;

CTokenize::CTokenize()
{
}

CTokenize::~CTokenize()
{
}

void CTokenize::tokenizar(string const& str, const char delim, vector<string>& out) //Complejidad: O(n)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}
