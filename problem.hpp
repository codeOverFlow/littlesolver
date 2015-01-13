#pragma once

#include <string>
#include <iostream>

#include "node.hpp"

namespace lslv {

    enum class Proof {SUCCESS, FAILURE, MIDDLE};

    class Problem {
        public:
            virtual Node initialNode(std::string const& filename) const = 0;
            virtual Proof testSat(std::vector<int> const& assignment, int n) const = 0;
            virtual void printSolution(std::vector<int> const& assignment) const {
                std::cout << "Solution found: ";
                for (auto i : assignment)
                    std::cout << i << "    ";
                std::cout << std::endl;
            }

	    virtual void printSolution(Node& node) const {
			std::cout << "Solution of the node: ";
			for (Domain d : node.dom()) {
				std::cout << "(";
				for (int i(0); i < d.dom().size(); i++) {
					if(d.dom().at(i)) {
						std::cout << i << "   ";
					}
				}
				std::cout << ") ";
			}
			std::cout << std::endl;
	    }
            
            virtual inline bool all_diff(std::vector<int> assignment) const {
                std::stable_sort(assignment.begin(), assignment.end());
                //std::cout << (std::adjacent_find(assignment.begin(), assignment.end()) == assignment.end() ? true : false) << std::endl;
                return std::adjacent_find(assignment.begin(), assignment.end()) == assignment.end() ? true : false;
            }

            virtual inline bool all_assign(std::vector<int> const& assignment, int n) const {
                return assignment.size() == (unsigned int)n;
            }
    };
}
