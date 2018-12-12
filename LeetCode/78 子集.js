// 78 子集
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var subsets = function(nums) 
{
    var list=[[]];
    //空集也是子集
    if(nums.length===0)
    	return list;

    //树形结构，先分为每个元素
    for(let i=0;i<nums.length;i++)
    {
    	var array=[nums[i]];//array是结果数组的元素，结果数组的元素也是数组
    	var len=list.length;//注意这句。这是结果数组的长度
    	//可以画个图看看
    	for(let j=0;j<len;j++)
    	{
    		//concat用于连接两个数组
    		var ret=list[j].concat(array);
    		list.push(ret);
    	}
    }

    return list;
};


//用位运算解
var subsets = function(nums)
{
    var list=[];  //定义结果数组
    var n=nums.length;      //n存储集合长度
    var l=Math.pow(2,n);    //用1-l期间的数的二进制表示的位串，来表示该全集所有的子集
    
    var array=[];//这里设置array作为子集的元素，因为结果数组的元素还是数组
    for(let i=1;i<l;i++)    //总共有l个子集
    {
        for(let j=0;j<n;j++)    //每个子集的二进制位串有几位有效数字
        {
            if((1<<j)&i)    //查看i的哪些位为1
            {
                array.push(nums[j]);    //i为1的位对应的元素加入子集
                list[i]=array;          
            }
        }
        array=[];
    }

    return list;
}


/**** 来看看56ms的范例 ****/
let subsets = function(nums) 
{
    let res = new Array(2 ** nums.length).fill().map(() => []);
    for (let i = 0; i < nums.length; ++i) {
        for (let j = 0; j < res.length; ++j) {
            if ((j >> i) & 1) {
                res[j].push(nums[i]);
            } 
        }
    }
    return res;
}