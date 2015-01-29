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

#include <ctime>
#include <tuple>

#include "algorithm.hpp"

namespace lslv {
	class LocalSearch : public Algorithm {
		public:
			inline LocalSearch(int nb_iter) : m_MAX_ITER(nb_iter) {}
			inline ~LocalSearch() {}
			virtual int solve(Problem& p, Node& node);

		private:
			void createInitialSol(Node& node);
			void permutSol(Node& node);
			bool conflict(int x1, int x2, std::vector<int> const& assign) const;
			std::tuple<std::vector<int>, int> count_conf(std::vector<int> const& assign) const;
			std::vector<int> neighborhood(std::vector<int> const& assign) const;
			const int m_MAX_ITER;

	};
};
