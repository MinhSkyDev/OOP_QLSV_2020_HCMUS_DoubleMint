#include "Function.h"

string normalizeString(string inp) {
	// Vi du:
	// input: ' asd  123 456  '
	// Output: 'asd 123 456'
	for (unsigned int i = 0; i < inp.size(); i++)
		inp[i] = toupper(inp[i]);
	while (inp[0] == ' ')
		inp.erase(0, 1);
	while (inp[inp.size() - 1] == ' ')
		inp.erase(inp.size() - 1, 1);
	return inp;
}
