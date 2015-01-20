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
	class LocalSearch : public Algorithm {
	public:
		inline LocalSearch() {}
		inline ~LocalSearch() {}
		virtual int solve(Problem& p, Node& node);
		
	private:
		void createInitialSol(Node& node);
		void permutSol(Node& node);
	};
};
