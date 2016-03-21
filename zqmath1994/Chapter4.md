###  分治策略解决问题三部曲
####  1. 分解：将问题划分为同性质的子问题 
####  2.  解决：递归求解子问题
#### 3. 合并 ：子问题的解组合成原问题的解

### 细节：子问题规模不必是原问题规模的固定比例，例如线性查找的递归版本仅生产一个子问题，其规模仅比原问题的规模少一个元素。 

### 求递归式三种方法
#### 1. 代入法：猜测界，数学归纳法证明
#### 2. 递归树法：将递归式转换为一棵树，结点表示不同层次的递归调用产生的代价，然后采用边界和技术求解递归式
#### 3. 主方法 ： 可以求解生成a个子问题，每个子问题为原问题规模的b分之一，分解和合并步骤总花费f(n)

### 最大子数组问题
####  问题描述：寻找数组Ａ的和最大的非空子数组
####  背景描述：股市高价卖，低价买，寻找买入和卖出时机，A[i]表示第i天和第i-1天的股市差值
#### 解决思路：A[low,high] 的最大子数组必然位于如下位置：
##### 1. 完全位于子数组A\[low,mid](mid为原始数组的中间节点)
##### 2. 完全位于子数组A\[mid+1,high](mid为原始数组的中间节点)
##### 3. 跨越了mid节点
#### 前两种情况，递归求解。第三种情况，令low≤i≤mid，mid+1≤j≤high，寻找最大子数组A[i,mid]和A[mid+1,j]
#### 解决跨越mid节点方法代码如下
```cpp
int findMaxCrossingSubarray(int a[],int low,int mid,int high)
{
    int left_sum = -(2<<31-1);
    int sum = 0;
    int max_left;
    for(int i = mid;i >= low;--i)
    {
        sum += a[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -(2<<31-1);
    int sum = 0 ;
    int max_right;
    for(int i = mid+1; i <= high; ++i)
    {
        sum += a[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    return left_sum+right_sum;
}
```
#### 解决最大子数组问题代码
```cpp
int findMaximumSubarray(int a[],int low,int high)
{
    int left_sum,right_sum,cross_sum;
    if(high == low)
    {
        return low;
    }
    else
    {
        int mid = (int)((low+high)/2);
        left_sum = findMaximumSubarray(&a,low,mid);
        right_sum = findMaximumSubarray(&a,mid+1,high);
        cross_sum = findMaxCrossingSubarray(&a,low,mid,high);
    }
    int max=max(left_sum,right_sum);
    max=max(max,cross_sum);
    return max;
}
```
### 未完待续