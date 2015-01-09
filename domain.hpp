/*
 * =====================================================================================
 *
 *       Filename:  domain.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2015 18:06:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

namespace lslv {
    class Domain {
        public:
            /*
             * create the domain for a variable
             */
            Domain(int dom_size, std::vector<bool> bool_vec = {});
            ~Domain();
            /*
             * check if the domain is empty
             */
            inline bool isEmpty() const { return m_dom.empty(); }
            /*
             * return the domain
             */
            inline std::vector<bool> dom() const { return m_dom; }
            /*
             * flip a bit in the vector
             * param: n the index of the bit to flip
             */
            inline void flip(int n) { m_dom.at(n) = !m_dom.at(n); }
            bool egal(Domain const& d) const;
            int positive_bits() const;

        private:
            std::vector<bool> m_dom; 
    };
}
