#include"head.h"
//索引表节点  
struct iNode
{
	int idata;  //块中最大的元素  
	int ipointer;   //块的起始下标  
};
//分块查找  
void block(iNode *index, int m, int *arr, int n, int key)       //index: 索引表数组，数组元素为索引节点  
{
	//对索引表进行二分查找  
	int low = 0, high = m - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key <= index[mid].idata)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	int aind = index[mid].ipointer; //获得已确定块的起始下标  
	bool ex = false; //是否存在匹配  
	while (arr[aind] <= index[mid].idata && aind != n)
	{
		if (key == arr[aind])
		{
			cout << "数组中第 " << aind + 1 << " 个数据元素与关键字 \"" << key << "\" 相匹配" << endl;
			ex = true;
			++aind;
			continue;
		}
		++aind;
	}
	if (false == ex)
	{
		cout << "数组中不存在数据元素与关键字 \"" << key << "\" 相匹配" << endl;
	}
}