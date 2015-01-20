#pragma once

#include <vector>

#include "domain.hpp"

namespace lslv {
    class Node {
        public:
            Node(int dom_size, int nb_var);
            inline std::vector<Domain>& dom() { return m_dom; }
            void addDom(Domain const& dom);

        private:
            std::vector<Domain> m_dom;
    };
}
