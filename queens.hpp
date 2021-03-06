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

#include <ctime>
#include <cmath>

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
				std::vector<int> storage;
				
				for (int i(0); i < n; i++)
					storage.push_back(i);
				
				std::srand(std::time(NULL));
				int pred(-1);
				for (int i(0); i < n; i++) {
					int rand;
					
					if (pred != -1) {
						std::vector<int> storage_tmp;
						for (int n(0); n < storage.size(); n++) {
							if (storage.at(n) != pred+1 && storage.at(n) != pred-1)
								storage_tmp.push_back(n);
						}
						
						if (storage_tmp.size() != 0) {
							rand = std::rand() % storage_tmp.size();
							rand = storage_tmp.at(rand);
						}
						else
							rand = std::rand() % storage.size();
					}
					else
						rand = std::rand() % storage.size();

					std::vector<bool> tmp_v;
					for(int k(0); k < n; k++) {
						if (k == storage.at(rand)) {
							tmp_v.push_back(true);
							pred = k;
						}
						else
							tmp_v.push_back(false);
					}
					node.addDom(Domain(n, tmp_v));
					storage.erase(storage.begin()+rand);
				}

				return node;
			}
			
			virtual Proof testSat(std::vector<int> const& assign, int n) const;
		private:
			bool check_diag(std::vector<int> const& assign) const;
	};
}
