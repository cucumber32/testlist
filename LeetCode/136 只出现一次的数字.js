//136 只出现一次的数字

/**
 * @param {number[]} nums
 * @return {number}
 */

//此方法不能识别负数。
/*var singleNumber = function(nums) 
{
	var n;
	/*for(let i=0;i<num.lenth;i++)
		//num+=nums[i];
	//数组转成字符串另一种方式：
	var num=nums.join("");
    for(let i=0;i<num.length;i++)
    {
    	//这里，正则表达的两个“/”之间如果放变量不可行，此时需要用另一种方式创建正则表达式：
    	//n=nums.match(/nums[i]/g);
    	var reg=new RegExp(num[i],"g");
    	n=num.match(reg);
    	//console.log(nums[i],n);

    	if(n.length==1)
    		return parseInt(num[i]);
    }

    return;
};*/

//这么写会比如[-1,-1,1]会没有结果，因为1包含在-1内
/*var singleNumber = function(nums) 
{
    var n;
	var num=nums.join("");

    for(let i=0;i<num.length;i++)
    {
    	var reg=new RegExp(nums[i],"g");
    	n=num.match(reg);
    	//console.log(nums[i],n.length);
    	debugger;
    	if(n.length==1)
    		return nums[i];
    }

    return;
};*/

//那么用逗号隔开？6000+ms哈哈哈太真实了
var singleNumber = function(nums) 
{
    var n;
	var num=","+nums.join(",");

    for(let i=0;i<nums.length;i++)
    {
    	var reg=new RegExp(","+nums[i],"g");//前面加逗号，防止匹配到对应负数
    	n=num.match(reg);
    	if(n.length==1)
    		return nums[i];
    }

    return;
};

/******************看看人家52ms的范例**********************/
var singleNumber = function(nums) {
    let init = 0
    nums.forEach(d=>{
        init ^= d
    })
    return init
};
//es6中，=>相当于function()
/*
	el => (result ^= el)
	相当于
	function(el)
	{
		return result ^= el;
	}
    好的好的没看箭头函数给自己记一笔。
*/

/*知道原理之后再写了一遍*/
var singleNumber = function(nums) 
{
    var n=0;
    for(let i=0;i<nums.length;i++)
    {
        n ^=nums[i];
    }
    return n;
};