#include "localsearch.hpp"

using namespace lslv;

int LocalSearch::solve(Problem& p, Node& node) {
	int nb_sol(0);
	std::cout << "create initial solution" << std::endl;
	createInitialSol(node);
	nb_sol++;
	p.printDomains(node);

	/*/
	for (int i(0); i < node.dom().size(); i++) {
		permutSol(node);
		p.printDomains(node);
		nb_sol++;
	}
	//*/
	std::cout << "return" << std::endl;
	return nb_sol;
}

void LocalSearch::createInitialSol(Node& node) {
	std::cout << "compute the coef" << std::endl;
	int coef = (node.dom().size() % 2 == 0 ? 3 : 2);

	for (int i(0); i < node.dom().size(); i++) {
		for (int j(0); j < node.dom().size(); j++) {
			if (j != (i*coef) % node.dom().size())
				node.dom().at(i).dom().at(j) = false;
		}
	}
	std::cout << "create end" << std::endl;
}

void  LocalSearch::permutSol(Node& node) {

}
