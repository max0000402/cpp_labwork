#include "AxeVisitor.hpp"

void AxeVisitor::VisitBareTree(BareTree* tree) {
	m_new_tree = new Stump(tree->get_x(), tree->get_y(), tree->get_color());
}

void AxeVisitor::VisitTree(Tree* tree) {
	m_new_tree = new BareTree(tree->get_x(), tree->get_y(), tree->get_color());
}

void AxeVisitor::VisitAppleTree(AppleTree* tree) {
	m_new_tree = new Tree(tree->get_x(), tree->get_y(), tree->get_color(), tree->get_leaf_color());
}

void AxeVisitor::VisitFir(Fir* tree) {
	m_new_tree = new BareTree(tree->get_x(), tree->get_y(), tree->get_color());
}

void AxeVisitor::VisitStump(Stump* tree) {
	m_new_tree = tree;
}

BareTree* AxeVisitor::get_result() {
	return m_new_tree;
}