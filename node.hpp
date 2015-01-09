#pragma once

#include <vector>

#include "domain.hpp"

namespace lslv {
    class Node {
        public:
            Node(int dom_size, int nb_var);
            std::vector<Domain> dom() const;
            void addDom(Domain const& dom);

        private:
            std::vector<Domain> m_dom;
    };
}
