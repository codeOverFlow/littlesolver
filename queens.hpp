/*
 * =====================================================================================
 *
 *       Filename:  queens.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2015 12:45:47
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
	class Queens : public Problem {
		public:
			inline Queens() {}
			inline ~Queens() {}
			inline virtual Node initialNode(std::string const& filename = "") const {
				std::fstream file;
				file.open(filename);
				std::string val;
				file >> val;
				int n = std::stoi(val);
				Node node(n, n);
				for (int i(0); i < n; i++) {
					std::vector<bool> tmp_v;
					for (int j(0); j < n; j++) {
						tmp_v.push_back(true);
					}
					node.addDom(Domain(n, tmp_v));
				}

				return node;
			}
			
			virtual Proof testSat(std::vector<int> const& assign, int n) const;
		private:
			bool check_diag(std::vector<int> const& assign) const;
	};
}
