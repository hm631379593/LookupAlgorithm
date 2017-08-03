#include"head.h"
/*
*
*  顺序查找算法
*
*/
void saar(int *arr, int sz, int key)    //sz: 数组大小，key: 关键字  
{
	int ind = 0;    //下标索引  
	bool ex = false;    //是否存在匹配  
	while (ind != sz)
	{
		if (key == arr[ind])
		{
			cout << "数组中第 " << ind + 1 << " 个数据元素与关键字 \"" << key << "\" 相匹配" << endl;
			ex = true;
			++ind;
			continue;
		}
		++ind;
	}
	if (false == ex)
	{
		cout << "数组中不存在数据元素与关键字 \"" << key << "\" 相匹配" << endl;
	}
}