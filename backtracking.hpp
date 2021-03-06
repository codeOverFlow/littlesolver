/*
 * =====================================================================================
 *
 *       Filename:  backtracking.hpp
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

#include "algorithm.hpp"

namespace lslv {
	class Backtracking : public Algorithm {
	public:
		Backtracking();
		~Backtracking();
		virtual int solve(Problem& p, Node& node);
		
	protected:
		int backtracking(Problem& p, Node& node, int& cpt, std::vector<int> assignment = {}, std::vector<int> not_assigned = {});
		void branch(Problem& p, Node& node, std::vector<int> assignment, int& cpt, std::vector<int> not_assigned = {});
		int nb_nodes;
	};
};
