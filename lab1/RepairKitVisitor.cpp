#include "RepairKitVisitor.hpp"

void RepairKitVisitor::VisitBareTree(BareTree* tree) {
	m_new_tree = new Tree(tree->get_x(), tree->get_y(), tree->get_color(), RGB(0, 255, 0));
}

void RepairKitVisitor::VisitTree(Tree* tree) {
	m_new_tree = new AppleTree(tree->get_x(), tree->get_y(), tree->get_color(), tree->get_leaf_color(), RGB(255, 0, 0));
}

void RepairKitVisitor::VisitAppleTree(AppleTree* tree) {
	m_new_tree = tree;
}

void RepairKitVisitor::VisitFir(Fir* tree) {
	m_new_tree = new Tree(tree->get_x(), tree->get_y(), tree->get_color(), RGB(0, 255, 0));
}

void RepairKitVisitor::VisitStump(Stump* tree) {
	m_new_tree = new BareTree(tree->get_x(), tree->get_y(), tree->get_color());
}

BareTree* RepairKitVisitor::get_result() {
	return m_new_tree;
}