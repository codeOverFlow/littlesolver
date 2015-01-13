/*
 * =====================================================================================
 *
 *       Filename:  node.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2015 16:31:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (fgm), mehner.fritz@fh-swf.de
 *   Organization:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include "node.hpp"

using namespace lslv;

Node::Node(int dom_size, int nb_var) {
    m_dom.reserve(nb_var);
}

void Node::addDom(Domain const& dom) {
    m_dom.push_back(dom);
}
