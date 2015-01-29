#include "localsearch.hpp"

using namespace lslv;

int up(0), tot(0);

int LocalSearch::solve(Problem& p, Node& node) {
	//p.printDomains(node);
	std::vector<int> assignement;

	// create the assignement
	make_assign(node, assignement);	
	//count_conf(assignement);
	/*/
	for (int i(0); i < assignement.size(); i++) {
		for (int cpt(0); cpt < assignement.size(); cpt++) {
			if (cpt == assignement.at(i))
				std::cout << " ¥ ";
			else
				std::cout << " . ";	
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//*/

	// neiborghood
	int nb_sol = neighborhood(assignement);
	//std::cout << "nb_sol: " <<  nb_sol << std::endl;
	/*/
	for (int i(0); i < assignement.size(); i++) {
		for (int cpt(0); cpt < assignement.size(); cpt++) {
			if (cpt == assignement.at(i))
				std::cout << " ¥ ";
			else
				std::cout << " . ";	
		}
		std::cout << std::endl;
	}
	//std::cout << "return" << std::endl;
	//*/
	tot++;
	up += nb_sol;
	std::cout << "\rtotal: " << tot << " | up: " << up << " | up rate: " << (up*100/tot);
	return nb_sol;
}

void  LocalSearch::permutSol(Node& node) {

}

bool LocalSearch::conflict(int x1, int x2, std::vector<int> const& assign) const {
	return std::abs(assign.at(x1)-assign.at(x2)) == x2-x1;
}

std::vector<int> LocalSearch::find_conf(std::vector<int> assign) const {
	std::vector<int> confs;
	for (int row(0); row < assign.size(); row++)
		confs.push_back(assign, row, assign.at(row));
	return confs;
}

int LocalSearch::count_conf(std::vector<int> const& assign, int row, int col) const {
	int total(0);
	for (int i(0); i < assign.size(); i++) {
		if (i == row)
			continue;
		if (std::abs(assign.at(i) - col) == 
	}
	return tuple_i_vi(std::accumulate(conflicts.begin(), conflicts.end(), 0, std::plus<int>()), confs);
}

//*/
bool LocalSearch::contains(std::vector<int> const& vect, int const& val) const {
	for (int i : vect) {
		if (i == val)
			return true;
	}
	return false;
}
//*/

void LocalSearch::make_assign(Node& node, std::vector<int>& assign) const {
	for (auto d : node.dom()) {
		for (int i(0); i < d.dom().size(); i++) {
			if (d.dom().at(i)) {
				assign.push_back(i);
				break;
			}
		}
	}
}

int LocalSearch::neighborhood(std::vector<int>& assign) const {
	int sum_conf(-1);
	std::vector<int> save_assign;

	// localsearch
	for (int nb_iter(0); nb_iter < m_MAX_ITER; nb_iter++) {

		// conflicts
		tuple_i_vi i_v_tuple   = count_conf(assign);
		std::vector<int> confs = std::get<1>(i_v_tuple);
		sum_conf               = std::get<0>(i_v_tuple);

		if (sum_conf == 0)
			return 1;

		// neiborghood
		int x1 = confs.at(std::rand() % confs.size());
		//std::cout << x1 << " ";
		for (int i(0); i < assign.size(); i++) {
			if (i != x1) {
				int tmp = assign.at(i);
				assign.at(i) = assign.at(x1);
				assign.at(x1) = tmp;

				tuple_i_vi i_v_tuple2 = count_conf(assign);
				int tmp_sum = std::get<0>(i_v_tuple2);
				if (tmp_sum < sum_conf) {
					sum_conf = tmp_sum;
					save_assign = assign;
					if (sum_conf == 0)
						return 1;
				}
				else {
					int tmp       = assign.at(i);
					assign.at(i)  = assign.at(x1);
					assign.at(x1) = tmp;
				}
			}
		}
		assign = save_assign;
	}

	return 0;
}
