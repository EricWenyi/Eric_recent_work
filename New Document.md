# “关键字”法完成新闻摘要提取

## 一、实验说明

下述介绍为实验楼默认环境，如果您使用的是定制环境，请修改成您自己的环境介绍。

### 1. 环境登录

无需密码自动登录，系统用户名shiyanlou

### 2. 环境介绍

本实验环境采用带桌面的Ubuntu Linux环境，实验中会用到桌面上的程序：

1. LX终端（LXTerminal）: Linux命令行终端，打开后会进入Bash环境，可以使用Linux命令
2. GVim：非常好用的编辑器，最简单的用法可以参考课程[Vim编辑器](http://www.shiyanlou.com/courses/2)

### 3. 环境使用

使用GVim编辑器输入实验所需的代码及文件，使用LX终端（LXTerminal）运行所需命令进行操作。

实验报告页面可以在“我的主页”中查看，其中含有每次实验的截图及笔记，以及实验的有效学习时间（指的是在实验桌面内操作的时间，如果没有操作，系统会记录为发呆时间），这些都是您学习的真实性证明。

## 二、课程介绍

我们现在浏览新闻，一般都会看标题(title)和新闻简介(summary)来判断我们是否对这则新闻感兴趣。之前的新闻简介都是由编辑手动提取的，现在自然语言处理(Natural Language Processing, NLP)技术发展日益成熟，我们发现计算机提取的摘要也可圈可点。

本次课程分为两个实验。实验一主要完成一个相对简单的“关键字提取”算法，关注的是实现的过程，让同学们对自然语言处理有个大致的了解。实验二主要关注的是TextRank算法。

我们先来看一下我们最终实现的效果。

原文：
> 

![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid122063labid2480timestamp1482913479174.png/wm)

*号之后是我们提取的摘要。
## 二、实验步骤

###1. 准备工作

我们这次实验都是在python3中进行。首先我们需要安装NLTK(Natural Language Toolkit),我们在命令行中输入

```
sudo pip3 install nltk
```

然后进入python3的交互界面，在命令行中输入

```
python3
```
应该就有python的提示符出现。
![此处输入图片的描述](https://dn-anything-about-doc.qbox.me/document-uid122063labid2480timestamp1482911225849.png/wm)
请注意一定是要在python3环境下

在python 交互环境中，我们输入

```
>>> import nltk
>>> nltk.download('stopwords')
>>> nltk.download('punkt')
```
如果download函数长时间不响应的话，按ctrl+z退出python3交互环境，重新下载。

我们在桌面上新建一个文件夹NewsSummarize

```
mkdir NewsSummary
```
在NewsSummary中用vim创建NewsSummary1.py文件

先导入我们需要的包

```python
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import stopwords
from collections import defaultdict
from string import punctuation
from heapq import nlargest
```


至此我们完成了我们的准备工作。

###2. 思路解析

我们的基本思想很简单：拥有关键词最多的句子就是最重要的句子。我们把句子的关键词数量排序，取其中的前n项，即可汇总成我们的摘要。

所以我们的工作可以分为如下步骤：

1. 给在文章中出现的单词按照算法计算出分数，出现次数越多分数越高
2. 按照句子中单词的分数算出句子的总分
3. 按照句子的总分给文章中的每个句子排序
4. 取出前n个句子作为摘要

我们就按照这这个顺序写我们的模块


###3. 词频统计

首先我们先要统计出每个词在文章中出现的次数，在统计出次数之后，我们可以知道出现次数最多的词的出现次数 m 。我们把每个词wi出现的次数 mi 除以 m ，算出每个词的“重要系数”。

我们举个例子。
"I am a fool, big fool." 这句句子中

| I  |am| a | fool|big|
| -- |:-|: -| : --|:--|
| 1  | 1| 1 |  2  | 1 |
出现最多的是 'fool' 这个单词，所以 m 是2。所有单词的频率都除以m，可以获得新的表

| I  |am| a | fool|big|
| -- |:-|: -| : --|:--|
| 0.5| 0.5| 0.5 |  1  | 0.5 |


我们先定一些我们需要的常量

```
stopwords = set(stopwords.words('english') + list(punctuation))
max_cut = 0.9
min_cut = 0.1
```
首先是我们的stopwords。stopwords包含的是我们在日常生活中会遇到的出现频率很高的词，如do, I, am, is, are等等，这种词汇是不应该算是我们的关键字。同样的标点符号（punctuation）也不能被算作是关键字。我们的max_cut限制了一些没有在nltk.stopwords中出现，但是在文本中出现频率很高的词。同理，min_cut限制了出现频率很低的词。频率太高和频率太低都代表着这个词没有代表性。

```python
"""
计算出每个词出现的频率
word_sent 是一个已经分好词的列表
返回一个词典freq[],
freq[w]代表了w出现的频率
"""
def compute_frequencies(word_sent):
    """
    defaultdict和普通的dict
    的区别是它可以设置default值
    参数是int默认值是0
    """
    freq = defaultdict(int)
    
    #统计每个词出现的频率
    for s in word_sent:
        for word in s:
            #注意stopwords
            if word not in stopwords:
                freq[word] += 1
    
    #得出最高出现频次m
    m = float(max(freq.values()))
    #所有单词的频次统除m
    for w in list(freq.keys()):
        freq[w] = freq[w]/m
        if freq[w] >= max_cut or freq[w] <= min_cut:
            del freq[w]
    # 最后返回的是
    # {key:单词, value: 重要性}
    return freq
```

###4. 获得摘要

现在每个单词（stopwords和出现频率异常的单词除外）都有了“重要性”这样一个量化描述的值。我们现在需要统计的是一个句子中单词的重要性。只需要把句子中每个单词的重要性叠加就行了。

```
def summarize(text, n):
    """
    用来总结的主要函数
    text是输入的文本
    n是摘要的句子个数
    返回包含摘要的列表
    """

    # 首先先把句子分出来
    sents = sent_tokenize(text)
    assert n <= len(sents)

    # 然后再分词
    word_sent = [word_tokenize(s.lower()) for s in sents]
    
    # freq是一个词和词重要性的字典
    freq = compute_frequencies(word_sent)
    #ranking则是句子和句子重要性的词典
    ranking = defaultdict(int)
    for i, word in enumerate(word_sent):
        for w in word:
            if w in freq:
                ranking[i] += freq[w]
    sents_idx = rank(ranking, n)
    return [sents[j] for j in sents_idx]
    
"""
考虑到句子比较多的情况
用遍历的方式找最大的n个数比较慢
我们这里调用heapq中的函数
创建一个最小堆来完成这个功能
返回的是最小的n个数所在的位置
"""    
def rank(ranking, n):
    return nlargest(n, ranking, key=ranking.get)
```

###5. 运行程序

最后加入我们的__main__()
```python
if __name__ == '__main__':
    with open("news.txt", "r") as myfile:
        text = myfile.read().replace('\n','')
    res = summarize(text, 2)
    for i in range(len(res)):
        print(res[i])
```
这里我们提供了一个样本news.txt。可以在命令行中输入

```
wget http://labfile.oss.aliyuncs.com/courses/741/news.txt
```
来获取

## 三、文档格式

这里介绍实验文档中常见的几种Markdown样式

### 1. 标题

标题前使用`#`，例如下述代码块：

```
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
```

### 2. 列表

有序列表前使用数字`1. `，`2. `等，例如：

1. 我是第一个item
2. 我是第二个item
3. 我是第三个item


无序列表更简单，前面加`-`即可：

- 我是不知道第几个item
- 我是不知道第几个item
- 我是不知道第几个item


### 3. 代码

代码很简单，见下方：

```
我是代码，不太像？
```


### 4. 链接和图片

插入链接的样式为`[显示文本](链接地址)`，例如：

[我是一个超链接](http://www.shiyanlou.com)

实验文档编辑界面上方图片按钮，点击后即可插入图片并自动生成图片样式：

![](https://dn-simplecloud.qbox.me/gravatar6512bd43d9caa6e02c990b0a82652dca.png)



### 5. 引用

使用`>`表示后续文字为引用，例如

> 引用文字

### 6. 粗体和斜体

用两个 `*` 包含一段文本就是粗体的语法，用一个 `*` 包含一段文本就是斜体

**粗体文字**

*斜体文字*



### 7. 表格

表格代码如下，显示样式见右栏


| 表头1        | 表头2         | 表头3 |
| ------------ |:-------------:| -----:|
| 第一行       | 内容          | 内容  |
| 第二行       | 内容          | 内容  |
| 第三行       | 内容          | 内容  |

## 帮助

您如果对Markdown格式实验文档的编写仍然疑问可以发邮件给我们: [support@shiyanlou.com](mailto:support@shiyanlou)

我们会竭尽所能帮助您开发一门完美的在线实验课。

**实验楼感谢您对我们的信任与支持！**
