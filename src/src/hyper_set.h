#ifndef __HYPER_SET_H__
#define __HYPER_SET_H__

#include <map>
#include <set>
#include <vector>

#include "util.h"
#include "directed_graph.h"

using namespace std;

typedef pair<vector<int>, int> PVII;
typedef map<vector<int>, int> MVII;
typedef map< int, set<int> > MISI;
typedef pair< int, set<int> > PISI;
typedef vector< vector<int> > VVI;

class hyper_set
{
public:
	MVII nodes;			// hyper-edges using list-of-nodes
	VVI edges;			// hyper-edges using list-of-edges
	MISI e2s;			// index: from edge to hyper-edges

public:
	int clear();
	int add_node_list(const set<int> &s);
	int build(directed_graph &gr, MEI &e2i);
	int build_edges(directed_graph &gr, MEI &e2i);
	int build_index();
	set<int> get_intersection(const vector<int> &v);
	set<int> get_successors(int e);
	vector<PI> get_routes(int x, directed_graph &gr, MEI &e2i);
	int purify();
	int print();

public:
	int replace(int x, int y, int e);
	int replace(const vector<int> &x, int e);
	int remove(int e);
	int remove(const vector<int> &x);
};

#endif