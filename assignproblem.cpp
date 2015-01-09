/*
 * =====================================================================================
 *
 *       Filename:  assignproblem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2015 16:01:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include "assignproblem.hpp"

using namespace lslv;

AssignProblem::AssignProblem() {}

AssignProblem::~AssignProblem() {}

Node AssignProblem::initialNode(std::string const& filename) const {
    Node root(5,4);
    root.addDom(Domain(5, {true, false, false, false, false}));
    root.addDom(Domain(5, {false, true, false, false, false}));
    root.addDom(Domain(5, {false, false, true, false, false}));
    root.addDom(Domain(5, {false, false, false, true, false}));
    return root;
}

Proof AssignProblem::testSat(std::vector<int> const& assign, int n) const {
    Proof sat = Proof::MIDDLE;
    while (sat == Proof::MIDDLE) {
        if (all_assign(assign, n) && all_diff(assign))
            sat = Proof::SUCCESS;
        else if (!all_diff(assign))
            sat = Proof::FAILURE;
    }
    return sat;
}
