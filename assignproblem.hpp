/*
 * =====================================================================================
 *
 *       Filename:  queens.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2015 18:17:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

#include "problem.hpp"

namespace lslv {
    class AssignProblem : public Problem {
        public:
            AssignProblem();
            ~AssignProblem();

            virtual Node initialNode(std::string const& filename) const;

            virtual Proof testSat(std::vector<int> const& assign, int n) const;
    };
}
