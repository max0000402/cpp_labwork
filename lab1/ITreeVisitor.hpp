#pragma once

class BareTree;
class Tree;
class AppleTree;
class Fir;
class Stump;

class ITreeVisitor {
public:
	virtual void VisitBareTree(BareTree* tree) = 0;
	virtual void VisitTree(Tree* tree) = 0;
	virtual void VisitAppleTree(AppleTree* tree) = 0;
	virtual void VisitFir(Fir* tree) = 0;
	virtual void VisitStump(Stump* tree) = 0;
};