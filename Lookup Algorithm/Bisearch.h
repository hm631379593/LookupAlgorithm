/*
*
*   折半查找算法
*
*/
template<typename T>
int bsearch(const T* arr, const int& len, const T& data)
{
	int l = 0;
	int r = len - 1;
	int mid = 0;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (*(arr + mid) > data)
			r = mid - 1;
		else if (data > *(arr + mid))
			l = mid + 1;
		else
			return mid;
	}

	return -1;
}