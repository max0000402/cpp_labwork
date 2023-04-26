#pragma once

#include "ITreeVisitor.hpp"

#include "BareTree.hpp"
#include "Tree.hpp"
#include "AppleTree.hpp"
#include "Fir.hpp"
#include "Stump.hpp"

class AxeVisitor : public ITreeVisitor {
private:
	BareTree* m_new_tree = nullptr;
public:
	void VisitBareTree(BareTree* tree) override;
	void VisitTree(Tree* tree) override;
	void VisitAppleTree(AppleTree* tree) override;
	void VisitFir(Fir* tree) override;
	void VisitStump(Stump* tree) override;

	BareTree* get_result();
};