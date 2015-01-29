#include "localsearch.hpp"

using namespace lslv;

int LocalSearch::solve(Problem& p, Node& node) {
	p.printDomains(node);
	std::vector<int> assignement;
	int nb_iter(0);

	// create the assignement
	for (auto d : node.dom()) {
		for (int i(0); i < d.dom().size(); i++) {
			if (d.dom().at(i)) {
				assignement.push_back(i);
				break;
			}
		}
	}

	// neighborhood
	int sum_conf(-1);
	std::vector<int> save_conf, save_assign;

	for (auto a : assignement)
		std::cout << a << " ";
	std::cout << std::endl;

	// localsearch
	do {

		// conflicts
		auto v_i_tuple = count_conf(assignement);
		save_conf = std::get<0>(v_i_tuple);
		int x1 = std::get<1>(v_i_tuple);
		sum_conf = std::accumulate(save_conf.begin(), save_conf.end(), 0, std::plus<int>());

		//std::vector<int> cp_assign = assignement;

		for (int i(0); i < assignement.size(); i++) {
			if (i != x1) {
				//int tmp = cp_assign.at(i);
				//cp_assign.at(i) = cp_assign.at(x1)
				int tmp = assignement.at(i);
				assignement.at(i) = assignement.at(x1);
				assignement.at(x1) = tmp;

				auto v_i_tuple2 = count_conf(assignement);
				int tmp_sum = std::accumulate(std::get<0>(v_i_tuple2).begin(), std::get<0>(v_i_tuple2).end(), 0, std::plus<int>());
				if (tmp_sum < sum_conf) {
					sum_conf = tmp_sum;
					break;
				}
				else {
					int tmp = assignement.at(i);
					assignement.at(i) = assignement.at(x1);
					assignement.at(x1) = tmp;
				}
			}
		}

		nb_iter++;
	} while (sum_conf != 0 && nb_iter < m_MAX_ITER);

	/*/
	  for (int i(0); i < node.dom().size(); i++) {
	  permutSol(node);
	  p.printDomains(node);
	  nb_sol++;
	  }
	//*/
	std::cout << nb_iter << std::endl;
	for (auto a : assignement) 
		std::cout << a << " ";
	std::cout << std::endl;
	std::cout << "return" << std::endl;
	return sum_conf == 0 ? 1 : 0;
}

void  LocalSearch::permutSol(Node& node) {

}

bool LocalSearch::conflict(int x1, int x2, std::vector<int> const& assign) const {
	return std::abs(assign.at(x1)-assign.at(x2)) == x2-x1;
}

std::tuple<std::vector<int>, int> LocalSearch::count_conf(std::vector<int> const& assign) const {
	std::vector<int> conflicts(assign.size());
	int x1(0);
	for (int i(0); i < assign.size(); i++) {
		for (int j(i+1); j < assign.size(); j++) {
			if (conflict(i, j, assign)) {
				conflicts.at(i)++;
				conflicts.at(j)++;
			}
		}

		if (conflicts.at(i) >= conflicts.at(x1))
			x1 = i;
	}

	return std::tuple<std::vector<int>, int>(conflicts, x1);
}

/*/
  std::vector<int> LocalSearch::neighborhood(std::vector<int> const& assign) const {

  }
//*/


