#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <fstream>


#include "node.hpp"

namespace lslv {
	
	enum class Proof {SUCCESS, FAILURE, MIDDLE};
	
	class Problem {
	public:
		virtual Node initialNode(std::string const& filename) const{
			std::fstream f;
			f.open(filename);
			
			int nb_var, size_d;
			std::string val;
			f >> val;
			//std::cout << val << std::endl;
			nb_var = std::stoi(val);
			f >> val;
			size_d = std::stoi(val);
			Node n(size_d, nb_var);
			for(size_t loop = 0; loop < nb_var; loop++){
				bool finished(false);
				std::vector<bool> tmp_v(size_d);
				while (!finished){
					f >> val;
// 					std::cout << val << std::endl;
					if (val == ",")
						finished = true;
					else if (f.eof()) {
						tmp_v.at(std::stoi(val)-1) = true;
						finished = true;
					}
					else
						tmp_v.at(std::stoi(val)-1) = true;
				}
				n.addDom(Domain(size_d, tmp_v));
			}
			return n;
		}
		
		virtual Proof testSat(std::vector<int> const& assignment, int n) const = 0;
		
		virtual inline void printSolution(std::vector<int> const& assignment) const {
			std::cout << "Solution found: ";
			for (auto i : assignment)
				std::cout << i << "    ";
			std::cout << std::endl;
		}
		
		virtual inline void printDomains(Node& node) const {
			std::cout << "Domains: ";
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
			std::vector<int> tmp;
			for (auto i : assignment) {
				if (i != -1)
					tmp.push_back(i);
			}
			std::stable_sort(tmp.begin(), tmp.end());
			return std::adjacent_find(tmp.begin(), tmp.end()) == tmp.end();
		}
		
		virtual inline bool all_assign(std::vector<int> const& assignment, int n) const {
			bool b(true);
			for (auto i : assignment) {
				if (i == -1) {
					b = false;
					break;
				}
			}
			return (assignment.size() == (unsigned int)n) && b;
		}
	};
}
