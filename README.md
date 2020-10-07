# repo2020-fall
該複習一下題目了，雜記，寫給自己看的。
有空打電動不如打leetcode，有時間就寫點，讓腦袋動一動。

# Tree
- 基本建立、刪除寫在#l-100裡
- 常用tests放在#d-1
- 下面兩對fucntions有什麼不一樣呢? 有的，其中一種方式會丟掉資料，這是常見的傳值和傳指標誤區，詳細說明和解答請參考這個連結：https://chenhh.gitbooks.io/parallel_processing/content/cython/memory_leak.html
```
  struct TreeNode*  newNode(int v)
  void newNode1(struct TreeNode* p, int v)
  struct TreeNode* newTree(int nums[], int numSize)
  void newTree1(struct TreeNode* p, int nums[], int numSize)
```

# Singly Linked List
基本建立、刪除寫在#l-2裡
