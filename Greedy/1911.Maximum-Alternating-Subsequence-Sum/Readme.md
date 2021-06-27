### 1911.Maximum-Alternating-Subsequence-Sum

此题的本质就是```122. Best Time to Buy and Sell Stock II```. 数组的元素想象成每天的股价，你必须买一支（挑选的第偶数个数）、卖一支（挑选的第奇数个数）这样交替操作。问最终的最大收益是多少。显然对于122题而言，尽量榨取每一天的利润、规避每一天的亏损，就是最优的贪心策略。只要明天比今天的价格高，那么我就今天买，明天卖；如果明天比今天的价格低，那么我今天就不买。

对于本题，同理查看每一个相邻对。比如nums[1]>nums[2]，那么我们就增加利润nums[1]-nums[2]. 如果nums[2]>nums[3]，那么我们就增加利润nums[2]-nums[3]. 我们发现这两步操作，前者是将nums[2]当做奇数项，后者是将nums[2]当做偶数项，看似矛盾，但本质就是抵消了nums[2]，只挑选了nums[1]和nums[3]，同时将这两段gap的利润都拿到了。

特别注意的是，无论nums个数的奇偶性，我们最终无法给最后一个元素nums[n-1]找相邻对。所以我们只需要将其直接加入结果即可。注意这只是形式上的。举个例子，```4,3,2,1```，虽然我们计算的收益是(4-3)+(3-2)+(2-1)+1，但本质我们选中的其实是4和1，其中1是被当做了奇数项。再比如```1 2 3 4```，(1,2), (2,3), (3,4)都是亏损的，我们不会考虑，最终我们计算的收益只有是4，形式上它被当做了偶数项。