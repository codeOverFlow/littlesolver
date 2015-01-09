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

#include "algorithm.hpp"

namespace lslv {
    class Solver {
        public:
            Solver(Algorithm algo, Problem problem) : m_algo(algo), m_problem(problemlist)
            ~Solver() {}
            
            void solve(){
                // TODO: implements it
            }

            void setAlgorithm(Algorithm algo) { m_algo = algo; }

            void setProblem(Problem problem) { m_problem = problem; }
        private:
            Algorithm m_algo;
            Problem m_problem;
    };
};
