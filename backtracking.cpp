/*
	* =====================================================================================
	*
	*       Filename:  backtracking.cpp
	*
	*    Description:  
	*
	*        Version:  1.0
	*        Created:  08/01/2015 16:15:11
	*       Revision:  none
	*       Compiler:  gcc
	*
	*         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
	*   Organization:  FH Südwestfalen, Iserlohn
	*
	* =====================================================================================
	*/

#include "backtracking.hpp"
#include <iostream>

using namespace lslv;

Backtracking::Backtracking()
:nb_nodes(0){}
Backtracking::~Backtracking() {}

int Backtracking::solve(Problem& p, Node& node) {
	bool is_empty (false);
	for (Domain d : node.dom()) {
		if (d.positive_bits() == 0) {
			is_empty = true;
			break;
		}
	}
	
	if (is_empty) {
		std::cout << "No solution due to an empty domain" << std::endl;
		return 0;
	}
	else {
		int cpt(0);
		nb_nodes = 0;
		int res = backtracking(p, node, cpt);
		std::cout << "Solution(s) explored with " << nb_nodes << " node(s)" << std::endl;
		if (res == 0)
			std::cout << "No solution found for those domains" << std::endl;
		return res;
	}
}

int Backtracking::backtracking(Problem& p, Node& node, int& cpt, std::vector<int> assignment, int num_dom) {
	if (assignment.size() != node.dom().size())
		branch(p, node, assignment, cpt, num_dom);
	
	return cpt;
}

void Backtracking::branch(Problem& p, Node& node, std::vector<int> assignment, int& cpt, int num_dom) {
	int d(num_dom);
	for (int i(0); i < node.dom().at(d).dom().size(); i++) {
		if (node.dom().at(d).dom().at(i)) {
			nb_nodes++;
			// push the new assignment
			if (assignment.size() > num_dom)
				assignment.at(num_dom) = i;
			else
				assignment.push_back(i);
			
			Proof proof = p.testSat(assignment, node.dom().size());
			if (proof == Proof::MIDDLE) {
				backtracking(p, node, cpt, assignment, num_dom+1);
				assignment.pop_back();
			}
			else if (proof == Proof::SUCCESS) {
				cpt++;
				p.printDomains(node);
				p.printSolution(assignment);
				std::cout << std::endl;
			}
			else {
				assignment.pop_back();
			}
		}
	}
}
