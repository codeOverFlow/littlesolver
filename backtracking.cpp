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
		std::vector<int> not_assigned, assignment(node.dom().size(), -1);
		p.printDomains(node);
		for (int i(0); i < node.dom().size(); i++)
			not_assigned.push_back(i);
		int res = backtracking(p, node, cpt, assignment, not_assigned);
		std::cout << "Solution(s) explored with " << nb_nodes << " node(s)" << std::endl;
		if (res == 0)
			std::cout << "No solution found for those domains" << std::endl;
		return res;
	}
}

int Backtracking::backtracking(Problem& p, Node& node, int& cpt, std::vector<int> assignment, std::vector<int> not_assigned) {
	if (not_assigned.size() != 0)
		branch(p, node, assignment, cpt, not_assigned);
	
	return cpt;
}

void Backtracking::branch(Problem& p, Node& node, std::vector<int> assignment, int& cpt, std::vector<int> not_assigned) {
	int d;
	int min_size(node.dom().at(0).dom().size());

	for (auto i : not_assigned) {
		if (node.dom().at(i).positive_bits() < min_size) {
			d = i;
			min_size = node.dom().at(i).positive_bits();
		}
	}


	std::vector<int> tmp;
	//std::cout << "not_assigned: ";
	for (auto i : not_assigned) {
		//std::cout << i << "   ";
		if (i != d)
			tmp.push_back(i);
	}
	//std::cout << std::endl << std::endl;
	not_assigned  = tmp;

	for (int i(0); i < node.dom().at(d).dom().size(); i++) {
		if (node.dom().at(d).dom().at(i)) {
			// push the new assignment
			assignment.at(d) = i+1;
			//p.printSolution(assignment);
			Proof proof = p.testSat(assignment, node.dom().size());
			if (proof == Proof::MIDDLE) {
				nb_nodes++;
				//p.printSolution(assignment);
				backtracking(p, node, cpt, assignment, not_assigned);
				assignment.at(d) = -1;
			}
			else if (proof == Proof::SUCCESS) {
				cpt++;
				nb_nodes++;
				//p.printDomains(node);
				//p.printSolution(assignment);
				//std::cout << std::endl;
			}
			else {
				assignment.at(d) = -1;
			}
		}
	}
}
