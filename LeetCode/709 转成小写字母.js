//709 转成小写字母

/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) 
{
	var code,abc="";
    for(var i=0;i<str.length;i++)
    {
    	code=str[i].charCodeAt();
    	if(code>=65&&code<=90)
    	{
    		code+=32;
    		abc+=String.fromCharCode(code);
    		continue;
    	}
    	abc+=str[i];
    	//str[i]=String.fromCharCode(code); 这样写一直不能赋值？为啥！！！！
    	//console.log(String.fromCharCode(code));
    	//console.log("to:"+stt);
    }
    return abc;
};