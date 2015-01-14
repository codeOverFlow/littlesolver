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

Backtracking::Backtracking() {}
Backtracking::~Backtracking() {}

int Backtracking::solve(Problem& p, Node& node) {
    int sum(0);
    for (Domain d : node.dom()) {
        sum += d.positive_bits();
    }

    if (sum == node.dom().size()) {
        p.printSolution(node);
        return 1;
    }
    else {
        int cpt(0);
        int nb_iter(0);
        return backtracking(p, node, cpt);
    }
}

int Backtracking::backtracking(Problem& p, Node& node, int& cpt, std::vector<int> assignment, int num_dom) {
    if (assignment.size() == node.dom().size()) {
        std::cout << "retour" << std::endl;
        //p.printSolution(assignment);
    }
    else {
        std::cout << "branch" << std::endl;
        branch(p, node, assignment, cpt, num_dom);
    }
    return cpt;
}

int nb_nodes(0); // count the number of nodes

void Backtracking::branch(Problem& p, Node& node, std::vector<int> assignment, int& cpt, int num_dom) {
    //for (int d(nb_iter); d < node.dom().size(); d++) {
    int d(num_dom);
    if (assignment.size() > d)
        assignment.pop_back();
  
    std::cout << "num_dom: " << num_dom << std::endl;

    for (int i(0); i < node.dom().at(d).dom().size(); i++) {
        std::cout << "cpt: " << cpt << std::endl;
        if (node.dom().at(d).dom().at(i)) {
            std::cout << "node number: " << nb_nodes++ << std::endl;
            p.printSolution(node);
            std::cout << "domain: " << d << std::endl;
            std::cout << "push_back: " << i << std::endl;
            // push the new assignment
            if (assignment.size() > num_dom)
                assignment.at(num_dom) = i;
            else
                assignment.push_back(i);
            //node.dom().at(d).flip(i);
            p.printSolution(node);
            std::cout << "test sat" << std::endl;
            Proof proof = p.testSat(assignment, node.dom().size());
            if (proof == Proof::MIDDLE) {
                std::cout << "middle node" << std::endl;
                p.printSolution(assignment);
                std::cout << std::endl << std::endl;

                backtracking(p, node, cpt, assignment, ++num_dom);
                //break;
                //node.dom().at(d).flip(i);
                assignment.pop_back();
            }
            else if (proof == Proof::SUCCESS) {
                std::cout << "success node" << std::endl;
                cpt++;
                //nb_iter++;
                p.printSolution(assignment);
                std::cout << std:: endl << std::endl;
                //assignment.clear();
                //d = node.dom().size();
                //backtracking(p, node, cpt, 0, assignment);
                //node.dom().at(d).flip(i);
                break;
            }
            else {
                std::cout << "pop_back: " << assignment.at(assignment.size()-1) << std::endl;
                std::cout << "failure node" << std::endl << std::endl << std::endl;
                std::cout << assignment.size() << std::endl;
                assignment.pop_back();
                std::cout << assignment.size() << std::endl << std::endl << std::endl;
                //node.dom().at(d).flip(i);
            }
        }
    }
    //}
}
