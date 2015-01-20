/*
 * =====================================================================================
 *
 *       Filename:  solver.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/01/2015 17:48:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#pragma once

#include "algorithmList.hpp"
#include "problemList.hpp"
#include <iostream>

namespace lslv {
    class Solver {
        public:
            inline Solver(Problem& problem, Algorithm& algo) : m_algo(algo), m_problem(problem) {}
            inline ~Solver() {}
            
            inline int solve(std::string const& data_filename){
		    std::cout << "bite" << std::endl; 
		    Node n = m_problem.initialNode(data_filename);
                return m_algo.solve(m_problem, n); 
            }

            inline void setAlgorithm(Algorithm& algo) { m_algo = algo; }

            inline void setProblem(Problem& problem) { m_problem = problem; }
        private:
            Algorithm& m_algo;
            Problem& m_problem;
    };
};
