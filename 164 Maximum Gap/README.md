# 163 Maximum Gap


题目链接： [https://leetcode.com/problems/maximum-gap/](https://leetcode.com/problems/maximum-gap/ "点击查看原始题目")

## 题意
一个未排序的数组，计算该数组排序后相邻两个元素间差值的最大值。要求用O(n)的时间和空间。

## 思路
利用桶排序的思想

+ 桶排序

	针对一个数组，例如[1,2,...,99,100]我们可以划分10个桶bucket[10],这样数组中的每个元素经过key=value/10可以将每个元素对应到某一个桶中，在分别对每一个非空桶进行排序，之后将每一个非空桶连接起来就是排好序的数组了
+ 一个例子

		[34,12,24,44,90,99,87,86,80,89,65,66],可以划分10个桶bucket[10]
		bucket[0]->NULL
		bucket[1]->12->NULL
		bucket[2]->24->NULL
		bucket[3]->34->NULL
		bucket[4]->44->NULL
		bucket[5]->NULL
		bucket[6]->65->66->NULL
		bucket[7]->NULL
		bucket[8]->80->86->87->NULL
		bucket[9]->90->99->NULL

	数据一般是在插入桶的同时进行排序的

+ 针对本题，可以将桶长度设置为len=(max-min+1)/n,这样最大值肯定是>=len的，因此最大值得两个数一定在不同的桶中，所以只需要在排序后找到相邻非空桶之间的最大差值，即为要求的最大值。排序的过程中每个桶只需记录该桶中的最大值和最小值就行了。


