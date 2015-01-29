#include "queens.hpp"

using namespace lslv;

Proof Queens::testSat(std::vector<int> const& assign, int n) const {
	Proof sat = Proof::MIDDLE;
	bool diff = all_diff(assign);
	bool no_diag = check_diag(assign);
	if (all_assign(assign, n) && diff && no_diag)
		sat = Proof::SUCCESS;
	else if (!diff && !no_diag)
		sat = Proof::FAILURE;
	return sat;
}

bool Queens::check_diag(std::vector<int> const& assign) const {
	for (int i(0); i < assign.size(); i++) {
		for (int j(i+1); j < assign.size(); j++) {
			if (std::abs(assign.at(i) - assign.at(j)) == j-i)
				return false;
		}
	}
	return true;
}
