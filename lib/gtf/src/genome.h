#ifndef __GTF_FILE_H__
#define __GTF_FILE_H__

#include <string>
#include <map>
#include "gene.h"

using namespace std;

class genome
{
public:
	genome();
	genome(const string &file);
	~genome();

public:
	vector<gene> genes;
	map<string, int> s2i;

public:
	int add_gene(const gene &g);
	int read(const string &file);
	int write(const string &file) const;
	int sort();
	int build_index();
	const gene* get_gene(string name) const;
};

#endif