#pragma once

enum InputType { RANDOM, MANUAL };

class DichotomySearch
{
public:
	DichotomySearch();
	DichotomySearch(InputType type);
	virtual ~DichotomySearch();

    int Preprocess(int* array, int size);
    int Search(int element);

private:
    Tree tree;
};

