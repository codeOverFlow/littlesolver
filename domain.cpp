/*
 * =====================================================================================
 *
 *       Filename:  domain.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2015 16:20:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include "domain.hpp"

using namespace lslv;

Domain::Domain(int dom_size, std::vector<bool> bool_vec) {
    if (bool_vec.empty()) {
        m_dom.reserve(dom_size);
        for (int i = 0; i < dom_size; i++)
            m_dom.push_back(false);
    }
    else
        m_dom = bool_vec;
}

Domain::~Domain() {}

bool Domain::egal(Domain& d) const {
    bool res(true); 
    for (int i(0); i < m_dom.size(); i++) {
        if(m_dom.at(i) != d.dom().at(i)) {
            res = false;
            break;
        }
    }
    return res;
}

int Domain::positive_bits() const { 
    int sum(0);
    for(auto b : m_dom)
        sum += b;

    return sum; 
}
