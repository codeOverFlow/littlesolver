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

using namespace lslv;

Backtracking::Backtracking() {}
Backtracking::~Backtracking() {}

int Backtracking::solve(Problem& p, Node& node) {
    return backtracking(p, node);
}

int Backtracking::backtracking(Problem& p, Node& node, std::vector<int> assignment, int i, int cpt) {
    if (i == node.dom().size()-1) {
        p.printSolution(assignment);
        return cpt;
    }
    else
        branch(p, node, assignment, cpt);
}

void Backtracking::branch(Problem& p, Node& node, std::vector<int>& assignment, int cpt) {
    for (Domain d : node.dom()) {
        for (int i(0); i < d.dom().size(); i++) {
            if (d.dom().at(i)) {
                assignment.push_back(i);
                Proof proof = p.testSat(assignment, node.dom().size());
                if (proof == Proof::MIDDLE)
                    backtracking(p, node, assignment, i++, cpt);
                else if (proof == Proof::SUCCESS)
                    backtracking(p, node, assignment, i++, cpt++);
                else
                    assignment.pop_back();
            }
        }
    }
}
