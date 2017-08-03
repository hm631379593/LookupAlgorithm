/*
*
*　哈希表的查找
*
*
*  开放地址法哈希表的存储表示
*
*/

//哈希表的表长
#define m               16    
//单元为空的标记
#define NULLKEY         0           

struct HashTable {
	//关键字项
	int  key;                        
	// InfoType  otherinfo;             //其他数据项									 
};

/*
*
*  哈希表查找的算法，采用线性探测法处理冲突。
*
*
*  除留取余方法构造哈希函数：
*    H(key) = key % p
*    H(key) —— 散列地址(表现为数组下标)
*    key —— 数据中的关键字(直接来自数据)
*    p —— 不大于表长的质数
*/

//构造哈希函数
int H(int key)
{
	int result;
	result = key % 13;
	return result;
}

//在哈希表HT中查找关键字为key的元素，若查找成功，返回哈希表的单元标号，否则返回-1 
int SearchHash(HashTable HT[], int key) {
	//根据哈希函数H(key)计算哈希地址
	int H0 = H(key);                            
	int Hi;
	//若单元H0为空，则所查元素不存在
	if (HT[H0].key == NULLKEY) return -1; 
	// 若单元H0中元素的关键字为key，则查找成功
	else if (HT[H0].key == key) return H0;       
	else {

		/*
		开放地址法处理地址冲突公式：
		Hi = (H(key) + di) % m    (i = 1, 2, ..., m-1)
		Hi——下一个散列地址
		H(key)——产生冲突的散列地址

		di——散列地址增量(视具体冲突处理方法而定)
		-> 线性探测法 di = 1, 2, 3, ..., m-1
		-> 二次探测法 di = 1^2, -1^2, 2^2, -2^2, k^2, -k^2(k <= m/2)
		-> 伪随机探测法 di = 伪随机数序列

		m——散列表表长
		*/
		for (int i = 1; i < m; ++i) {
			//按照线性探测法计算下一个哈希地址Hi
			Hi = (H0 + i) % m; 
			//若单元Hi为空，则所查元素不存在
			if (HT[Hi].key == NULLKEY) return -1;  
			//若单元Hi中元素的关键字为key，则查找成功
			else if (HT[Hi].key == key) return Hi;   
		}//for

		return -1;

	}//else

}
