/*
 * =====================================================================================
 *
 *       Filename:  algorithm.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2015 12:41:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#pragma once

#include "problem.hpp"

namespace lslv {
    class Algorithm {
        public:
            virtual int solve(Problem& p, Node& node) = 0;
        protected:
            virtual void branch(Problem& p, Node& node, std::vector<int> assignment, int& cpt, std::vector<int> not_assigned) = 0;
    };
}
