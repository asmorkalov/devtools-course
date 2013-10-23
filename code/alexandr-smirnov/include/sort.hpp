#pragma once 

enum SortMethod { QuickSort, HeapSort, MergeSort };

class ISorter {
	virtual void Sort(int* array, int size) = 0;
	virtual ~ISorter();
};

smart_ptr<ISorter> createSorter(SortMethod method);

//=======================

ISorter* sorter;
sorter = createSorter(QuickSort);
...
sorter.Sort(array, size);