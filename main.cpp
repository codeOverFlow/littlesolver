/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2015 17:59:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */


#include <cstdlib>
#include <iostream>

#include "assignproblem.hpp"
#include "backtracking.hpp"

using namespace lslv;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    AssignProblem p;
    Backtracking b;
    Node node = p.initialNode("");
    std::cout << std::endl << "res: " << b.solve(p, node) << std::endl;
    /*/std::cout << node.dom().at(0).dom().at(0) << std::endl;
    node.dom().at(0).flip(0);
    std::cout << node.dom().at(0).dom().at(0) << std::endl;
    //*/
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
