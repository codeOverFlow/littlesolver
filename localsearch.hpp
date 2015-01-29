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
	typedef std::tuple<int, std::vector<int>> tuple_i_vi;

	class LocalSearch : public Algorithm {
		public:
			inline LocalSearch(int nb_iter) : m_MAX_ITER(nb_iter) {}
			inline ~LocalSearch() {}
			virtual int solve(Problem& p, Node& node);

		private:
			void permutSol(Node& node);
			bool conflict(int x1, int x2, std::vector<int> const& assign) const;
			std::vector<int> find_conf(std::vector<int> assign) const;
			int count_conf(std::vector<int> const& assign) const;
			bool contains(std::vector<int> const& vect, int const& val) const;
			int neighborhood(std::vector<int>& assign) const;
			void make_assign(Node& node, std::vector<int>& assign) const;
			const int m_MAX_ITER;

	};
};
